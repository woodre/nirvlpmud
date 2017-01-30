/* edited 05-15-07 by Tallos to include mage guild bonus*/

#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
#define GUILDID "mageobj"
#define BONUS_TYPE "enchantment"
#define BONUS_AMOUNT 1 
int n, ahp;

reset(arg){
   ::reset(arg);

set_name("sash");
set_short(GRY+"Enchanted grey sash"+NORM);
set_long(
  "A beautiful grey sash to be worn around the waist.  It has been enchanted\n"+
  "by some mystical being to provide special protection.\n");

set_type("belt");
set_ac(2);
set_weight(1);
set_value(1000);
/*
set_save_flag();
*/
}
query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
			
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
	
}