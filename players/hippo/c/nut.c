#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
object armour;
::reset(arg);
if(arg) return;
set_name("nut");
set_short("a little nut");
set_long(
   "This is a little nut, Hippo must have eaten in the last few hours."+BS);
set_level(10);
set_ac(11);
set_wc(11);
money = 250;
set_hp(150);
armour = clone_object("/players/hippo/armour/helmet.c");
if (armour) {
   move_object(armour,this_object());
}
  }
