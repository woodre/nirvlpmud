/*                                                                            *
 *      File:             /players/angel/area/town/room/hw_351.c              *
 *      Function:         room                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!present("new sign"))
     move_object(clone_object("/players/angel/area/town/obj/sign_02"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Highway 35";
  long_desc =
"    "+HIC+"HW 35"+NORM+"\n\
  Highway 35 stretchs three miles into Gas City. Gas City's physical\n\
features consist of rolling prairies that drain to the Mississenwa\n\
River, and the area is one-fourth forested.  Much of the vegetation\n\
consists of cultivated farms and pasture land.  The large James Dean\n\
historical museum is seen off to the east of the Highway.  There is a\n\
Welcome sign to the right as you enter towards town. There are gas\n\
stations to the north and south.\n";

  items =
  ({
  "prairies",
  "An area of open rolling grassy land",
  "river",
  "The water is fast flowing and crystal clear",
  "farms",
  "These farms are filled with mile of corn stalks",
  "pasture land",
  "An area of the farm where the cows and pigs live",
  "land",
  "An area of the farm where the cows and pigs live",
  "pasture",
  "An area of the farm where the cows and pigs live",
  "stations",
  "A small business that sell gas",
  "station",
  "A small business that sell gas",
});
  dest_dir =
  ({
    "/players/angel/area/town/room/foyer",    "east",
    "/players/angel/area/town/room/hw_352",   "west",
  });
}
