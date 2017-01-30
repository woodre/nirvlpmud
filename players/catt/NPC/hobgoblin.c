
inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object armour;
object armour1;
object armour2;
object weapon;
::reset(arg);
if(arg) return;
set_name("large hobgoblin");
set_alias("hobgoblin");
set_short("a large hobgoblin");
set_long(
"a very large and mean looking hobgoblin\n");
set_level(10);
set_race("hobgoblin");
set_hp(200);
set_al(-700);
/* Changed wc from 5 to 20  -Snow */
set_wc(20);
set_ac(5);
set_aggressive(1);
set_chance(50);
set_spell_dam(5);
set_spell_mess1("YOU CAN NOT PASS!");
set_spell_mess2("YOU CAN NOT PASS HERE!!!!!!");
set_random_pick(5);
armour = clone_object(ARM+"gobhelmet");
if(armour) {
move_object(armour,this_object());
command("wear "+armour->query_name());
  }
armour1 = clone_object(ARM+"goblinarmor");
if(armour1) {
move_object(armour1,this_object());
command("wear "+armour1->query_name());
}
armour2 = clone_object(ARM+"jerkin");
if(armour2) {
move_object(armour2,this_object());
command("wear "+armour2->query_name());
}
weapon = clone_object(WPN+"goblinspear");
if(weapon) {
move_object(weapon,this_object());
command("wield "+weapon->query_name());
   }
}
