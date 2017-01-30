/*                      /                                             *
 *    File:             /players/sami/area/GPO/bentrance.c   *
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
   set_short("Barracks Entrance");
  long_desc =
" O-==========================================================================-O\n"+
" |    |    |  This is the old GPO Barracks, where military personnel used to\n"+
" |    |    |  sleep.  Along the hallways are destroyed rooms that used to be\n"+
" |    |    |  bedrooms.  There are broken pieces of doors, and scattered\n"+
" | ---"+HIR+"*"+NORM+"--- |  debris lying everywhere, and smaller vampires have made this\n"+
" |         |  area their home.  Some of the red fon stones are still active\n"+
" |         |  and are dimly lighting the area with their red glow.\n"+
" |         |\n"+
" O-==========================================================================-O\n";

   items =
    ({
	"doors",
	 "Broken pieces of wood.",
    "debris",
    "Broken pieces of the ceiling and walls lay scatted about making walking difficult.",
	"stones",
	"Crystal like stones that radiate a small amount of light, lay scatted on the floor.",
	"bedrooms",
	"Abandoned cots lay about. They appear to have been abandoned for a long time.",
    	
});

add_exit("/players/sami/area/GPO/shallway3.c","north");
add_exit("/players/sami/area/GPO/abarracks1.c","east");
add_exit("/players/sami/area/GPO/abarracks13.c","west");
}