#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  set_short("A paper note");
  set_alias("note");
  set_long(
"Away be back soon\n"+
"\n"+
"           -Otto\n");
}
get() { return 0; }

