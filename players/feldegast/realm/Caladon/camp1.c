/*
File: camp1.c
Author: Feldegast/ Dave Sampson
Date: 10/25/01
Description:
  An orc camp.  The entrance.
*/

#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(!random(2) && !present("orc"))
    move_object(clone_object(MON_PATH+"orc1.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  To the west of you is an orc encampment.  The orcs have constructed\n\
a bailey out of tree trunks lashed together by leather ropes.  The\n\
only way in or out is through the gate.\n";
  items = ({
    "encampment", "The encampment consists of perhaps a dozen tents and several wooden buildings\n"+
                  "further up the side of the mountains is a temple of some sort that\n"+
                  "the orcs have taken over",
    "orcs", "You can see a few orcs milling around inside the encampment",
    "bailey", "The bailey is several hundred feet long and consists of tree trunks\n"+
              "lashed together by leather ropes.  Primitive, but effective",
    "gate", "The \"gate\" is merely a break in the bailey",
  });

  dest_dir = ({
    PATH+"camp2.c", "west",
    PATH+"1x5.c", "east",
  });

}

void init()
{
  ::init();
  add_action("cmd_west", "west");
}

int cmd_west(string str)
{
  if(present("orc") && (string)TP->query_race() != "orc")
  {
    write("The orc blocks your way into the encampment.\n");
    return 1;
  }
}
