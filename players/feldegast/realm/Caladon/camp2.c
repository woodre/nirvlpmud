/*
File: camp2.c
Author: Feldegast/ Dave Sampson
Date: 10/25/01
Description:
  An orc camp.  The entrance.
*/

#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(!present("orc"))
    while(random(3))
      move_object(clone_object(MON_PATH+(random(2)?"orc1.c":"orc2.c")), this_object());
  if(arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  This is some sort of commons area in the middle of the orc encamp-\n\
ment.  Scraps of cloth and other trash are spread around a small camp\n\
fire.  To the north and south of you are small huts made out of wood\n\
and mud.  To the east is a gate leading out of the encampment.\n";
  items = ({
    "encampment", "The encampment consists of perhaps a dozen tents and several wooden buildings\n"+
                  "further up the side of the mountains is a temple of some sort that\n"+
                  "the orcs have taken over",
    "orcs",       "You can see a few orcs milling around inside the encampment",
    "bailey",     "The bailey is several hundred feet long and consists of tree trunks\n"+
                  "lashed together by leather ropes.  Primitive, but effective",
    "gate",       "The \"gate\" is merely a break in the bailey",
    "scraps",     "Orcs are not well known for their cleanliness",
    "cloth",      "Orcs are not well known for their cleanliness",
    "trash",      "Orcs are not well known for their cleanliness",
    "huts",       "They are poorly constructed, but servicable",
  });

  dest_dir = ({
    PATH+"camp3.c", "north",
    PATH+"camp5.c", "west",
    PATH+"camp1.c", "east",
    PATH+"camp4.c", "south",
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
