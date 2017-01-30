/*
 *      File:                 /players/star/rooms/apt_bath.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/29/2005
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
  short_desc = "The Caretaker's Bathroom";
  long_desc =
  "   There is barely enough room to turn around in this tiny bathroom.\n"+
  "The small space is lit by four round bulbs over the mirror.  Below the\n"+
  "mirror is an old chipped sink, and directly across from it is the\n"+
  "equally old toilet.  The entire wall opposite the door is taken up by\n"+
  "the bathtub.\n";

  items =
  ({
    "bulbs",
    "The lightbulbs are round, white, and all in a row",
    "mirror",
    "Looking into the mirror you see something incredibly ugly staring back\n"+
    "at you!  Oh wait...that's just your reflection",
    "sink",
    "The sink is white, and chipped in more than a few places",
    "toilet",
    "The old toilet is chipped and has a crack in the seat that could\n"+
    "easily pinch unsuspecting behinds",
    "wall",
    "The walls in here are white, and water stains show on the parts\n"+
    "nearest the tub",
    "tub",
    "The bathtub has a definate ring around the inside of it",
    "bathtub",
    "The bathtub has a definate ring around the inside of it",
  });
  dest_dir =
  ({
    HOTEL+"rooms/live_room.c",     "south",
  });
}
