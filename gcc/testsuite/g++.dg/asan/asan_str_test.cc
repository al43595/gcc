//=-- asan_str_test.cc ----------------------------------------------------===//
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a part of AddressSanitizer, an address sanity checker.
//
//===----------------------------------------------------------------------===//
#include "asan_test_utils.h"

#if defined(__APPLE__)
#include <AvailabilityMacros.h>  // For MAC_OS_X_VERSION_*
#endif

// Used for string functions tests
static char global_string[] = "global";
static size_t global_string_length = 6;

// Input to a test is a zero-terminated string str with given length
// Accesses to the bytes to the left and after str
// are presumed to produce OOB errors
void StrLenOOBTestTemplate(char *str, size_t length, bool is_global) {
  // Normal strlen calls
  EXPECT_EQ(strlen(str), length);
  if (length > 0) {
    EXPECT_EQ(length - 1, strlen(str + 1));
    EXPECT_EQ(0U, strlen(str + length));
  }
  // Arg of strlen is not malloced, OOB access
  if (!is_global) {
    // We don't insert RedZones before global variables
    EXPECT_DEATH(Ident(strlen(str - 1)), LeftOOBReadMessage(1));
    EXPECT_DEATH(Ident(strlen(str - 5)), LeftOOBReadMessage(5));
  }
  EXPECT_DEATH(Ident(strlen(str + length + 1)), RightOOBReadMessage(0));
  // Overwrite terminator
  str[length] = 'a';
  // String is not zero-terminated, strlen will lead to OOB access
  EXPECT_DEATH(Ident(strlen(str)), RightOOBReadMessage(0));
  EXPECT_DEATH(Ident(strlen(str + length)), RightOOBReadMessage(0));
  // Restore terminator
  str[length] = 0;
}
TEST(AddressSanitizer, StrLenOOBTest) {
  // Check heap-allocated string
  size_t length = Ident(10);
  char *heap_string = Ident((char*)malloc(length + 1));
  char stack_string[10 + 1];
  break_optimization(&stack_string);
  for (size_t i = 0; i < length; i++) {
    heap_string[i] = 'a';
    stack_string[i] = 'b';
  }
  heap_string[length] = 0;
  stack_string[length] = 0;
  StrLenOOBTestTemplate(heap_string, length, false);
  // TODO(samsonov): Fix expected messages in StrLenOOBTestTemplate to
  //      make test for stack_string work. Or move it to output tests.
  // StrLenOOBTestTemplate(stack_string, length, false);
  StrLenOOBTestTemplate(global_string, global_string_length, true);
  free(heap_string);
}

TEST(AddressSanitizer, WcsLenTest) {
  EXPECT_EQ(0U, wcslen(Ident(L"")));
  size_t hello_len = 13;
  size_t hello_size = (hello_len + 1) * sizeof(wchar_t);
  EXPECT_EQ(hello_len, wcslen(Ident(L"Hello, World!")));
  wchar_t *heap_string = Ident((wchar_t*)malloc(hello_size));
  memcpy(heap_string, L"Hello, World!", hello_size);
  EXPECT_EQ(hello_len, Ident(wcslen(heap_string)));
  EXPECT_DEATH(Ident(wcslen(heap_string + 14)), RightOOBReadMessage(0));
  free(heap_string);
}

#if SANITIZER_TEST_HAS_STRNLEN
TEST(AddressSanitizer, StrNLenOOBTest) {
  size_t size = Ident(123);
  char *str = MallocAndMemsetString(size);
  // Normal strnlen calls.
  Ident(strnlen(str - 1, 0));
  Ident(strnlen(str, size));
  Ident(strnlen(str + size - 1, 1));
  str[size - 1] = '\0';
  Ident(strnlen(str, 2 * size));
  // Argument points to not allocated memory.
  EXPECT_DEATH(Ident(strnlen(str - 1, 1)), LeftOOBReadMessage(1));
  EXPECT_DEATH(Ident(strnlen(str + size, 1)), RightOOBReadMessage(0));
  // Overwrite the terminating '\0' and hit unallocated memory.
  str[size - 1] = 'z';
  EXPECT_DEATH(Ident(strnlen(str, size + 1)), RightOOBReadMessage(0));
  free(str);
}
#endif  // SANITIZER_TEST_HAS_STRNLEN

TEST(AddressSanitizer, StrDupOOBTest) {
  size_t size = Ident(42);
  char *str = MallocAndMemsetString(size);
  char *new_str;
  // Normal strdup calls.
  str[size - 1] = '\0';
  new_str = strdup(str);
  free(new_str);
  new_str = strdup(str + size - 1);
  free(new_str);
  // Argument points to not allocated memory.
  EXPECT_DEATH(Ident(strdup(str - 1)), LeftOOBReadMessage(1));
  EXPECT_DEATH(Ident(strdup(str + size)), RightOOBReadMessage(0));
  // Overwrite the terminating '\0' and hit unallocated memory.
  str[size - 1] = 'z';
  EXPECT_DEATH(Ident(strdup(str)), RightOOBReadMessage(0));
  free(str);
}

TEST(AddressSanitizer, StrCpyOOBTest) {
  size_t to_size = Ident(30);
  size_t from_size = Ident(6);  // less than to_size
  char *to = Ident((char*)malloc(to_size));
  char *from = Ident((char*)malloc(from_size));
  // Normal strcpy calls.
  strcpy(from, "hello");
  strcpy(to, from);
  strcpy(to + to_size - from_size, from);
  // Length of "from" is too small.
  EXPECT_DEATH(Ident(strcpy(from, "hello2")), RightOOBWriteMessage(0));
  // "to" or "from" points to not allocated memory.
  EXPECT_DEATH(Ident(strcpy(to - 1, from)), LeftOOBWriteMessage(1));
  EXPECT_DEATH(Ident(strcpy(to, from - 1)), LeftOOBReadMessage(1));
  EXPECT_DEATH(Ident(strcpy(to, from + from_size)), RightOOBReadMessage(0));
  EXPECT_DEATH(Ident(strcpy(to + to_size, from)), RightOOBWriteMessage(0));
  // Overwrite the terminating '\0' character and hit unallocated memory.
  from[from_size - 1] = '!';
  EXPECT_DEATH(Ident(strcpy(to, from)), RightOOBReadMessage(0));
  free(to);
  free(from);
}

TEST(AddressSanitizer, StrNCpyOOBTest) {
  size_t to_size = Ident(20);
  size_t from_size = Ident(6);  // less than to_size
  char *to = Ident((char*)malloc(to_size));
  // From is a zero-terminated string "hello\0" of length 6
  char *from = Ident((char*)malloc(from_size));
  strcpy(from, "hello");
  // copy 0 bytes
  strncpy(to, from, 0);
  strncpy(to - 1, from - 1, 0);
  // normal strncpy calls
  strncpy(to, from, from_size);
  strncpy(to, from, to_size);
  strncpy(to, from + from_size - 1, to_size);
  strncpy(to + to_size - 1, from, 1);
  // One of {to, from} points to not allocated memory
  EXPECT_DEATH(Ident(strncpy(to, from - 1, from_size)),
               LeftOOBReadMessage(1));
  EXPECT_DEATH(Ident(strncpy(to - 1, from, from_size)),
               LeftOOBWriteMessage(1));
  EXPECT_DEATH(Ident(strncpy(to, from + from_size, 1)),
               RightOOBReadMessage(0));
  EXPECT_DEATH(Ident(strncpy(to + to_size, from, 1)),
               RightOOBWriteMessage(0));
  // Length of "to" is too small
  EXPECT_DEATH(Ident(strncpy(to + to_size - from_size + 1, from, from_size)),
               RightOOBWriteMessage(0));
  EXPECT_DEATH(Ident(strncpy(to + 1, from, to_size)),
               RightOOBWriteMessage(0));
  // Overwrite terminator in from
  from[from_size - 1] = '!';
  // normal strncpy call
  strncpy(to, from, from_size);
  // Length of "from" is too small
  EXPECT_DEATH(Ident(strncpy(to, from, to_size)),
               RightOOBReadMessage(0));
  free(to);
  free(from);
}

// Users may have different definitions of "strchr" and "index", so provide
// function pointer typedefs and overload RunStrChrTest implementation.
// We can't use macro for RunStrChrTest body here, as this macro would
// confuse EXPECT_DEATH gtest macro.
typedef char*(*PointerToStrChr1)(const char*, int);
typedef char*(*PointerToStrChr2)(char*, int);

UNUSED static void RunStrChrTest(PointerToStrChr1 StrChr) {
  size_t size = Ident(100);
  char *str = MallocAndMemsetString(size);
  str[10] = 'q';
  str[11] = '\0';
  EXPECT_EQ(str, StrChr(str, 'z'));
  EXPECT_EQ(str + 10, StrChr(str, 'q'));
  EXPECT_EQ(NULL, StrChr(str, 'a'));
  // StrChr argument points to not allocated memory.
  EXPECT_DEATH(Ident(StrChr(str - 1, 'z')), LeftOOBReadMessage(1));
  EXPECT_DEATH(Ident(StrChr(str + size, 'z')), RightOOBReadMessage(0));
  // Overwrite the terminator and hit not allocated memory.
  str[11] = 'z';
  EXPECT_DEATH(Ident(StrChr(str, 'a')), RightOOBReadMessage(0));
  free(str);
}
UNUSED static void RunStrChrTest(PointerToStrChr2 StrChr) {
  size_t size = Ident(100);
  char *str = MallocAndMemsetString(size);
  str[10] = 'q';
  str[11] = '\0';
  EXPECT_EQ(str, StrChr(str, 'z'));
  EXPECT_EQ(str + 10, StrChr(str, 'q'));
  EXPECT_EQ(NULL, StrChr(str, 'a'));
  // StrChr argument points to not allocated memory.
  EXPECT_DEATH(Ident(StrChr(str - 1, 'z')), LeftOOBReadMessage(1));
  EXPECT_DEATH(Ident(StrChr(str + size, 'z')), RightOOBReadMessage(0));
  // Overwrite the terminator and hit not allocated memory.
  str[11] = 'z';
  EXPECT_DEATH(Ident(StrChr(str, 'a')), RightOOBReadMessage(0));
  free(str);
}

TEST(AddressSanitizer, StrChrAndIndexOOBTest) {
  RunStrChrTest(&strchr);
#if !defined(_WIN32)  // no index() on Windows.
  RunStrChrTest(&index);
#endif
}

TEST(AddressSanitizer, StrCmpAndFriendsLogicTest) {
  // strcmp
  EXPECT_EQ(0, strcmp("", ""));
  EXPECT_EQ(0, strcmp("abcd", "abcd"));
  EXPECT_GT(0, strcmp("ab", "ac"));
  EXPECT_GT(0, strcmp("abc", "abcd"));
  EXPECT_LT(0, strcmp("acc", "abc"));
  EXPECT_LT(0, strcmp("abcd", "abc"));

  // strncmp
  EXPECT_EQ(0, strncmp("a", "b", 0));
  EXPECT_EQ(0, strncmp("abcd", "abcd", 10));
  EXPECT_EQ(0, strncmp("abcd", "abcef", 3));
  EXPECT_GT(0, strncmp("abcde", "abcfa", 4));
  EXPECT_GT(0, strncmp("a", "b", 5));
  EXPECT_GT(0, strncmp("bc", "bcde", 4));
  EXPECT_LT(0, strncmp("xyz", "xyy", 10));
  EXPECT_LT(0, strncmp("baa", "aaa", 1));
  EXPECT_LT(0, strncmp("zyx", "", 2));

#if !defined(_WIN32)  // no str[n]casecmp on Windows.
  // strcasecmp
  EXPECT_EQ(0, strcasecmp("", ""));
  EXPECT_EQ(0, strcasecmp("zzz", "zzz"));
  EXPECT_EQ(0, strcasecmp("abCD", "ABcd"));
  EXPECT_GT(0, strcasecmp("aB", "Ac"));
  EXPECT_GT(0, strcasecmp("ABC", "ABCd"));
  EXPECT_LT(0, strcasecmp("acc", "abc"));
  EXPECT_LT(0, strcasecmp("ABCd", "abc"));

  // strncasecmp
  EXPECT_EQ(0, strncasecmp("a", "b", 0));
  EXPECT_EQ(0, strncasecmp("abCD", "ABcd", 10));
  EXPECT_EQ(0, strncasecmp("abCd", "ABcef", 3));
  EXPECT_GT(0, strncasecmp("abcde", "ABCfa", 4));
  EXPECT_GT(0, strncasecmp("a", "B", 5));
  EXPECT_GT(0, strncasecmp("bc", "BCde", 4));
  EXPECT_LT(0, strncasecmp("xyz", "xyy", 10));
  EXPECT_LT(0, strncasecmp("Baa", "aaa", 1));
  EXPECT_LT(0, strncasecmp("zyx", "", 2));
#endif

  // memcmp
  EXPECT_EQ(0, memcmp("a", "b", 0));
  EXPECT_EQ(0, memcmp("ab\0c", "ab\0c", 4));
  EXPECT_GT(0, memcmp("\0ab", "\0ac", 3));
  EXPECT_GT(0, memcmp("abb\0", "abba", 4));
  EXPECT_LT(0, memcmp("ab\0cd", "ab\0c\0", 5));
  EXPECT_LT(0, memcmp("zza", "zyx", 3));
}

typedef int(*PointerToStrCmp)(const char*, const char*);
void RunStrCmpTest(PointerToStrCmp StrCmp) {
  size_t size = Ident(100);
  int fill = 'o';
  char *s1 = MallocAndMemsetString(size, fill);
  char *s2 = MallocAndMemsetString(size, fill);
  s1[size - 1] = '\0';
  s2[size - 1] = '\0';
  // Normal StrCmp calls
  Ident(StrCmp(s1, s2));
  Ident(StrCmp(s1, s2 + size - 1));
  Ident(StrCmp(s1 + size - 1, s2 + size - 1));
  s1[size - 1] = 'z';
  s2[size - 1] = 'x';
  Ident(StrCmp(s1, s2));
  // One of arguments points to not allocated memory.
  EXPECT_DEATH(Ident(StrCmp)(s1 - 1, s2), LeftOOBReadMessage(1));
  EXPECT_DEATH(Ident(StrCmp)(s1, s2 - 1), LeftOOBReadMessage(1));
  EXPECT_DEATH(Ident(StrCmp)(s1 + size, s2), RightOOBReadMessage(0));
  EXPECT_DEATH(Ident(StrCmp)(s1, s2 + size), RightOOBReadMessage(0));
  // Hit unallocated memory and die.
  s1[size - 1] = fill;
  EXPECT_DEATH(Ident(StrCmp)(s1, s1), RightOOBReadMessage(0));
  EXPECT_DEATH(Ident(StrCmp)(s1 + size - 1, s2), RightOOBReadMessage(0));
  free(s1);
  free(s2);
}

TEST(AddressSanitizer, StrCmpOOBTest) {
  RunStrCmpTest(&strcmp);
}

#if !defined(_WIN32)  // no str[n]casecmp on Windows.
TEST(AddressSanitizer, StrCaseCmpOOBTest) {
  RunStrCmpTest(&strcasecmp);
}
#endif

typedef int(*PointerToStrNCmp)(const char*, const char*, size_t);
void RunStrNCmpTest(PointerToStrNCmp StrNCmp) {
  size_t size = Ident(100);
  char *s1 = MallocAndMemsetString(size);
  char *s2 = MallocAndMemsetString(size);
  s1[size - 1] = '\0';
  s2[size - 1] = '\0';
  // Normal StrNCmp calls
  Ident(StrNCmp(s1, s2, size + 2));
  s1[size - 1] = 'z';
  s2[size - 1] = 'x';
  Ident(StrNCmp(s1 + size - 2, s2 + size - 2, size));
  s2[size - 1] = 'z';
  Ident(StrNCmp(s1 - 1, s2 - 1, 0));
  Ident(StrNCmp(s1 + size - 1, s2 + size - 1, 1));
  // One of arguments points to not allocated memory.
  EXPECT_DEATH(Ident(StrNCmp)(s1 - 1, s2, 1), LeftOOBReadMessage(1));
  EXPECT_DEATH(Ident(StrNCmp)(s1, s2 - 1, 1), LeftOOBReadMessage(1));
  EXPECT_DEATH(Ident(StrNCmp)(s1 + size, s2, 1), RightOOBReadMessage(0));
  EXPECT_DEATH(Ident(StrNCmp)(s1, s2 + size, 1), RightOOBReadMessage(0));
  // Hit unallocated memory and die.
  EXPECT_DEATH(Ident(StrNCmp)(s1 + 1, s2 + 1, size), RightOOBReadMessage(0));
  EXPECT_DEATH(Ident(StrNCmp)(s1 + size - 1, s2, 2), RightOOBReadMessage(0));
  free(s1);
  free(s2);
}

TEST(AddressSanitizer, StrNCmpOOBTest) {
  RunStrNCmpTest(&strncmp);
}

#if !defined(_WIN32)  // no str[n]casecmp on Windows.
TEST(AddressSanitizer, StrNCaseCmpOOBTest) {
  RunStrNCmpTest(&strncasecmp);
}
#endif

TEST(AddressSanitizer, StrCatOOBTest) {
  // strcat() reads strlen(to) bytes from |to| before concatenating.
  size_t to_size = Ident(100);
  char *to = MallocAndMemsetString(to_size);
  to[0] = '\0';
  size_t from_size = Ident(20);
  char *from = MallocAndMemsetString(from_size);
  from[from_size - 1] = '\0';
  // Normal strcat calls.
  strcat(to, from);
  strcat(to, from);
  strcat(to + from_size, from + from_size - 2);
  // Passing an invalid pointer is an error even when concatenating an empty
  // string.
  EXPECT_DEATH(strcat(to - 1, from + from_size - 1), LeftOOBAccessMessage(1));
  // One of arguments points to not allocated memory.
  EXPECT_DEATH(strcat(to - 1, from), LeftOOBAccessMessage(1));
  EXPECT_DEATH(strcat(to, from - 1), LeftOOBReadMessage(1));
  EXPECT_DEATH(strcat(to + to_size, from), RightOOBWriteMessage(0));
  EXPECT_DEATH(strcat(to, from + from_size), RightOOBReadMessage(0));

  // "from" is not zero-terminated.
  from[from_size - 1] = 'z';
  EXPECT_DEATH(strcat(to, from), RightOOBReadMessage(0));
  from[from_size - 1] = '\0';
  // "to" is not zero-terminated.
  memset(to, 'z', to_size);
  EXPECT_DEATH(strcat(to, from), RightOOBWriteMessage(0));
  // "to" is too short to fit "from".
  to[to_size - from_size + 1] = '\0';
  EXPECT_DEATH(strcat(to, from), RightOOBWriteMessage(0));
  // length of "to" is just enough.
  strcat(to, from + 1);

  free(to);
  free(from);
}

TEST(AddressSanitizer, StrNCatOOBTest) {
  // strncat() reads strlen(to) bytes from |to| before concatenating.
  size_t to_size = Ident(100);
  char *to = MallocAndMemsetString(to_size);
  to[0] = '\0';
  size_t from_size = Ident(20);
  char *from = MallocAndMemsetString(from_size);
  // Normal strncat calls.
  strncat(to, from, 0);
  strncat(to, from, from_size);
  from[from_size - 1] = '\0';
  strncat(to, from, 2 * from_size);
  // Catenating empty string with an invalid string is still an error.
  EXPECT_DEATH(strncat(to - 1, from, 0), LeftOOBAccessMessage(1));
  strncat(to, from + from_size - 1, 10);
  // One of arguments points to not allocated memory.
  EXPECT_DEATH(strncat(to - 1, from, 2), LeftOOBAccessMessage(1));
  EXPECT_DEATH(strncat(to, from - 1, 2), LeftOOBReadMessage(1));
  EXPECT_DEATH(strncat(to + to_size, from, 2), RightOOBWriteMessage(0));
  EXPECT_DEATH(strncat(to, from + from_size, 2), RightOOBReadMessage(0));

  memset(from, 'z', from_size);
  memset(to, 'z', to_size);
  to[0] = '\0';
  // "from" is too short.
  EXPECT_DEATH(strncat(to, from, from_size + 1), RightOOBReadMessage(0));
  // "to" is not zero-terminated.
  EXPECT_DEATH(strncat(to + 1, from, 1), RightOOBWriteMessage(0));
  // "to" is too short to fit "from".
  to[0] = 'z';
  to[to_size - from_size + 1] = '\0';
  EXPECT_DEATH(strncat(to, from, from_size - 1), RightOOBWriteMessage(0));
  // "to" is just enough.
  strncat(to, from, from_size - 2);

  free(to);
  free(from);
}

static string OverlapErrorMessage(const string &func) {
  return func + "-param-overlap";
}

TEST(AddressSanitizer, StrArgsOverlapTest) {
  size_t size = Ident(100);
  char *str = Ident((char*)malloc(size));

// Do not check memcpy() on OS X 10.7 and later, where it actually aliases
// memmove().
#if !defined(__APPLE__) || !defined(MAC_OS_X_VERSION_10_7) || \
    (MAC_OS_X_VERSION_MAX_ALLOWED < MAC_OS_X_VERSION_10_7)
  // Check "memcpy". Use Ident() to avoid inlining.
  memset(str, 'z', size);
  Ident(memcpy)(str + 1, str + 11, 10);
  Ident(memcpy)(str, str, 0);
  EXPECT_DEATH(Ident(memcpy)(str, str + 14, 15), OverlapErrorMessage("memcpy"));
  EXPECT_DEATH(Ident(memcpy)(str + 14, str, 15), OverlapErrorMessage("memcpy"));
#endif

  // We do not treat memcpy with to==from as a bug.
  // See http://llvm.org/bugs/show_bug.cgi?id=11763.
  // EXPECT_DEATH(Ident(memcpy)(str + 20, str + 20, 1),
  //              OverlapErrorMessage("memcpy"));

  // Check "strcpy".
  memset(str, 'z', size);
  str[9] = '\0';
  strcpy(str + 10, str);
  EXPECT_DEATH(strcpy(str + 9, str), OverlapErrorMessage("strcpy"));
  EXPECT_DEATH(strcpy(str, str + 4), OverlapErrorMessage("strcpy"));
  strcpy(str, str + 5);

  // Check "strncpy".
  memset(str, 'z', size);
  strncpy(str, str + 10, 10);
  EXPECT_DEATH(strncpy(str, str + 9, 10), OverlapErrorMessage("strncpy"));
  EXPECT_DEATH(strncpy(str + 9, str, 10), OverlapErrorMessage("strncpy"));
  str[10] = '\0';
  strncpy(str + 11, str, 20);
  EXPECT_DEATH(strncpy(str + 10, str, 20), OverlapErrorMessage("strncpy"));

  // Check "strcat".
  memset(str, 'z', size);
  str[10] = '\0';
  str[20] = '\0';
  strcat(str, str + 10);
  EXPECT_DEATH(strcat(str, str + 11), OverlapErrorMessage("strcat"));
  str[10] = '\0';
  strcat(str + 11, str);
  EXPECT_DEATH(strcat(str, str + 9), OverlapErrorMessage("strcat"));
  EXPECT_DEATH(strcat(str + 9, str), OverlapErrorMessage("strcat"));
  EXPECT_DEATH(strcat(str + 10, str), OverlapErrorMessage("strcat"));

  // Check "strncat".
  memset(str, 'z', size);
  str[10] = '\0';
  strncat(str, str + 10, 10);  // from is empty
  EXPECT_DEATH(strncat(str, str + 11, 10), OverlapErrorMessage("strncat"));
  str[10] = '\0';
  str[20] = '\0';
  strncat(str + 5, str, 5);
  str[10] = '\0';
  EXPECT_DEATH(strncat(str + 5, str, 6), OverlapErrorMessage("strncat"));
  EXPECT_DEATH(strncat(str, str + 9, 10), OverlapErrorMessage("strncat"));

  free(str);
}

void CallAtoi(const char *nptr) {
  Ident(atoi(nptr));
}
void CallAtol(const char *nptr) {
  Ident(atol(nptr));
}
void CallAtoll(const char *nptr) {
  Ident(atoll(nptr));
}
typedef void(*PointerToCallAtoi)(const char*);

void RunAtoiOOBTest(PointerToCallAtoi Atoi) {
  char *array = MallocAndMemsetString(10, '1');
  // Invalid pointer to the string.
  EXPECT_DEATH(Atoi(array + 11), RightOOBReadMessage(1));
  EXPECT_DEATH(Atoi(array - 1), LeftOOBReadMessage(1));
  // Die if a buffer doesn't have terminating NULL.
  EXPECT_DEATH(Atoi(array), RightOOBReadMessage(0));
  // Make last symbol a terminating NULL or other non-digit.
  array[9] = '\0';
  Atoi(array);
  array[9] = 'a';
  Atoi(array);
  Atoi(array + 9);
  // Sometimes we need to detect overflow if no digits are found.
  memset(array, ' ', 10);
  EXPECT_DEATH(Atoi(array), RightOOBReadMessage(0));
  array[9] = '-';
  EXPECT_DEATH(Atoi(array), RightOOBReadMessage(0));
  EXPECT_DEATH(Atoi(array + 9), RightOOBReadMessage(0));
  array[8] = '-';
  Atoi(array);
  free(array);
}

#if !defined(_WIN32)  // FIXME: Fix and enable on Windows.
TEST(AddressSanitizer, AtoiAndFriendsOOBTest) {
  RunAtoiOOBTest(&CallAtoi);
  RunAtoiOOBTest(&CallAtol);
  RunAtoiOOBTest(&CallAtoll);
}
#endif

void CallStrtol(const char *nptr, char **endptr, int base) {
  Ident(strtol(nptr, endptr, base));
}
void CallStrtoll(const char *nptr, char **endptr, int base) {
  Ident(strtoll(nptr, endptr, base));
}
typedef void(*PointerToCallStrtol)(const char*, char**, int);

void RunStrtolOOBTest(PointerToCallStrtol Strtol) {
  char *array = MallocAndMemsetString(3);
  char *endptr = NULL;
  array[0] = '1';
  array[1] = '2';
  array[2] = '3';
  // Invalid pointer to the string.
  EXPECT_DEATH(Strtol(array + 3, NULL, 0), RightOOBReadMessage(0));
  EXPECT_DEATH(Strtol(array - 1, NULL, 0), LeftOOBReadMessage(1));
  // Buffer overflow if there is no terminating null (depends on base).
  Strtol(array, &endptr, 3);
  EXPECT_EQ(array + 2, endptr);
  EXPECT_DEATH(Strtol(array, NULL, 0), RightOOBReadMessage(0));
  array[2] = 'z';
  Strtol(array, &endptr, 35);
  EXPECT_EQ(array + 2, endptr);
  EXPECT_DEATH(Strtol(array, NULL, 36), RightOOBReadMessage(0));
  // Add terminating zero to get rid of overflow.
  array[2] = '\0';
  Strtol(array, NULL, 36);
  // Don't check for overflow if base is invalid.
  Strtol(array - 1, NULL, -1);
  Strtol(array + 3, NULL, 1);
  // Sometimes we need to detect overflow if no digits are found.
  array[0] = array[1] = array[2] = ' ';
  EXPECT_DEATH(Strtol(array, NULL, 0), RightOOBReadMessage(0));
  array[2] = '+';
  EXPECT_DEATH(Strtol(array, NULL, 0), RightOOBReadMessage(0));
  array[2] = '-';
  EXPECT_DEATH(Strtol(array, NULL, 0), RightOOBReadMessage(0));
  array[1] = '+';
  Strtol(array, NULL, 0);
  array[1] = array[2] = 'z';
  Strtol(array, &endptr, 0);
  EXPECT_EQ(array, endptr);
  Strtol(array + 2, NULL, 0);
  EXPECT_EQ(array, endptr);
  free(array);
}

#if !defined(_WIN32)  // FIXME: Fix and enable on Windows.
TEST(AddressSanitizer, StrtollOOBTest) {
  RunStrtolOOBTest(&CallStrtoll);
}
TEST(AddressSanitizer, StrtolOOBTest) {
  RunStrtolOOBTest(&CallStrtol);
}
#endif


