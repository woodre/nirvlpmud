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
if(!present("dameon"))  {
    MOCO("/players/sami/area/GPO/npc/mvampboss.c"),this_object()); }
   if(arg) return;
   set_light(1);
   set_short(""+BOLD+"I"+HIK+"nfested"+NORM+" "+BOLD+"T"+HIK+"est"+NORM+" "+BOLD+"R"+HIK+"oom"+NORM+"");
  long_desc =
" O-==========================================================================-O\n"+
" |         | \n"+
" |   -"+HIY+"*"+NORM+"-   |  Large test tubes, big enough to fit an entire human inside, line\n"+
" |    |    |  the perimeter of the room.  Blood, both fresh and coagulated, is\n"+
" |    "+HIR+"*"+NORM+"    |  scattered on the test tubes, floors, walls, and some even made\n"+
" |         |  its way onto the ceiling.  It appears some fighting has been\n"+
" |         |  done in this room, but for the large part appears to be this\n"+
" |         |  vampire's nest.\n"+
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
	"test tubes",
	"glass flasks, and test tubes lay scatterd abot the room, coverd in what appears to be blood.",
});
add_exit("/players/sami/area/GPO/labpath3.c","north");
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