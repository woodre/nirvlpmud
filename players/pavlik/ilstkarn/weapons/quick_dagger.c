#include "/players/pavlik/closed/colors.h"
inherit "players/pavlik/weapons/weapon.c";
#define IT capitalize(attacker->query_name())
#define ME capitalize(this_player()->query_name())
#define GUILD_ID "pavlik_guild_obj"
#define BONUS_TYPE "agility"
#define BONUS_AMOUNT 2

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("Dagger");
  set_alt_name("quickling dagger");
  set_short("a Quickling Dagger");
  set_long(
  "The quickling dagger is a small very light dagger.\n");
  set_type("dagger");
  set_class(12+random(3));
  set_weight(1);
  set_value(550);
  set_save_flag(1);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  return 2 + random(3);
}

query_guild_bonus() { return BONUS_AMOUNT; }

add_guild_bonus() {
  if(present(GUILD_ID, this_player()))
	present(GUILD_ID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}

remove_guild_bonus() {
  if(present(GUILD_ID, this_player()))
	present(GUILD_ID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
}
