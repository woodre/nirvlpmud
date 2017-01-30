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
   set_short("Lower Deck-Lab hallway");
  long_desc =
" O-==========================================================================-O\n"+
" |         |  The smell of chemicals is almost intoxicating, and several vials\n"+
" |   -"+HIY+"*"+NORM+"    |  of liquid can be seen scattered everywhere.  The fon stones here\n"+
" |    |    |  are sparking erratically, glowing really bright then dimming\n"+
" |    "+HIR+"*"+NORM+"    |  down to a barely visible glow.  To the south is a destroyed\n"+
" |    |    |  room, but there is a walkable path through it.  The room south\n"+
" |    |    |  is dark, and no light can be seen coming from the other side.\n"+
" |    |    |\n"+
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
add_exit("/players/sami/area/GPO/labhallway1.c","north");
add_exit("/players/sami/area/GPO/labpath6.c","south");
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