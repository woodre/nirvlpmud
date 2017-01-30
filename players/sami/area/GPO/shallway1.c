/*                      /                                             *
 *    File:             /players/sami/area/GPO/shallway1.c   *
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
   set_short("Southern Hallway");
  long_desc =
" O-==========================================================================-O  \n"+
" |    |    |  The southern hallway has a small cold breeze blowing through it\n"+
" |   -"+HIY+"#"+NORM+"-   |  and the smell of blood can be smelled coming from the south. There\n"+
" |    |    |  aren't much lights here, making visibility quite poor.  Random\n"+
" |    "+HIR+"*"+NORM+"    |  debris are littered across the floor, making walking the hallway\n"+
" |    |    |  hard.  Off into the distant south, what looks like moving\n"+
" |    |    |  shadows can be seen scattering about.\n"+
" |    |    |\n"+
" O-==========================================================================-O\n";

   items =
    ({
	"blood",
	 "An enormous amount of blood appears to be everywhere, upon the floors and walls.",
    "debris",
    "Broken pieces of the ceiling and walls lay scatted about making walking difficult.",
	"shadows",
	"Shadows dance upon the walls. It is almost as if they are watching you.",
    	
});

add_exit("/players/sami/area/GPO/entrance.c","north");
add_exit("/players/sami/area/GPO/shallway2.c","south");
}