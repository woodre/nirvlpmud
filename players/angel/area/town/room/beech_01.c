inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/town/room/beech_01.c      *
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


reset(arg)
{
  ::reset(arg);
  if( !present("multi", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi.c"), this_object());
  if( !present("multi02", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi_02.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Beech Drive Entrance";
  long_desc =
"    "+YEL+"Beech Drive Entrance"+NORM+"\n\
  One can feel the small town atmosphere in Beech Drive subdivision.\n\
Young singles and married couple with families fill the streets in\n\
this small town.  The roads are bustling with the active families.\n\
There are sidewalks on both sides of the road with many large oak\n\
trees along each side.\n\
'123' Beech Drive\n";

  items =
  ({
	"road",
    "Two way paved lanes",
    "sidewalks",
	"They appear to be well worn with many cracks",
	"trees",
	"Large oak trees with large leaves",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/6thnh",        "north",	  
    "/players/angel/area/town/room/beech_02",     "south",
  });
}

init() {
  ::init();
    add_action("enter","123");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/town/land/land_03.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
