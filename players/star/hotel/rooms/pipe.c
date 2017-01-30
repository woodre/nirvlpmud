/*
 *      File:                 /players/star/rooms/pipe.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/02/2006
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
    if(!present("ghost"))
      move_object(clone_object(HOTEL+"npcs/boy_ghost.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc = "A Dim Pipe";
  long_desc =
  "   As you hunch over to fit in this pipe you notice just how small it\n"+
  "is in here.  The pipe itself is rather large, but just under half of\n"+
  "its diamter has been buried in the ground.  Weak light filters through \n"+
  "the half circles on either end of the long tunnel, and dead leaves and\n"+
  "wood chips crunch under your feet.  It almost feels like you are being\n"+
  "watched, giving you an extreme case of the heebie-jeebies.\n";

  items =
  ({
    "pipe",
    "The inside curve of the pipe is plain, unpainted concrete",
    "ground",
    "The ground is covered in wood chips and dead leaves",
    "leaves",
    "These leaves have been dead for some time and have lost their vibrant\n"+
    "colors.  They are just plain"+YEL+" brown"+NORM,
    "chips",
    "The thick layer of wood chips is enough to cushion any falls",
    "wood chips",
    "The thick layer of wood chips is enough to cushion any falls",
  });
  dest_dir =
  ({
    HOTEL+"rooms/playground.c",     "out",
  });
}
