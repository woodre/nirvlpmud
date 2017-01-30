#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  set_short(YEL+"Gopher"+NORM+" head, with a note attached");
  set_alias("head");
  set_long("Job done.\n"+
                   "\n"+
                   "           -Da Rabbit\n");
}
