#include "../def.h"
id(str) { return str == "init"; }

get() { return 1; }
drop() { return 1; }

init()
{
  add_action("do_init","init");
}

do_init()
{
  ENV(TP)->init();
}
