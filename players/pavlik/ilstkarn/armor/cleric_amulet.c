inherit "players/pavlik/armor/armor";
#define GUILD_ID "pavlik_guild_obj"
#define BONUS_TYPE "will"
#define BONUS_AMOUNT 2

reset(arg){
  if(arg) return;
  ::reset(arg);
  set_short("Amulet of Tukuoi");
  set_arm_light(0);
  set_long("An Amulet of Tukukoi\n");
  set_ac(1);
  set_weight(1);
  set_value(1200);
  set_alias("amulet");
  set_name("Amulet of Tukukoi");
  set_type("amulet");
}

init() {
  ::init();
  add_action("rub_amulet", "rub");
}

rub(str) {
  if(id(str)) {
	write("The amulet glows brightly with magic.\n");
	say(capitalize(this_player()->query_name())+" rubs the magical amulet.\n");
	set_arm_light(1);
	return 1;
  }
}

query_guild_bonus() { return BONUS_AMOUNT; }

add_guild_bonus() {
  if(present(GUILD_ID, this_player()))
        present(GUILD_ID, this_player())->add_wil_bonus(BONUS_AMOUNT);
}

remove_guild_bonus() {
  if(present(GUILD_ID, this_player()))
        present(GUILD_ID, this_player())->add_wil_bonus(-BONUS_AMOUNT);
}
