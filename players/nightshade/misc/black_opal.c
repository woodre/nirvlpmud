inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: black_opal.c
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
set_id("black opal");
set_short(GRY+"Black"+NORM+GRN+" O"+YEL+"p"+GRN+"a"+YEL+"l"+NORM);
set_long
("Black opal is a prized gem among most communities. It is dark\n"+
"green with black mottling and golden flecks.\n");
set_weight(1);
set_alias("gem");
set_value(1500);
}
id(str) { return (::id(str) || str == "opal"); }
