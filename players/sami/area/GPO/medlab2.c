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
        MOCO("/players/sami/area/GPO/npc/mvampire.c"),this_object());
     }

     if(!present("vampire 2") && present("vampire"))  {
        MOCO("/players/sami/area/GPO/npc/mvampire.c"),this_object());
		}
   if(arg) return;
   set_light(1);
   set_short("Lower Deck-Lab hall");
  long_desc =
" O-==========================================================================-O\n"+
" |         |  The remains of the old Medical Lab lies in ruins.  All the\n"+
" |   -"+HIY+"#"+NORM+"    |  resting beds are broken, and the healing machines are destroyed.\n"+
" |    |    |  Vampires have infested the lab, scouring over every inch as if\n"+
" |    "+HIR+"*"+NORM+"    |  their trying to figure something out.  The vents are no longer\n"+
" |    |    |  pouring in their healing mist, and the lights are quit dim.  It\n"+
" |    |    |  seems as if the fon stones are losing their power.  To the west\n"+
" |    |    |  lies a broken entrance to another room.\n"+
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
add_exit("/players/sami/area/GPO/medlab1.c","south");
add_exit("/players/sami/area/GPO/medlab3.c","north");
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