#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  set_short(BOLD+"SCOREBOARD"+NORM);
  set_alias("scoreboard");
  set_long("Read it.\n");
  set_read("\n"+BOLD+
  "******************************************************************\n"+
  "*                                                                *\n"+
  "*        "+HIK+"Oakland"+NORM+BOLD+" Raiders"+NORM+":      17   (1/0)                         *\n"+
  "*        "+HIK+"Pittsburgh "+NORM+YEL+"Stealers"+NORM+":  7   (0/1)                         *\n"+
  "*                                                                *\n"+
  "*                                                                *\n"+
  "******************************************************************\n"+
  "\n\n"+NORM);
}
get() { return 0; }
