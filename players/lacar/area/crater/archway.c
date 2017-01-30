/*
*      File:             	/players/lacar/area/crater/archway.c
*      Function:        room
*      Author(s):       Lacar@nirvana
*      Copyright:      Copyright (c) 2007 Lacar (Carla J Merrill)
*                     			All Rights Reserved
*      Source:    		  01/13/2007
*      Notes:        	area
*      Change History: 
*/

#include <ansi.h>

inherit "/room/room";

reset(arg)
{
  set_light(1);
  short_desc = "Archway";
  long_desc =
  "   This is the archway from the Unicorn park to a crater made from\n\
a meteor that came crashing down into the forest. The archway was made\n\
from the trees that used to stand here. The edge of the crater starts\n\
to slant downward. The grass gives way to dirt, it is not known what\n\
lies down in the crater.\n";

  items =
  ({
    "branches",
    "Slender wooden branches woven into an archway",
    "edge",
    "The rim of the crater",
    "arch",
    "Branches woven into a covering",
    "grass",
    "Green grass with a little brown on edges",
    "dirt",
    "Dark brown dirt",
    "archway",
    "Branches woven together",
    "crater",
    "A indentation in the ground",
    "forest",
    "Green trees seen to the south",
});
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark12","south",
"players/lacar/area/crater/crater1","down",
});
}

