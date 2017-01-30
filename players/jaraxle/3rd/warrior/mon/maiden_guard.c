#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("Warrior Maiden");
set_alias("maiden");
set_alt_name("warrior");
set_race("human");
set_short("Warrior Maiden");
set_long(
  "This Warrior Maiden looks well prepared for battle. She has tribal tattoos around\n"+
  "her arms. Her hair is long and tied back in a ponytail.\n");

set_level(15);
set_hp(275+random(25));
set_al(0);
set_ac(16);
set_aggressive(0);
MOCO("/players/jaraxle/3rd/warrior/weaps/bow.c"),this_object());
MOCO("obj/soul"),this_object());
init_command("wield bow");
set_wc(25);
set_dead_ob(this_object());

set_chat_chance(3);
  load_chat("The Warrior Maiden looks around cautiously.\n");
set_a_chat_chance(15);
  load_a_chat("The Warrior Maiden shoots an arrow into you!\n");

gold = clone_object("obj/money");
gold->set_money(900+random(100));
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
        "The Warrior Maiden falls lifeless to the ground.\n");
return 0; }

