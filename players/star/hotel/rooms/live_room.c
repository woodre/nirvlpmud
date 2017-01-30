/*
 *      File:                 /players/star/rooms/live_room.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/10/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
    if(!present("wendy"))
      move_object(clone_object(HOTEL+"npcs/wendy.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc = "The Caretakers Living Room";
  long_desc =
    "   The living room of the caretaker's apartment is small but\n"+
    "comfortable.  This winter's caretaker seems to have a family, as there\n"+
    "are toys scattered around the room here and there.  Each wall of the\n"+
    "square room contains a door.  From here it looks as if the one to the\n"+
    "north leads into a bathroom and the ones to the east and south lead\n"+
    "into bedrooms.  Of course the door in the west wall leads back into\n"+
    "the hallway.\n";

  items =
  ({
    "toys",
    "Watch your step.  There are toy soldiers and matchbox cars all over\n"+
    "the place",
    "door",
    "The doors are plain, white, and wooden",
    "wall",
    "The walls of this room are painted white like the hall to the west",
    "bathroom",
    "All you can see of the bathroom from here is part of the sink",
    "bedrooms",
    "The bedroom doors are only open a crack so not much is visible",
    "hallway",
    "The hallway to the west looks just as plain as it did when you were\n"+
    "there",
  });
  dest_dir =
  ({
    HOTEL+"rooms/apt_bath.c",     "north",
    HOTEL+"rooms/apt_bed1.c",     "east",
    HOTEL+"rooms/apt_bed2.c",     "south",
    HOTEL+"rooms/hallway2.c",     "west",
  });
}
