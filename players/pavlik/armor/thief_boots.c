inherit "players/pavlik/armor/armor";
#include "/players/pavlik/guild_bonus"

reset(arg){
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
  guild_stat = random(sizeof(MAGE_GUILD_STATS)-1);
}


