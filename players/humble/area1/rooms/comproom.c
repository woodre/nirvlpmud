/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIW+"Computer Room"+NORM;
    long_desc =
    "This is the room where all the high tech computers that\n"+
    "run the checkstands downstairs are kept.  There is a low\n"+
    "pitched buzzing noise here that you just can't escape.\n"+
    "Several columns of servers take up a lot of the space\n"+
    "here.  Nothing here draws your attention.\n";

    items =
    ({
    "server","This is a set of servers that runs the checkstands, lights and all other sorts of good stuff inside the store",
    "computers","A set of computers, the high tech ones without monitors and shit, Wow!",
    });
    dest_dir =
    ({
    RPATH+"office",        "out",
    });

    move_object(clone_object("players/humble/area1/mobs/gary.c"), this_object());
  }
}
