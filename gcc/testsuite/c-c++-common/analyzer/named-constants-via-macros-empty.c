#include "analyzer-decls.h"

/* Various constants used by the fd state machine.  */

#define O_ACCMODE
#define O_RDONLY
#define O_WRONLY

void test_sm_fd_constants (void)
{
  __analyzer_dump_named_constant ("O_ACCMODE"); /* { dg-warning "named constant 'O_ACCMODE' has unknown value" } */
  __analyzer_dump_named_constant ("O_RDONLY"); /* { dg-warning "named constant 'O_RDONLY' has unknown value" } */
  __analyzer_dump_named_constant ("O_WRONLY"); /* { dg-warning "named constant 'O_WRONLY' has unknown value" } */
}
