/*
*      File:             /players/lacar/area/park/rooms/uphouse1.c 
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
int is_there;
int x;

reset(arg)
{
 ::reset(arg);
   if( !present("babyU", this_object()))
  {
  move_object(clone_object("/players/lacar/area/park/npc/babyU.c"), this_object());
}
    if( !present("fairym", this_object()))
  {  
  move_object(clone_object("/players/lacar/area/park/npc/fairym.c"), this_object());
}  

  is_there=1;
  if(arg) return;
  set_light(1);
  short_desc = "uphouse1";
  long_desc =
  "  This is the living room with a fireplace facing south. There is a\n\
blue couch facing the north. On the fireplace are miniatures of all\n\
the different animals in the park. There is a lamp on a small round\n\
table next to the couch. On one side of the fireplace is a stack of\n\
cut wood, and on the other side is a small cushion for the baby \n\
unicorn. There is an opening on the far side of the couch, which\n\
looks like it leads to the kitchen. Then next to the stack of wood is\n\
a door.\n";

  items =
  ({
    "fireplace",
    "A brick fireplace with logs set for a fire",
    "couch",
    "Blue couch with three cushions on it",
    "cushions",
    "Blue fluffy cushions that look like hiding something",
    "lamp", 
    "A tall slime lamp that lights the room",
    "stack",
    "A pile of cut logs for the fireplace",
    "logs",
    "Wood cut into two foot wedges",
});
dest_dir =
  ({
    "/players/lacar/area/park/rooms/unicornpark12","out",
    "/players/lacar/area/park/rooms/uphouse2","south",
    "/players/lacar/area/park/rooms/uphouse3","north",
});
return 1;
}

init() {
  ::init();
  add_action("search","search");
}
search(str) {
  object gold;
  if(present("Zeek")) {
    write("Zeek is blocking your way!\n");
    return 1;
  }
  if(!str) {
    write("Search what?\n");
    return 1;
  }
  if(str=="couch" && is_there) {
    write("You find a few coins that must have fallen out of someone's pocket!\n");
    gold=clone_object("obj/money");
    gold->set_money(random (4)+2);
    move_object(gold, this_object());
    is_there=0;
    return 1;
  }
  write("You find nothing.\n");
  return 1;
}