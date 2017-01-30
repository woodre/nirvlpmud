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
   set_short("labhall");
  long_desc =
"O-==========================================================================-O\n"+
"|         |  The eastern hallway lights up brighter than the others, with the\n"+
"|         |  fon stones operating at full capacity.  The walls and floors are\n"+
"|         |  smeared with blood, and viles of liquid are busted and leaking\n"+
"| ---"+HIR+"*"+NORM+"    |  onto the floors.  The smell of chemicals eminates from up ahead\n"+
"|    |    |  and the sounds of bubbling can be heard as well.  Random\n"+
"|    |    |  flickers of light can be seen sparking off in the distant rooms.\n"+
"|    |    |  The laboratory entrance lies south.\n"+
"O-==========================================================================-O\n";

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
add_exit("/players/sami/area/GPO/labentrance.c","south");
add_exit("/players/sami/area/GPO/labhall2.c","west");
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