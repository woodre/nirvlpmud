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
if(!present("vampire"))  {
    MOCO("/players/sami/area/GPO/npc/lvampboss.c"),this_object()); }

     if(arg) return;
   set_light(1);
   set_short("Southern Hallway");
  long_desc =
" O-==========================================================================-O\n"+
" |         |  This room is light up bright red, both by the fon stone in the\n"+
" |         |  middle of the ceiling, and by the massive amount of blood thrown\n"+
" |      |  |  around everywhere.  A few dead bodies lie at the feet of a\n"+
" |    "+HIR+"*"+NORM+"-"+HIY+"#"+NORM+"  |  hideous looking beast.  The room itself seems to be empty of\n"+
" |      |  |  anything save a small coffin in the corner.  There is blood\n"+
" |         |  covering almost every part of this room, from the floor to the\n"+
" |         |  ceiling.\n"+
" O-==========================================================================-O\n";


   items =
    ({
	"doors",
	"Broken pieces of wood.",
    "debris",
    "Broken pieces of the ceiling and walls lay scatted about making walking difficult.",
	"There appears to be movement on the other side, mayby you should search it?",
	"stones",
	"Crystal like stones that radiate a small amount of light, lay scatted on the floor.",
	"bedrooms",
	"Abandoned cots lay about. They appear to have been abandoned for a long time.",
    	
});
add_exit("/players/sami/area/GPO/ldeck5.c","east");
}

