#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
object heal;
object weapon;
::reset(arg);
if(arg) return;
set_name("acid");
set_short("An acid");
set_long("It is a very acidic acid that comes out of the stomach somewhere"+BS);
set_level(16);
set_wc(23);
set_ac(12);
set_hp(500);
set_al(-1000);
money = 90;
weapon = clone_object("/players/hippo/weapons/skinbite");
if (weapon) {
   move_object(weapon,this_object());
}
heal = clone_object("/players/hippo/heals/enzymes");
if (heal) {
   move_object(heal,this_object());
}
}
