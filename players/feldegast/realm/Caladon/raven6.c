/*
File: raven6.c
Author: Feldegast
Date: 10/20/01
Description:
  Fourth floor of the tower of ravens in Caladon.
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Tower of Ravens"+NORM;
  long_desc=
"  At the top of the stairs is a large circular chamber with a marble\n\
dome capping it.  A plush red carpet covers the floor.  An archway\n\
leads north across a bridge.  The wall of the chamber is covered in a\n\
mural.\n";
  items=({
    "chamber", "reflexive",
    "dome", "This chamber is capped by a marble dome",
    "bridge", "The bridge leads over a deep chasm and to an archway which\n"+
              "opens into another room",
    "flights", "You fancy them",
    "stairs", "The marble staircase spirals down into the darkness",
    "marble", "The marble is black, with streaks of violet",
    "carpet", "It is a plush red velvet carpet",
    "mural", "The mural depicts a murder of ravens flocking around a mysterious\n"+
             "cloaked figure",
    "wall", "The mural depicts a murder of ravens flocking around a mysterious\n"+
             "cloaked figure",

  });
  dest_dir=({
    PATH+"raven8.c", "north",
    PATH+"raven4.c", "down",
  });
}

void init() {
  ::init();
  add_action("cmd_north", "north");
  add_action("cmd_jump", "jump");
  add_action("cmd_jump", "leap");
}

int cmd_north(string str)
{
  write("The bridge collapses beneath your feet as you attempt to cross it.\n"+
        "You plunge into the darkness.\n");
  say("The bridge collapses as "+TPN+" falls into the darkness.\n");
  TP->move_player("down#"+PATH+"raven7");
  call_out("upagain", 3);
  return 1;
}

void upagain()
{
  tell_room(this_object(), "The bridge pops back up again.\n");
}

int cmd_jump(string str)
{
  if(str != "across bridge" &&
     str != "over gap" &&
     str != "across gap" &&
     str != "across chasm" &&
     str != "over chasm" &&
     str != "over pit")
    return 0;
  if((int)TP->query_attrib("ste") > random(30))
  {
    write("You leap across the bridge.\n\n");
    TP->move_player("north#"+PATH+"raven8");
    return 1;
  }
  else return command("north", TP);
}
