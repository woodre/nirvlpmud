/*
 *      File:                 /players/star/hotel/rooms/207.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               03/15/2006
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
    if(!present("jimmy"))
      move_object(clone_object(HOTEL+"npcs/jimmy.c"),this_object());
    if(!present("vito"))
      move_object(clone_object(HOTEL+"npcs/vito.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Room 207";
  long_desc =
    "   As luxurious as the other rooms in the hotel are, this one makes\n"+
    "them look like a Super 8.  This is the Overlook's Presidential Suite,\n"+
    "and it is at least twice the size of the other rooms.  Besides the\n"+
    "usual king-size bed and bedside table, this room contains an executive \n"+
    "desk.  Opposite the door is a large picture window that offers a\n"+
    "gorgeous view of the surrounding mountains.  There is a door in the\n"+
    "wall to the left that looks like it leads to the bathroom, but there\n"+
    "is something odd-looking about the wall next to it.\n";

  items =
  ({
    "bed",
    "The bed is huge, and looks quite soft.  It has been stripped of linens\n"+
    "for the off season",
    "table",
    "The bedside table is made of oak and has a drawer in the front of it",
    "bedside table",
    "The bedside table is made of oak and has a drawer in the front of it",
    "drawer",
    "This is a plain wooden drawer with a knob in the center",
    "knob",
    "This is a plain wooden knob one can use to open a drawer",
    "desk",
    "The desk is huge, looks like it is made out of cedar, and has been\n"+
    "completely cleared off for its next user when the hotel opens again\n"+
    "in the spring",
    "door",
    "One door leads back out to the hall, and through the other you can see\n"+
    "a small, neat bathroom",
    "window",
    "The window is at least six feet across.",
    "view",
    "The view through the window is of the surrounding mountains in all\n"+
    "their autumn glory",
    "wall",
    "There is something grey and red on the wall.  It looks like blood, a\n"+
    "lot of blood, and grey matter from someone's brain.  It is oozing and\n"+
    "running toward the floor.  But then you blink, and it's gone",
    "bathroom",
    "The bathroom is done in cream colors and is quite rich and tasteful",
  });
  dest_dir=
  ({
    HOTEL+"rooms/up_hall1.c",     "out",
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
