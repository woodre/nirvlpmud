inherit "players/pavlik/armor/armor";
#include "/players/pavlik/closed/colors.h"
#define tp this_player()
#define BONUS 5

string *stats;
int i;

reset(arg){
 ::reset(arg);
 set_short(
 "the "+HIR+"W"+HIG+"a"+HIY+"r"+HIB+"P"+HIM+"R"+HIC+"i"+
 HIW+"n"+HIR+"G"+NORM);
 set_arm_light(1);
 set_long(
 "The Warp Ring.  A bizarre piece of jewerly from another dimension.\n"+
 "It is glowing (as if you hadn't noticed).\n");
 set_ac(2);
 set_weight(1);
 set_value(6969);
 set_alias("ring");
 set_name("ring");
 set_type("ring");
 set_save_flag(1);
 stats = ({ "int","wis","wil","pow","conj","ench","evoc","illu","necr", });
 i = random(9);
}

query_guild_bonus(){ return BONUS; }

add_guild_bonus() {
  if(present("mageobj", tp)) {
    call_other(present("mageobj", tp), "add_"+stats[i]+"_bonus", BONUS);
  }
  return 1;
}

remove_guild_bonus() {
  if(present("mageobj", tp)) {
    call_other(present("mageobj", tp), "add_"+stats[i]+"_bonus", -BONUS);
  }
  return 1;
}

