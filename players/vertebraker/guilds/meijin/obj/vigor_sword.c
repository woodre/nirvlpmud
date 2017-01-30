#include "/players/pavlik/closed/colors.h"
inherit "players/pavlik/weapons/weapon.c";

#define IT capitalize(attacker->query_name())
#define ME capitalize(this_player()->query_name())
#define GUILD_ID "pavlik_guild_obj"
#define BONUS_TYPE "endurance"
#define BONUS_TYPE_2 "constitution"
#define BONUS_AMOUNT 2
#define BONUS_AMOUNT_2 1

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("the Sword of "+HIY+"Vigor"+NORM);
  set_alt_name("sword of vigor");
  set_short("the Sword of "+HIY+"Vigor"+NORM);
  set_long(
	"This is a finely balanced blade with special magical properties.  The\n"+
	"sword of Vigor is known to empower its wielder with amazing stamina and\n"+
	"endurance.\n");
  set_type("sword");
  set_class(16+random(3));
  set_weight(2);
  set_value(10000);
  set_save_flag(1);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if(present(GUILD_ID, this_player())) {
	if(17 > random(50)) {
		write("You feel full of energy and vigor!\n");
		present(GUILD_ID, this_player())->add_endurance(random(15));
		return;
	}
  }
  if(call_other(this_player(), "query_attrib", "stamina") > random(50)) {
	write("The Sword of "+HIY+"Vigor"+NORM+" cuts effortlessly through your foe!\n");
	say(ME+"'s sword cuts effortlessly through "+this_player()->query_possessive()+" foe!\n");
	return 7;
  }
}

query_guild_bonus() { return BONUS_AMOUNT; }

add_guild_bonus() {
  if(present(GUILD_ID, this_player())) {
	present(GUILD_ID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
	present(GUILD_ID, this_player())->add_guild_bonus(BONUS_TYPE_2, BONUS_AMOUNT_2);
  }
}

remove_guild_bonus() {
  if(present(GUILD_ID, this_player())) {
	present(GUILD_ID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
	present(GUILD_ID, this_player())->add_guild_bonus(BONUS_TYPE_2, -BONUS_AMOUNT_2);
  }
}
