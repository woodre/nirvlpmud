
inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object money;
object armour;
object weapon;
::reset(arg);
if(arg) return;
set_name("goblin");
set_alias("goblin");
set_short("a dirty goblin");
set_long(
"a little dirty goblin\n");
set_level(5);
set_race("goblin");
set_hp(100);
set_al(-500);
set_wc(3);
set_ac(7);
set_aggressive(1);
set_spell_mess2("");
set_random_pick(10);
money = clone_object("obj/money");
money->set_money(50);
move_object(money, this_object());
   weapon = clone_object(WPN+"goblinaxe");
if(weapon) {
move_object(weapon,this_object());
command("wield "+weapon->query_name());
   }
}
