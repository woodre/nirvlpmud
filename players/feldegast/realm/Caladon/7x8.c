/*
File: 7x8.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/15/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=7; y=8;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Here, in the middle of the woods, the trees open up for a small\n\
clearing in which a sinkhole has formed.  A tall birch tree has fallen\n\
halfway into the sinkhole, allowing an easy descent.\n";
  items=({
    "woods",    "The surrounding foothills are densely covered in trees",
    "trees",    "The surrounding foothills are densely covered in trees",
    "clearing", "reflexive",
    "sinkhole", "The sinkhole is roughly ten meters wide and descends into darkness.\n"+
                "A tree has fallen into the hole and provides an easy way to descend",
    "tree",     "The dead tree has been uprooted at the edge of the sinkhole and descends"+
                "into it at a forty-five degree angle",
  });
  dest_dir=({
    PATH+"7x9.c", "north",
    PATH+"6x8.c","west",
    PATH+"8x8.c","east",
    PATH+"7x7.c","south",
  });
}

void init()
{
  ::init();
  add_action("cmd_enter", "descend");
  add_action("cmd_enter", "climb");
}

int cmd_enter(string str)
{
  if(query_verb() == "climb" &&
     str!="down" &&
     str!="into hole" &&
     str!="down into hole" &&
     str!="down into sinkhole" &&
     str!="into sinkhole")
  {
    notify_fail("Climb what?\n");
    return 0;
  }
  say(TPN+" descends into the sinkhole.\n");
  write("You descend into the sinkhole.\n");
  move_object(TP, PATH+"cave3.c");
  command("look", TP);
  say(TPN+" descends into the sinkhole.\n");
  return 1;
}
