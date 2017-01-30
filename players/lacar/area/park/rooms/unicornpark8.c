/*
*      File:             /players/lacar/area/park/rooms/unicornpark8.c
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
  {
}
  set_light(1);
  short_desc = "Unicorn Park 8";
  long_desc =
  "  This is the top of a large oak tree, and the view is breathtaking\n\
up here. The tops of the trees look like green clouds and are very\n\
deep in color. The tree tops make it feel like a green carpet\n\
changing into a blue one of the sky. Both seem to run into each other,\n\
making it look like it will never end. There is a empty nest nestled\n\
in the middle of the tree looking comfy enough to sit in.\n";

  items =
  ({
    "oak",
    "A very sturdy, tall tree",
    "top",
    "A lush green foliage",
    "sky",
    "A very blue sky",
	"nest",
	"A nest full of old feathers and twigs",
	"trees",
	"The green foliage of the top of trees",
	"view",
	"breathetaking",
	"carpet",
	"the green foliage running into the blue sky",
	"clouds",
	"The shape of the tree tops",
	"feathers",
	"different shape and sizes of fluffy feathers",
	"twigs",
	"differeent size sticks",
	"tree",
	"A very sturdy, tall oak",
 });
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark7","south",
"/players/lacar/area/park/rooms/unicornpark9","east",
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
  if (arg == "nest" || arg == "empty nest") {
	write("You sit in the nest and feel very relaxed.\n");
    say(this_player()->query_name()+" sits in the nest and looks very relaxed.\n");
	return 1;
  }

  notify_fail("Sit what?\n");
  return 0;
}