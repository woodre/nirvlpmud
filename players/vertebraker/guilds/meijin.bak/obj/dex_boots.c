inherit "players/pavlik/armor/armor";
#include "/players/pavlik/closed/colors.h"
#define GUILD_ID "pavlik_guild_obj"
#define BONUS_TYPE "dexterity"
#define BONUS_AMOUNT 2

reset(arg){
  ::reset(arg);
  set_short(HIW+"Boots of "+HIB+"Dexterity"+NORM);
  set_arm_light(1);
  set_long(
	"This fabulous boots have been bestowed with magical powers that will\n"+
	"enhance the wearers dexterity.  The boots are made from soft leather and\n"+
	"appear to be well worn.  A small bronze buckle adorns the left boot.\n");
  set_ac(1);
  set_weight(1);
  set_value(5000);
  set_alias("boots");
  set_name(HIW+"Boots of "+HIB+"Dexterity");
  set_type("boots");
  set_save_flag(0);
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus() {
  if(present(GUILD_ID, this_player()))
	present(GUILD_ID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}

remove_guild_bonus() {
  if(present(GUILD_ID, this_player()))
	present(GUILD_ID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
}

