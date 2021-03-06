/*                                                                    *
 *    File:             /players/angel/area/town/room/9thnh.c         *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           6/15/07                                       *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("multi", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/town/npc/multi_02"), this_object());
    }
  }
  if(arg) return;
  set_light(1);
  short_desc = "9th & North H";
  long_desc =
"  "+HIM+"Ninth and North H street"+NORM+"\n\
H street is the furthest road north of the city.  There are\n\
sidewalks on both sides of the road with many large oak trees\n\
along each side. The trees provide a lot of shade.  To the\n\
south of H street are many square blocks of houses.\n";

  items =
  ({
	"road",
	"It is a two lane road",
	"city",
	"It is a small quiet town where many people live",
	"sidewalks",
	"They appear to be well worn with many cracks",
	"trees",
	"Large oak trees with large leaves",
	"houses",
	"Average middle class homes",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/10thnh",     "east",
    "/players/angel/area/town/room/8thnh",      "west",
  });
}