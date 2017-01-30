/*
File: 5x7.c
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
  x=5; y=7;
  set_light(1);
  short_desc="Baron's Highway";
  long_desc=
"  A well-paved road goes north to the River Siber, and winds south\n\
through low foothills dotted with trees.  A dirt path leads off to\n\
the west.  By the side of the road is a signpost.\n";
  items=({
    "river", "The river is far to the north",
    "siber", "The river is far to the north",
    "spine", "Many miles to the east, you see the snow-capped mountain range\n"+
             "known as the Spine of Allandria",
    "foothills", "The hills to the south of you are dotted with trees",
    "hills", "The hills to the south of you are dotted with trees",
    "hill", "The hills to the south of you are dotted with trees",
    "trees", "Tall, deciduous trees dot the hills",
    "road", "The road is paved with cobbles",
    "signpost", "The signpost points to the north, west, and east",
  });
  dest_dir=({
    PATH+"5x8.c","north",
    PATH+"4x7.c","west",
    PATH+"6x7.c","east",
    PATH+"5x6.c","south",
  });
}

void init() {
  ::init();
  add_action("cmd_read", "read");
}

int cmd_read(string str) {
  if(str!="signpost" && str!="sign" && str!="post") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The signpost points in three directions:\n"+
        "  North: Ferry\n"+
        "  West: Graveyard\n"+
        "  South: Calador\n"
  );
  say(TPN+" reads the signpost.\n");
  return 1;
}

