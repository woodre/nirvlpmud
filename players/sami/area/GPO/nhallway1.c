/*                      /                                             *
 *    File:             /players/sami/area/GPO/entrance.c   *
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
   set_short("teleporter room");
  long_desc =
" O-==========================================================================-O\n"+
" |    |    |  The northern hallway is riffe with different sounds coming from\n"+
" |   -"+HIY+"#"+NORM+"-   |  all different directions.  There is less blood and broken debris\n"+
" |    |    |  in this portion of the area, but the light remains just as dim.\n"+
" |    "+HIR+"*"+NORM+"    |  The smell of blood lingers through the area, and sounds of\n"+
" |    |    |  vampires feasting can be heard.  Some parts of the hallway are\n"+
" |   -"+HIY+"#"+NORM+"-   |  brighter than others, but overall its hard to see.\n"+
" |    |    |\n"+
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
    	
});

add_exit("/players/sami/area/GPO/entrance.c","south");
add_exit("/players/sami/area/GPO/nhallway2.c","north");
}