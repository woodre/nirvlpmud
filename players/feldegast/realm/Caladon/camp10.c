/*
File: camp10.c
Author: Feldegast
Date: 03/16/02
Description:
  An orc camp.  In the temple.
  Note to self: Loot goes here.
*/

#include "defs.h"

inherit ROOM;

int found;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  no_clean = 1;
  short_desc=AREANAME;
  long_desc=
"  This is a small room whose original purpose has been lost.  The\n\
room's furnishings have been chopped up and used for firewood.  A\n\
fireplace is all that remains.\n";
  items = ({
    "room",      "The room is four meters wide and six deep",
    "fireplace", "The fireplace is carved with elaborate designs and motifs in dedication\n"+
                 "to the Maiden.  It is filled with ash and soot, and does not appear to\n"+
                 "have been cleaned since before the temple fell",
  });

  dest_dir = ({
    PATH+"camp9.c", "north",
  });

}

void init()
{
  ::init();
  add_action("cmd_search", "search");
}

int cmd_search(string str)
{
  if(str!="fireplace" && str!="ash" && str!="soot" && str!="fire")
  {
    write("You find nothing.\n");
  }
  else
  {
    if(!found)
    {
      write("You find an amulet hidden in the ashes of the fireplace.\n");
      say(TPN+" searches the fireplace.\n");
      if(!TP->add_weight(1))
        write("It is too heavy for you to bear.\n");
      else
      {
        move_object(clone_object(OBJ_PATH+"mlocket.c"),TP);
        found = 1;
      }
    }
  } 
  return 1;
}
