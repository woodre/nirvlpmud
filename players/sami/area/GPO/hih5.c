/*                      /                                             *
 *    File:             /players/sami/area/GPO/hih1.c   *
 *    Function:         room                                          *
 *    Author(s):        Sami@Nirvana                                  *
 *    Copyright:        Copyright (c) 2014 Sami                       *
 *                              All Rights Reserved.                  *
 *    Source:                   10/4                                  *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>
#include "define.h"

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Lower Deck");
  long_desc =
" O-==========================================================================-O\n"+
" |         |  The heavily infested hallway comes to an abrupt end.  The\n"+
" |         |  hallway appears to have kept going but has since been collapsed\n"+
" |         |  in.  There is too much debris blocking the way to the wast.\n"+
" |    "+HIR+"*"+NORM+"--- |  However, to the north what looks like a door can be seen through\n"+
" |         |  some of the rubble and debris.  Perhaps if one could find a key\n"+
" |         |  they would be able to open it.\n"+
" |         |\n"+
" O-==========================================================================-O\n";

   items =
    ({
	"wires",
	 "An abnormally large metal wires are protruding from the walls and ceilings.",
	 "debris",
    "Broken pieces of the ceiling and walls lay scatted about making walking difficult.",
	"door",
	"An office door. It appears to be shut and locked. Maybe there is a key nearby?",
    "walls",
    "Strange metallic walls; cracked and busted, chunks of wire protrude.",
	"ceiling",
	"A low hanging metallic ceiling with thick metal wire protruding from the cracks.",
	"blood",
	"pools of blood lay stagnant on the floor.",
	"parts",
	"There are dismembered legs, arms, torsos and heads laying randomly about.",
    	
});

add_exit("/players/sami/area/GPO/hih4.c","east");
}