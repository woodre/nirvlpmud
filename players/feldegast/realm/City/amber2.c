/*
File: amber2.c
Author: Feldegast
Date: 04/09/02
Description:
  Amber street
*/

#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Amber street descends at a steap angle down from the hills to the\n\
river to the south.  The houses that line the street are all well-\n\
made, but many have fallen into disrepair.  Amber street was once a\n\
prosperous neighborhood, but now has a sense of decay about it.  At\n\
the end of Amber street an abandoned cathedral dominates the cityscape.\n";
  items=({
    "amber street", "reflexive",
    "hills", "The street descends at a steep angle and with few zig-zags down\n"+
             "the hills to the river to the south",
    "houses", "Many of the houses have fallen into disrepair, but none of them\n"+
              "appear to be of interest to you",
    "neighborhood", "The neighborhood is scarcely inhabited and the few inhabitants scurry\n"+
                    "quickly about their business",
    "cathedral", "The abandoned cathedral is of gothic architecture and has a tarnished\n"+
                 "appearance.  It is the center of the malignancy that grips this part\n"+
                 "of the city",
  });
  dest_dir=({
    PATH+"amber1.c","north"
  });
}   

void init()
{
  ::init();
  add_action("cmd_enter", "enter");
}

int cmd_enter(string str)
{
  if(str!="cathedral")
  {
    notify_fail("Enter what?\n");
    return 0;
  }

  write("You enter the cathedral.\n");
  say(TPN+" enters the cathedral.\n");
  move_object(TP, PATH+"dark.c");
  say(TPN+" enters the cathedral.\n");
  command("look", TP);
  return 1;
}
