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
if(!present("vampire")) {
        MOCO("/players/sami/area/GPO/npc/mvampire.c"),this_object());
       }
   if(arg) return;
   set_light(1);
   set_short("Lower Deck-Lab hallway");
  long_desc =
" O-==========================================================================-O\n"+
" |    |    |  The remains of the old GPO Laboratory has for the most part\n"+
" |    |    |  remained untouched, unlike the rest of the spacestation in this\n"+
" |    |    |  area.  Some of the larger test tubes still remain intact as well\n"+
" |    "+HIR+"*"+NORM+"    |  as the assorted vials and storage shelves.  However, there is\n"+
" |    |    |  blood sprayed everywhere.  There are dead bodies in lab coats\n"+
" |   -"+HIY+"*"+NORM+"    |  lying on the ground, with blood soaked vampires standing above\n"+
" |         |  them.\n"+
" O-==========================================================================-O\n";

   items =
    ({
	"stone",
	"A glowing "+HIR+"red"+NORM+" fon stone.",
	"walls",
    "Strange metallic walls; cracked and busted, chunks of wire protrude.",
	"ceiling",
	"A low hanging metallic ceiling with thick metal wire protruding from the cracks.",
	"blood",
	"pools of blood lay stagnant on the floor.",
	"vials",
	"Broken glass, with liquid seeping out everywhere.",
		
});
add_exit("/players/sami/area/GPO/labpath6.c","north");
add_exit("/players/sami/area/GPO/labpath4.c","south");
}
init() {
     ::init();
       add_action("smell","smell");
}

smell(str) {
     if(!str) { write("smell what?\n"); return 1; }
       write("You smell the "+str+" and are overcome by the foul scent of blood and chemicals.\n");
       say(this_player()->query_name()+" smells around for something.\n");
     return 1;
}