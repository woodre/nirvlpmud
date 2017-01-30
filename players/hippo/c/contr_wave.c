#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
object heal;
object armour;
::reset(arg);
if(arg) return;
set_name("contraction wave");
set_short("a very strong contraction wave");
set_alias("wave");
set_long(
   "You see a very strong contraction wave. If it reaches you,"+BS+
    "I will not give a coin for your life!!"+BS);
set_level(20);
set_wc(30);
set_ac(17);
/* Now aggressive 50% from non-aggressive  -Snow */
set_aggressive(random(2));
set_hp(500);
add_money(1200+random(900));  /* Fred */
armour = clone_object("/players/hippo/armour/endotheel");
if (armour) {
   move_object(armour,this_object());
}
heal = clone_object("/players/hippo/heals/blood");
if (heal) {
   move_object(heal,this_object());
}
}

#include "/players/mythos/amon/hb_ag.h"

