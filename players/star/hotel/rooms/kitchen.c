/*
 *      File:                 /players/star/rooms/kitchen.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/03/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
    if(!present("dick"))
      move_object(clone_object(HOTEL+"npcs/dick.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc = "The Overlook's Kitchen";
  long_desc =
  "   The Overlook's kitchen is large and every little sound echoes back\n"+
  "to you.  Along one wall are four huge refrigerators, and along the \n"+
  "opposite wall is a row of industrial-sized sinks.  There are two doors\n"+
  "in the wall opposite to the entry.  One of them looks like the door to\n"+
  "a walk-in freezer.  The space in between is filled with counters,\n"+
  "cutting blocks, and stoves.  An assortment of gleaming pans, from the\n"+
  "tiny to the huge, hangs from hooks on the ceiling.\n";

  items =
  ({
    "refrigerators",
    "These huge refrigerators look as if they can easily hold enough food\n"+ 
    "feed an army...or a hotel full of hungry guests",
    "sinks",
    "There are three giant sinks along the wall.  The signs above them\n"+
    "designate one for washing, one for rinsing, and one for sterilizing", 
    "wall",
    "The kitchen walls are a gleaming white color",
    "doors",
    "The two wide doors in the north wall look like they may lead into a\n"+
    "freezer and a pantry",
    "counters",
    "The huge counters in the middle of the room provide plenty of work\n"+
    "space",
    "blocks",
    "These look like the counters, but are made of wood and not topped\n"+
    "with any kind of Formica or tiles",
    "stoves",
    "The stoves in here are gigantic.  The smallest one has twelve burners",
    "pans",
    "The gleaming copper pans reflect your face back at you",
    "hooks",
    "Medium-sized metal hooks, used to hang pans from the ceiling",
  });
  dest_dir =
  ({
    HOTEL+"rooms/freezer.c",     "freezer",
    HOTEL+"rooms/pantry.c",      "pantry",
    HOTEL+"rooms/ballroom.c",    "south",
  });
}
