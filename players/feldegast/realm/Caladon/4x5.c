/*
File: 4x5.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 7/06/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=4; y=5;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  To the east are the gates of the walled city of Calador.  A poor\n\
dirt road leads west through the hilly countryside of the Barony of\n\
Caladon.  To the south, a wooden bridge leads over the River Xian.\n";
  items=({
    "hill",        "The rolling foothills of Caladon are dotted with trees",
    "countryside", "reflexive",
    "caladon",     "You can't see it all from here.  You'd have to move around to see it all",
    "city",        "The walled city of Calador lies to the east",
    "calador",     "The walled city of Calador lies to the east",
    "road",        "The dirt road leads west through the hilly countryside",
    "bridge",      "To the south, a wooden bridge leads across the River Xian",
  });
  dest_dir=({
    PATH+"4x6.c", "north",
    PATH+"3x5.c", "west",
    "/players/feldegast/realm/City/marble1.c", "east",
    PATH+"4x4.c", "south",
  });
}


void init()
{
  ::init();
  add_action("cmd_south", "south");
}

int cmd_south(string str)
{
  write("The bridge is currently out.\n");
  return 1;
}
