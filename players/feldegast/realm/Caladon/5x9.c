/*
File: 5x9.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/1/01
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=5; y=9;
  set_light(1);
  short_desc="Ferry";
  long_desc=
"  To the north of you, the River Siber flows from west to east.  A\n\
ferry is tied up at the dock on this side of the river.  To the south,\n\
a well-paved road winds through the hills.\n";
  items=({
    "river", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "siber", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "foothills", "The hills to the south of you are dotted with trees",
    "hills", "The hills to the south of you are dotted with trees",
    "hill", "The hills to the south of you are dotted with trees",
    "trees", "Tall, deciduous trees dot the hills",
    "boat", "The boat appears to be a ferry for crossing the river",
    "road", "The road is paved with cobbles",
    "ferry", "The ferry is old, but appears to be sturdy enough to get you across the river",
  });
  dest_dir=({
    PATH+"4x9.c","west",
    PATH+"6x9.c","east",
    PATH+"5x8.c","south",
    "blank", "ferry",
  });
}

void init() {
  ::init();
  add_action("cmd_ferry", "ferry");
}

int cmd_ferry(string str) {
  if((int)TP->query_money() < 150) {
    write("You need 150 coins.\n");
    return 1;
  }
  TP->add_money(-150);
  write("You pay the ferryman 150 coins to take you across the river.\n");
  say(TPN+" crosses the river on the ferry.\n");
  move_object(TP,(object)"/players/feldegast/realm/JalHab/Map.c"->query_location(5,0));
  say(TPN+" arrives on the ferry.\n");
  return 1;
}
