/*                      /                                             *
 *    File:             /players/sami/area/GPO/hroom1.c   *
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
if(!present("vampire"))  {
    MOCO("/players/sami/area/GPO/npc/mikal.c"),this_object()); }

   if(arg) return;
   set_light(1);
   set_short("Sleeping Quarters");
  long_desc =
" O-==========================================================================-O\n"+
" |         |  Stepping inside the room you find a destroyed bedroom, with bunk\n"+
" |         |  beds broken down, and scattered wooden debris lying everywhere.\n"+
" |         |  In the middle of the room stands a large vampire who stares at\n"+
" |    "+HIR+"*"+NORM+"    |  you in complete silence.  There's a ring on his finger that\n"+
" |    |    |  seems to cloak him in some sort of dark power.  A single dim fon\n"+
" |   -"+HIY+"#"+NORM+"-   |  stone lights the room, making the vampire's skin appear red in\n"+
" |         |  color.\n"+
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

add_exit("/players/sami/area/GPO/abarracks7.c","south");
}