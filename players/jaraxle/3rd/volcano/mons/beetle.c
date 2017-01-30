#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
     ::reset(arg);
  if(arg) return;

call_out("bye_bye", 300);
set_name("beetle");
set_alias("beetle");
set_alt_name("beetle");
set_race("creature");
set_short("A beetle");
set_long(
   "A large black beetle.  It has green spots all over its hard shell.\nLarge pinchers reach out from its mouth.\n");

set_level(12);
set_hp(180+random(31));
set_al(-1000+random(1001));
set_wc(14);
set_ac(11);
set_aggressive(0);

set_dead_ob(this_object());



}

monster_died() {
object gold;
gold = clone_object("obj/money");
gold->set_money(400+random(200));
  tell_room(environment(this_object()),
      "The beetle shakes, as it falls lifeless to the ground.\nIt's shell cracks as coins fall from inside.\n");
 move_object(gold,environment());
return 0; }

