/******************************************************************************
 * Program: foulpendant.c
 * Path: /players/khrell/armors/skaven
 * Type: Armor
 * Created: ? by Khrell
 *
 * Purpose: Armor with special.
 * History:
 *   08/03/2011 Dragnar - Added Mage Bonus
 ******************************************************************************/
inherit "obj/armor";

#include <ansi.h>
#define ENV environment(this_object())
#define GUILDID "mageobj"
#define BONUS_TYPE "necromancy"
#define BONUS_AMOUNT 2

reset(arg){
   ::reset(arg);

set_name("pendant");
set_short(HIK+"The Foul Pendant"+NORM);
set_long(
  "A magical Skaven talisman crafted from a giant rat's skull with a\n"+
  "potent rune of protection etched in warpstone ink on the surface.\n"+
  "A lazy stream of sickly green fumes constantly drift from the empty\n"+
  "eye sockets, forming some sort of protective barrier.\n");
set_type("necklace");
set_ac(1);
set_params("other|poison",0,20,0);
set_weight(1);
set_value(2000);
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

do_special(owner){
if(random(100) < 12) { tell_object(environment(),
    HIK+"The Foul Pendant's fumes solidify and blunts the attack!\n"+NORM);
  return 1; }
ENV->add_hit_point(5);
return 0;
}
