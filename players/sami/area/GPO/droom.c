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
   set_short("Lab Entrance");
  long_desc =
"O-==========================================================================-O\n"+
"|    |    |  Broken steel beams have fallen through the ceiling here and\n"+
"|    |    |  block the paths south.  However, there are small crawl spaces\n"+
"|    |    |  through the beams, debris, and other rubble that makes up this\n"+
"|    "+HIR+"*"+NORM+"--- |  room.  It appears as if someone tried to seal off this area.  Its\n"+
"|         |  dark and damp from some of the water leaking out of the\n"+
"|         |  destroyed ceiling.  After climbing past the debris the room\n"+
"|         |  opens up lights can be seen throughout the area.\n"+
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
add_exit("/players/sami/area/GPO/labentrance.c","north");
add_exit("/players/sami/area/GPO/labpath1.c","east");
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