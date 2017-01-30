inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/entrance.c       *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           06/15/07                                      *
 *    Notes:            Entrance                                      *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

#include "/players/angel/area/stargate/obj/dial_obj.c"


reset(arg)
{
  /* the computer displays where players can travel */
  if(!present("dhd"))
     move_object(clone_object("/players/angel/area/stargate/obj/dhd"), this_object());
if(arg) return;
  set_light(1);
  short_desc = "Nox Homeworld Stargate";
  long_desc =
"    ~ Entrance of Nox Homeworld ~\n\
  This is the heavily wooded forest of the Nox, lightly\n\
populated by the Nox and their mysterious allies. Evil strangers\n\
are frowned upon here, so be on your guard. It is rumored that\n\
many different races of Nox actually inhabit the various parts of\n\
this forest and are usually are carefully hidden, away from the\n\
prying eyes of strangers. The Stargate can be seen to the south.\n";

  items =
  ({
    "trees",
    "Giant red wood trees that look to be over 100 years old",
	"tree",
    "A giant red wood tree that looks to be over 100 years old",
    "forest",
    "Many large trees and shrubs clumped together",
    "stargate",
    "The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving Stargate which then reconstructs\n\
     the matter in its original form",
     "shrubs",
     "Small red bushy leaves with an array of beautiful blooms\n\
which look siminular to Crape myrtles",
	 "dhd",
     "You should try to 'view dhd'",
     "DHD",
     "You should try to 'view dhd'",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f02.c",   "north",
  });
}
