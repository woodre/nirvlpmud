/*
*      File:             /players/lacar/area/park/rooms/uphouse3.c 
*      Function:         room
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar(Carla Merrill)
*                                All Rights Reserved
*      Source:           11/22/06
*      Notes:            area
*      Change History
*/

#include <ansi.h>
int searched;
inherit "/room/room";

int x;

reset(arg)
{
  ::reset(arg);
  {
}
  set_light(1);
  short_desc = "uphouse3";
  long_desc =
  "  This is the bedroom done in different shades of blue. There is a\n\
canopy bed in the center of the room. It has a night stand on one side,\n\
and a bureau on the other. There is a reading lamp on the night stand.\n\
There is a closet full of dresses, cloaks and skirts. There is a small\n\
pillow at the foot of the bed, just the right size for a baby unicorn.\n";

  items =
  ({
    "bureau",
    "A wooden bureau painted a sky blue",
    "bed",
    "A mahogany bed, 232 x170 x 224 in size",
    "canopy",
    "A light baby blue cloth that draps bed",
    "nightstand", 
    "A mahogany stand with a drawer",
     "closet",
     "A organized closet of clothes",
     "lamp",
     "A reading lamp curved toward the bed",
     "pillow",
     "A round blue pillow",
});
dest_dir =
({
"/players/lacar/area/park/rooms/uphouse1","south",
});
}

void init() {
  ::init();
  add_action("do_lie", "lie");
add_action("do_search","search");
}

status do_lie(string arg) {
  if (!arg) {
    notify_fail("lie what?\n");
    return 0;
   }
  if (arg == "bed" || arg == "soft bed") {
	write("You lie on bed and feel very sleepy.\n");
    say(this_player()->query_name()+" lays on the bed and looks ready to sleep.\n");
	return 1;
  }

  notify_fail("Lie what?");
  return 0;
}

do_search() {
	if(searched) {write("This room has already been searched.\n");
return 1;
}
else {
write("You find a unicorn rattle!\n");
move_object(clone_object("/players/lacar/area/park/obj/unicornrattle.c"), this_player());
searched = 1;
}
return 1;
}
