/*
File: 5x8.c
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
  x=5; y=8;
  set_light(1);
  short_desc="Baron's Highway";
  long_desc=
"  A well-paved road goes north to the River Siber, and winds south\n\
through low foothills dotted with trees.  By the side of the road is\n\
an obelisk with a bronze plaque.\n";
  items=({
    "river", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "siber", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "spine", "Many miles to the east, you see the snow-capped mountain range\n"+
             "known as the Spine of Allandria",
    "foothills", "The hills to the south of you are dotted with trees",
    "hills", "The hills to the south of you are dotted with trees",
    "hill", "The hills to the south of you are dotted with trees",
    "trees", "Tall, deciduous trees dot the hills",
    "obelisk", "A short obelisk about waist-height sits beside the road.\n"+
               "There is a bronze plaque on it",
    "plaque", "A bronze plaque with neat writing embossed upon it has been\n"+
              "bolted to the obelisk.  You can 'read' the plaque",
  });
  dest_dir=({
    PATH+"5x9.c","north",
    PATH+"4x8.c","west",
    PATH+"6x8.c","east",
    PATH+"5x7.c","south",
  });
}

void init() {
  ::init();
  add_action("cmd_read", "read");
}

int cmd_read(string str) {
  if(str!="plaque" && str!="sign" && str!="obelisk") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The plaque says:\n"+
"+--------------------------------------------------------+\n\
|                                                        |\n\
|                   Baron's Highway                      |\n\
|                                                        |\n\
|                    Founded 384 AL                      |\n\
|                                                        |\n\
|                  Baron Halek deBlood                   |\n\
|                                                        |\n\
+--------------------------------------------------------+\n\
\n");
  say(TPN+" reads the plaque.\n");
  return 1;
}

