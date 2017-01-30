/*                      /                                             *
 *    File:             /players/sami/area/GPO/abarracks7.c   *
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
int searched;

reset(arg) {

     if(!present("vampire")) {
        MOCO("/players/sami/area/GPO/npc/bvamp.c"),this_object());
        MOCO("/players/sami/area/GPO/npc/bvamp.c"),this_object());
     }

     if(!present("vampire 2") && present("vampire"))  {
        MOCO("/players/sami/area/GPO/npc/bvamp.c"),this_object());
      
     }

     if(arg) return;
   set_light(1);
   set_short("Southern Hallway");
  long_desc =
" O-==========================================================================-O\n"+
" |         |  There is what looks to be a covered up door to the west.  The\n"+
" |    "+HIY+"#"+NORM+"-   |  area here is very dim, almost too dim to see.  You can see\n"+
" |    |    |  several piercing eyes shining through the darkness, with a very\n"+
" |    "+HIR+"*"+NORM+"    |  sadistic look to them.  Although you can't really see it, as the\n"+
" |    |    |  fon stones here have lost most of their power, blood has been\n"+
" |    "+HIY+"#"+NORM+"-   |  sprayed everywhere.  You can smell it, and feel it sticking to\n"+
" |         |  your feet as you walk through the hallway.\n"+
" O-==========================================================================-O\n";


   items =
    ({
	"doors",
	 "Broken pieces of wood.",
    "debris",
    "Broken pieces of the ceiling and walls lay scatted about making walking difficult.",
	"There appears to be movement on the other side, mayby you should check it out?",
	"stones",
	"Crystal like stones that radiate a small amount of light, lay scatted on the floor.",
	"bedrooms",
	"Abandoned cots lay about. They appear to have been abandoned for a long time.",
    	
});
add_exit("/players/sami/area/GPO/ldeck4.c","north");
add_exit("/players/sami/area/GPO/ldeck6.c","south");
}
init() {
     ::init();
       add_action("smell","smell");
       add_action("west","west");
}

smell(str) {
     if(!str) { write("smell what?\n"); return 1; }
       write("You smell the "+str+" and are overcome by the foul scent of blood and chemicals.\n");
       say(this_player()->query_name()+" smells around for something.\n");
     return 1;
}

west() {
TP->move_player("west#players/sami/area/GPO/broom.c");
return 1;}

