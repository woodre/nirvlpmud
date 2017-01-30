/* 2005.08.16 Zeus
// -changed from obj/armor.c to bfeq object to support
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c";
*/
/* edited 05-15-07 to add mage guild bonus and change 
high white short to bold black and lowered weight
a veil of shadow should weigh next to nothing.*/
inherit "/players/forbin/closed/bfeq.c";
#include "/players/arrina/closed/ansi.h"
#define GUILDID "mageobj"
#define BONUS_TYPE "illusion"
#define BONUS_AMOUNT 3 

reset(arg){
  ::reset(arg);
   set_name("Shadowveil");
  set_short(BOLD+""+BLK+"ShadowVeil"+NORM);
  set_alias("veil");
  set_long("Almost translucent, this veil appears to be\n"+
            "armor used by the mysterious Qurd mages.\n");
  set_type("armor");
  set_ac(5);
/* <ill> may 2005 */
  set_params("magical",5,0,0);
  set_weight(1);
  set_value(5000);
  set_bf_guild_bonus(0, 5);
  set_bf_guild_bonus(4, 5);
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
