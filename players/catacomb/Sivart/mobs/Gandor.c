#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("gandor");
set_race("durkor");
set_short("Gandor, the"+BLK+" Black"+NORM);
set_long(
  "  A scrawny looking durkor but behind his cold, ruthless eyes\n"+
  "is a raging inner fire.  Gandor was the high archmage of the \n"+
  "House Werjor until the spark of magic dimmed within him.  Now\n"+
  "he sells his magical heals to those in need.  Type '"+WHT+"list"+NORM+"'\n"+
  "to see Gandor's heals.\n");
 
set_level(17);
set_hp(350);
set_al(0);
set_dead_ob(this_object());
set_aggressive(0);
add_money(100);
set_wc(24);
set_ac(14);

}
  