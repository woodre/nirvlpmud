#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
object heal;
object armour;
::reset(arg);
if(arg) return;
set_name("valvula");
set_short("Some valvula");
set_alias("valve");
set_long(
   "These are valvula of the heart. They make sure blood goes the right way."+BS);
set_level(20);
set_wc(30);
set_ac(17);
set_hp(500);
add_money(1200+random(900));  /* Fred */
armour = clone_object("/players/hippo/armour/shield");
if (armour) {
   move_object(armour,this_object());
}
heal = clone_object("/players/hippo/heals/blood");
if (heal) {
   move_object(heal,this_object());
}
}

#include "/players/mythos/amon/hb_ag.h"
