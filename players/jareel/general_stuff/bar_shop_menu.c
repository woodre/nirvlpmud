#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  set_short("A wooden menu");
  set_alias("menu");
set_long("The list of food is a little disturbing for the weak of heart, maybe you could read it.\n");
set_read(BOLD+"The menu reads:"+NORM+"\n"+
  "     Jungle juice          :  60 coins\n"+
  "     Faerie legs           :  50 coins\n"+
  "     Dwarf haunch          :  300 coins\n"+
  "     Beer                  :  480 coins\n"+
  "     Everclear             :  500 coins\n");
  return 1;
}
get() { return 0; }
