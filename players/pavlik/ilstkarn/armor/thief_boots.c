inherit "players/pavlik/armor/armor";
#define GUILD_ID "pavlik_guild_obj"
#define BONUS_TYPE "agility"
#define BONUS_AMOUNT 2

reset(arg){
 if(arg) return;
  ::reset(arg);
  set_short("Pair of Thief Boots");
  set_arm_light(0);
  set_long(
  "A soft leather pair of boots that would be sturdy and still comfortable\n"+
  "for the feet.\n");
  set_ac(1);
  set_weight(1);
  set_value(200);
  set_alias("thief boots");
  set_name("Thief boots");
  set_type("boots");
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
