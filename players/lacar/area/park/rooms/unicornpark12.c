/*
*      File:             /players/lacar/area/park/rooms/unicornpark12.c 
*      Function:         room
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar(Carla Merrill)
*                                All Rights Reserved
*      Source:           11/22/06
*      Notes:            area
*      Change History
*/

#include <ansi.h>
inherit "/room/room";

int x;

reset(arg)
{
 ::reset(arg);
   if( !present("fwizardT", this_object()))
  {
  move_object(clone_object("/players/lacar/area/park/npc/fwizardT.c"), this_object());
}

  ::reset(arg);
  set_light(1);
  short_desc = "Unicorn Park 12";
  long_desc =
  "  This area has river running from the south, it bends and flows\n\
around a house. There is a white picket fence with a gate boarding the\n\
house. The fence has a row of roses on the other side of it. The area\n\
area looks neat and tidy. There looks like a path leading north, but it\n\
looks like it ends at a boulder.\n";

  items =
  ({
    "door",
    "A blue door that invites one in",
	"roses",
    "Yellow, red and white roses",
    "river",
    "A green blue river that runs on and on",
    "fence",
    "White fence with slates",
    "gate",
    "Open wooden gate",
    "boulder",
    "A ten foot round stone",
    "house",
    "A red brick house with white wood trim",
    "north",
    "A boulder blocks the path", 
    "path",
    "A dirt path that is not used much, because it stops at a boulder",
});
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark11","south",
"/players/lacar/area/park/rooms/uphouse1","enter",
});
}

