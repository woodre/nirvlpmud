/*
 *      File:                 /players/star/hotel/rooms/209.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               03/12/2006
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
    if(!present("charlie"))
      move_object(clone_object(HOTEL+"npcs/charlie.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Room 209";
  long_desc =
    "   This hotel room is quite lavish.  The carpet under your feet is so\n"+
    "thick it feels like you will sink in to your ankles.  There is a large\n"+
    "king-size bed in the center of one wall with a nightstand next to it.\n"+
    "A lamp sticks out from the wall above the bed and a picture hangs on\n"+
    "the opposite wall.  Through a door across from the room entrance a\n"+
    "small bathroom can be seen.\n";

  items =
  ({
    "carpet",
    "The carpet is a nice calming shade of blue",
    "bed",
    "The bed is huge, and looks quite comfortable, though it is not made up\n"+
    "right now",
    "wall",
    "The walls are painted a cream color",
    "nightstand",
    "The nightstand looks to be made of oak and has a drawer in it",
    "drawer",
    "This is a plain wooden drawer with a knob in the center",
    "knob",
    "This is a plain wooden knob one can use to open a drawer",
    "lamp",
    "The lamp is a replica of an old fashioned oil lamp",
    "picture",
    "This is a picture of a bowl of fruit.  Yum!",
    "door",
    "There are two doors.  One leads out of the room and through the other\n"+
    "is a small, clean bathroom",
    "bathroom",
    "The bathroom is tiled in light blue and is sparkling clean",
  });
  dest_dir =
  ({
    HOTEL+"rooms/up_hall2.c",     "out",
  });
}

void init()
{
  ::init();
  add_action("cmd_enter", "enter");
  add_action("cmd_open", "open");
}

int cmd_enter(string str)
{
  if(!str)
  {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "bathroom" && str != "the bathroom")
  {
    notify_fail("The only thing here you can attempt to \"enter\" is the \"bathroom\".\n");
    return 0;
  }

  write("You can not enter that.\n");

  return 1;
}

int cmd_open(string str)
{
  if(!str)
  {
    notify_fail("Open what?\n");
    return 0;
  }
  if(str != "drawer" && str != "the drawer")
  {
    notify_fail("You can only \"open\" the \"drawer\".\n");
    return 0;
  }

  write("It is empty.\n");

  return 1;
}
