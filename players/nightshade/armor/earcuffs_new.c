inherit "obj/armor";
#include <ansi.h>

/******************************************************************************
 * Program: earcuffs_new.c
 * Path: /players/nightshade/armor
 * Type: Armor
 * Created: September 2014 by Karash
 *
 * Purpose: An armor piece to wear in the earrings slot.  Since these are ear coverings,
 *          they have 1AC, plus since they drop off a mage using mirror images, these
 *          earcuffs also have a bonus for illusion mage spells.
 * 
 * History:
 *          
 ******************************************************************************/


#define GUILDID "mageobj"
#define BONUS_TYPE "illusion"
#define BONUS_TYPE2 "evocation"
#define BONUS_AMOUNT 2

reset(arg)
{
::reset(arg);
if(arg) return;
set_type("earring");
set_name("earcuffs");
SetMultipleIds(({"ear cuffs", "cuffs", "earrings"}));
set_short(YEL+"Elven ear cuffs"+NORM);
set_long("A pair of enchanted gold ear coverings with a row of small beads of crystal\n\
along the edge of the outer ear.  The cuffs are shaped like an elven ear,\n\
but may be worn by almost anyone, thus giving the appearance of pointed ears\n\
when wearing this adornment.\n");
set_ac(1);
set_weight(1);
set_value(1300);
}


query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player())) {
    present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT); 
    present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, BONUS_AMOUNT); 
  }
}


remove_guild_bonus()
{
  if(present(GUILDID, this_player())) {
    present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
    present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, -BONUS_AMOUNT); 
  }
}


