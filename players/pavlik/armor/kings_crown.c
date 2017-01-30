inherit "players/pavlik/armor/armor";
#include "/players/pavlik/closed/colors.h"
#define BONUS 2

reset(arg){
 ::reset(arg);
 set_short("the Crown of Arcydia");
 set_long(
 "This crown is one of the ruling symbols of Arcydia, the Mountain\n"+
 "Fortress.  The Crown and Sceptre of King Secezeran contain untold\n"+
 "powers which had helped the King rule justly for many years.\n");
 set_name("Crown of Arcydia");
 set_ac(1);
 set_weight(1);
 set_value(5000);
 set_alias("crown");
 set_arm_light(0);
 set_save_flag(1);
 set_type("helmet");
}

id(str) {
  return str == name || str == alias || str == type ||
  str == "kings_crown";
}

query_guild_bonus(){ return BONUS; }

add_guild_bonus() {
  if(present("mageobj", this_player())) {
    present("mageobj", this_player())->add_wis_bonus(BONUS);
    present("mageobj", this_player())->add_necr_bonus(-BONUS);
  }
  return 1;
}

remove_guild_bonus() {
  if(present("mageobj", this_player())) {
    present("mageobj", this_player())->add_wis_bonus(-BONUS);
    present("mageobj", this_player())->add_necr_bonus(BONUS);
  }
  return 1;
}

