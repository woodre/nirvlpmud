inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: topaz.c
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
set_id("topaz");
set_short(BLU+"Topaz"+NORM);
set_long
("A rather large topaz gem Hephaestus has plundered.\n");
set_weight(1);
set_alias("gem");
set_value(1500);
}
