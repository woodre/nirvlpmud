inherit "players/pavlik/armor/armor";
#include "/players/pavlik/closed/colors.h"
#define BONUS 1

reset(arg){
   ::reset(arg);
  set_short(
  "the "+HIR+"W"+HIG+"a"+HIY+"r"+HIB+"P"+HIM+"R"+HIC+"i"+
  HIW+"n"+HIR+"G"+NORM);
   set_arm_light(1);
  set_long(
  "The Warp Ring.  A bizarre piece of jewerly from the Boogey Dimension.\n"+
  "It is glowing (as if you hadn't noticed).\n");
   set_ac(2);
   set_weight(1);
   set_value(6969);
   set_alias("ring");
   set_name("ring");
   set_type("ring");
}

query_guild_bonus(){ return BONUS; }

add_guild_bonus() {
  if(present("mageobj", this_player()))
    present("mageobj", this_player())->add_int_bonus(BONUS);
}

remove_guild_bonus() {
  if(present("mageobj", this_player()))
    present("mageobj", this_player())->add_int_bonus(-BONUS);
}

