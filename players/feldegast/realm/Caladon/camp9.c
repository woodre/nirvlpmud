/*
File: camp9.c
Author: Feldegast
Date: 03/16/02
Description:
  An orc camp.  In the temple.
  Note to self: Orc mage goes here.
*/

#include "defs.h"

inherit ROOM;

int flag;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  At one time, this temple was devoted to the Allandrian Goddess\n\
known as the Maiden, patron of beauty and love.  The temple has been\n\
defiled by the orcs, who have taken its fine silks and turned them\n\
into blankets, and melted down its golden statues to adorn their\n\
weapons.  An archway leads back out to the east, while a door leads\n\
south.\n";
  items = ({
    "temple",     "reflexive",
    "archway",    "The archway is three meters high and two wide.  It leads back outside",
    "door",       "The door barely hangs on its hinges.  A small room lies beyond",
  });

  dest_dir = ({
    PATH+"camp8.c", "east",
    PATH+"camp10.c", "south",
  });

}

void init()
{
  ::init();
  add_action("cmd_block", "south");
  add_action("cmd_search", "search");
}

int cmd_block(string str)
{
  if(present("orc") && (string)TP->query_race() != "orc")
  {
    write("The orc blocks your way.\n");
    return 1;
  }
}

int cmd_search(string str)
{
  if(present("orc"))
  {
    write("The orc blocks your way.\n");
    return 1;
  }

  if(flag)
  {
    write("You find nothing.\n");
    return 1;
  }

  write("Miraculously, you discover a golden symbol hidden beneath some rubble.\n");
  say(TPN +" searches around.\n");
  move_object(clone_object(OBJ_PATH+"symbol.c"), this_object());
  flag = 1;
  return 1;
}
