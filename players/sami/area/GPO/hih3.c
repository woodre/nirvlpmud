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
" |         |  This hallway is heavily infested with brutal looking vampires.\n"+
" |         |  There are wires protruding from the busted walls and ceilings,\n"+
" |         |  and deep scratches can be see marked along some of the walls.\n"+
" | ---"+HIR+"*"+NORM+"--- |  The metal floors are stained heavy with blood, and there are\n"+
" |         |  body parts scattered about.  There is very little light in this\n"+
" |         |  area, but enough that adjusted eyes can see clear enough.\n"+
" |         |\n"+
" O-==========================================================================-O\n";

   items =
    ({
	"wires",
	 "An abnormally large metal wires are protruding from the walls and ceilings.",
    "walls",
    "Strange metallic walls; cracked and busted, chunks of wire protrude.",
	"ceiling",
	"A low hanging metallic ceiling with thick metal wire protruding from the cracks.",
	"blood",
	"pools of blood lay stagnant on the floor.",
	"parts",
	"There are dismembered legs, arms, torsos and heads laying randomly about.",
    	
});

add_exit("/players/sami/area/GPO/hih2.c","east");
add_exit("/players/sami/area/GPO/hih4.c","west");
}