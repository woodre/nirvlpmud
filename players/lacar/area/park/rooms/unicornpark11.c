/*
*      File:             /players/lacar/area/park/rooms/unicornpark11.c 
*      Function:         room
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar(Carla Merrill)
*                                All Rights Reserved
*      Source:           11/22/06
*      Notes:            area
*      Change History:
*/

#include <ansi.h>
inherit "/room/room";

int x;

reset(arg)
{
 ::reset(arg);
   if( !present("pixie", this_object()))
  {
    for(x=0; x<3; x++)
    {
  move_object(clone_object("/players/lacar/area/park/npc/pixief.c"), this_object());
}
}
  ::reset(arg);
  set_light(1);
  short_desc = "Unicorn Park 11";
  long_desc =
  "  This is a field full of all different colored flowers. They make\n\
it very colorful. There is a pond with a river running north from it.\n\
The pond looks very refreshing and still. The river seems like it runs\n\
on forever.\n";
  items =
  ({
    "flowers",
    "Different wild flowers",
    "pond",
    "Blue in color and refreshing",
    "river",
    "Green blue river that runs on and on",
 });
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark10","south",
"/players/lacar/area/park/rooms/unicornpark12","north",
});
}

void init() {
	::init();
  add_action("do_sit", "sit");
}

status do_sit(string arg) {
  if (!arg) {
    notify_fail("Sit what?\n");
    return 0;
   }
  if (arg == "pond" || arg == "pond") {
	write("You sit in the water and feel very refreshed.\n");
    say(this_player()->query_name()+" sits in the pond and looks very cooler.\n");
	return 1;
  }

  notify_fail("Sit what?");
  return 0;
}