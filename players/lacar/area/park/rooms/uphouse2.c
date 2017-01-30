/*
*      File:             /players/lacar/area/park/rooms/uphouse2.c 
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

int searched;

reset(arg)
{
  ::reset(arg);
  
  set_light(1);
  short_desc = "uphouse2";
  long_desc =
  "  This is the kitchen with a wood burning stove. There is an open\n\
pantry stocked with food. There are jars from canning with fruits and\n\
vegetables. Over the sink on the south wall is a window, which\n\
overlooks a garden that grows different fruits and vegetables. The\n\
kitchen is very clean and tidy. Everything is in its place, from the\n\
pots hanging from hooks to the silverware in the drawers.\n";

  items =
  ({
    "stove",
    "A black stove set with wood for cooking",
    "pantry",
    "A closet with shelves full of food items",
    "window",
    "A square window with blue lace curtains",
    "pots", 
    "All different size pots for cooking",
    "sink",
    "Clean white ceramic sink",
    "jars",
    "Glass jars filled with different kinds of food",
});
dest_dir =
({
"/players/lacar/area/park/rooms/uphouse1","north",
});
searched=0;
}
init(){ ::init(); add_action("do_search","search"); }

do_search() {
	if(searched) {write("This room has already been searched.\n");
return 1;
}
else {
write("You find a rolling pin!\n");
move_object(clone_object("/players/lacar/area/park/obj/rollingpin.c"), this_player());
searched = 1;
}
return 1;
}

