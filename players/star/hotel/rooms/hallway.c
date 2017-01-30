/*
 *      File:                 /players/star/rooms/hallway.c
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
  if(arg) return;
  set_light(1);
  short_desc = "A Hallway";
  long_desc =
  "   This hallway is very plain, with white walls and a blue carpet that\n"+
  "has some kind of squiggly black pattern.  It is a narrow hallway, and\n"+
  "so drab that it almost does not seem to be part of the rest of the \n"+
  "hotel.  The hallway extends to the east toward a door, and the lobby\n"+
  "opens out to the west, almost like another, much fancier, world.\n";

  items =
  ({
    "walls",
    "The walls are white and boring",
    "carpet",
    "The carpet is thick, and by far the nicest thing in the hall",
    "pattern",
    "The pattern isn't anything special, just squiggly black lines",
    "door",
    "The door is as white and boring as the walls",
    "lobby",
    "The lobby looks lush and inviting compared to this plain hall",
  });
  dest_dir =
  ({
    HOTEL+"rooms/hallway2.c",     "east",
    HOTEL+"rooms/lobby.c",        "west",
  });
}
