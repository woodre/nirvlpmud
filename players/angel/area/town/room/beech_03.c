inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/town/room/beech_03.c      *
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

int x;

reset(arg)
{
  ::reset(arg);
  if( !present("multi02", this_object()) )
  {
    for(x=0; x<4; x++)
    {
    move_object(clone_object("/players/angel/area/town/npc/multi_02"), this_object());
    }
  }
  if(arg) return;
  set_light(1);
  short_desc = "Beech drive";
  long_desc =
"    "+YEL+"Beech Drive"+NORM+"\n\
  Beech Drive is a small subdivision where the road curves\n\
through two city blocks.  Most of the city is split into square\n\
blocks.  This area is new to the city and is filled with filled\n\
with average sized houses.  Sidewalks line both sides of the\n\
street with small oak trees planted along the sidewalks.\n\
'127' Beech Drive\n";

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
    "/players/angel/area/town/room/beech_02",     "northwest",	  
    "/players/angel/area/town/room/beech_04",     "southeast",
  });
}

init() {
  ::init();
    add_action("enter","127");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/town/land/land_05.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
