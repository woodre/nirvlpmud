inherit "players/pavlik/armor/armor";
#include "/players/pavlik/closed/colors.h"
#define BONUS 1

reset(arg){
 ::reset(arg);
 set_short("the "+GRN+"Astendale"+NORM+" Cape");
 set_long(
 "This magnificent cape was a gift to King Secezeran by the people of\n"+
 "Astendale.  The forest green cape is lined with the colorful, soft\n"+
 "fur of an Astendale Stag.\n");
 set_name("Astendale Cape");
 set_ac(2);
 set_weight(1);
 set_value(1700);
 set_alias("cape");
 set_arm_light(0);
 set_save_flag(1);
 set_type("misc");
}

query_guild_bonus(){ return BONUS; }

add_guild_bonus() {
  if(present("mageobj", this_player())) {
    present("mageobj", this_player())->add_ench_bonus(BONUS);
  }
 return 1;
}

remove_guild_bonus() {
  if(present("mageobj", this_player())) {
    present("mageobj", this_player())->add_ench_bonus(-BONUS);
  }
  return 1;
}

