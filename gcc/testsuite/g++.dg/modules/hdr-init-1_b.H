// { dg-additional-options -fmodule-header }
// { dg-module-cmi {} }

int bob ();

static int var = bob ();
