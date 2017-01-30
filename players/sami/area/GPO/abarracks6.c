/*                      /                                             *
 *    File:             /players/sami/area/GPO/abarracks6.c   *
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

     if(!present("vampire")) {
        MOCO("/players/sami/area/GPO/npc/lvampire.c"),this_object());
     }

     if(arg) return;
   set_light(1);
   set_short("Southern Hallway");
  long_desc =
" O-==========================================================================-O\n"+
" |         |  Further inside the barracks you can see where the smell was\n"+
" |         |  coming from.  There are dead bodies lined throughout the broken\n"+
" |      |  |  and scattered debris.  The smaller vampires are feasting on the\n"+
" | ---"+HIR+"*"+NORM+"-"+HIY+"#"+NORM+"  |  dead bodies, and slink back into the darkness when they notice\n"+
" |         |  your presence.  All the doors to the former bedrooms are busted\n"+
" |         |  in and the rooms have collapsed in.\n"+
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

add_exit("/players/sami/area/GPO/abarracks5.c","east");
add_exit("/players/sami/area/GPO/abarracks7.c","west");
}