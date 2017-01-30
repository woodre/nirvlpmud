/*
*      File:            /players/lacar/area/crater/crater3.c
*      Function:         room
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2007 Lacar(Carla Merrill)
*                                All Rights Reserved
*      Source:                              
*      Notes:            
*      Change History
*/

#include <ansi.h>

inherit "/room/room";

reset(arg)   
{
  if(arg) return;
  set_light(1);
  short_desc = "Crater 3";
  long_desc =
  " In this area section you can see nothing through the thick wall of\n\
trees. Studing the trees you see a lone oak standing among all the\n\
pines. The oak is giving off a very strong and unfimiliar aura from\n\
the rest. The grass is light green in color and seems to be less here.\n\
The roots from the trees seem to be taken over.\n";

  items =
  ({
	  "trees",
	  "A row of gree pine trees",
	  "pine",
	  "Green trees with pine needles",
	  "needles",
	  "Little green thin leaves of pine trees",
	  "oak",
	  "A broad leaved tree with a magical aura",
      "grass",
      "Light green patches",
      "roots",
      "The feet of the oak tree",   
   });
dest_dir =
({
"/players/lacar/area/crater/crater1","southwest",
"/players/lacar/area/crater/crater5","northwest",
"/players/lacar/area/crater/crater6","northeast",
});
}
