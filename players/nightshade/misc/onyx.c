inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: onyx.c
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
set_short(GRY+"Onyx"+NORM);
set_long
("A rather large onyx gem Hephaestus has plundered.\n");
set_weight(1);
set_alias("gem");
set_value(1500);
}

id(str) { return str == "onyx" || str == "evil_onyx"; }
