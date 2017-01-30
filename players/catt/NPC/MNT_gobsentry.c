
inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object armour;
object armor;
object weapon;
::reset(arg);
if(arg) return;
set_name("goblin sentry");
set_alias("sentry");
set_short("husky goblin sentry");
set_long(
"a goblin sentry who looks at you closely.\n");
set_level(10);
set_race("goblin");
set_hp(200);
set_al(-500);
set_wc(2);
set_ac(2);
set_aggressive(1);
set_spell_mess2("");
set_random_pick(3);
   armour = clone_object(ARM+"goblinarmor");
if(armour) {
move_object(armour,this_object());
command("wear "+armour->query_name());
  }
   armor = clone_object(ARM+"jerkin");
if(armor) {
  move_object(armor, this_object());
command("wear "+armor->query_name());
    }
   weapon = clone_object(WPN+"goblinspear");
if(weapon) {
move_object(weapon,this_object());
command("wield "+weapon->query_name());
   }
}
