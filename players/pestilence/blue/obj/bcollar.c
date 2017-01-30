#include "/players/pestilence/ansi.h"
inherit "/obj/armor";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("collar");
  set_alias("blue's collar");
  set_type("amulet");
  set_short(""+CYN+"Blue's Collar"+NORM+"");
set_long(
"This is the collar worn by Blue from Blue's Clues.  This collar doesn't\n"+
"seem to have any protection value, but maybe you could sell it.\n");
  set_value(300);
  set_weight(1);
  set_ac(0);
}
