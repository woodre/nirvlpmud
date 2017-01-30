#include "../define.h"
#define GUILDID "mageobj"
#define BONUS_TYPE "wisdom"
#define BONUS_TYPE2 "conjuration"
#define BONUS_AMOUNT 1
inherit ARMOUR;

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_short("Shamanic "+BLU+"boxer shorts"+NORM);
   set_id("shorts");
   set_alias("boxer shorts");
   set_type("underwear");
   set_ac(1);
   set_long(
      "Tattered boxer shorts that seem to have some property\n"+
      " to them that makes them offer a bit more protection.\n"+
      " They *WERE* from a shaman, of course.\n");
}
query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, BONUS_AMOUNT);	
 }
			
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, -BONUS_AMOUNT);	
  }
}
do_special(owner) {
   if(!random(8)) {
      tell_object(USER,
         " . .. the cotton seems to "+BLU+"f  ad e"+NORM+" from reality for a split-second.\n"+
         "The shorts remorph themselves.\n");
      return 1; }
}
