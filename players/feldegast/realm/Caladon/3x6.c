/*
File: 3x6.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/14/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=3; y=6;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Amid the forested hills of the barony of Caladon lies the legendary\n\
Healer Hall.  It is a large complex constructed of strong, solid\n\
stone and seems to have an orderly appearance.  The gates of the\n\
Hall are currently closed.  A dirt path leads east towards the city.\n";
  items=({
    "hills", "The rolling foothills of Caladon are dotted with trees",
    "hall", "The Hall is a sprawling compound surrounded by tall stone walls",
    "complex", "The Hall is a sprawling compound surrounded by tall stone walls",
    "gates", "The gates to the Healer Hall are currently closed",
    "path", "It leads east towards the city",
  });
  dest_dir=({
    PATH+"2x6.c", "west",
    PATH+"4x6.c", "east",
    PATH+"3x5.c", "south",
  });
}

void init()
{
  ::init();
  add_action("cmd_enter", "enter");
}

int cmd_enter(string str)
{
  if(str!="hall" && str!="gates")
  {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("The Healer Hall is currently closed.\n");
  return 1;

/*
  say(TPN+" enters the Healer Hall.\n");
  write("You enter the Healer Hall.\n");
  move_object(TP, "/players/feldegast/healers/rooms/center.c");
  command("look", TP);
  say(TPN+" enters the Healer Hall.\n");
  return 1;
*/
}
