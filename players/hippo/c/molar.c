#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
object armour;
object weapon;
::reset(arg);
if(arg) return;
set_name("molar");
set_short("an enormous molar");
set_long(
   "This is one of the molars. It looks very destructive,"+BS+
   "you'd better watch out. Don't get scrumbled by them."+BS);
set_level(19);
set_ac(14);
set_wc(28);
set_hp(500);
armour = clone_object("/players/hippo/armour/glazour_coat");
if (armour) {
   move_object(armour,this_object());
}
weapon = clone_object("/players/hippo/weapons/molar_sharf");
if (weapon) {
   move_object(weapon,this_object());
}
}
