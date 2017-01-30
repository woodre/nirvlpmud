inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: moonstone.c
 * Path: /players/nightshade/misc/
 * Type: Treasure
 * Updated: October 2014 by Karash
 *
 * Purpose: An upgrade to the loot found from red dragon area in Nightshade's
 *          area.  Increased value and added color.
 *
 * History:
 *          
 ******************************************************************************/
 
 
reset(arg) {
if (arg) return;
set_id("moonstone");
set_short(HIW+"M"+NORM+"o"+HIW+"o"+NORM+"n"+HIW+"s"+NORM+"t"+HIW+"o"+NORM+"n"+HIW+"e"+NORM);
set_long
("A white stone with a pale blue hue.\n");
set_weight(1);
set_alias("gem");
set_value(1500);
}
