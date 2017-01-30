/*                                                                    *
 *    File:             /players/angel/area/town/land/land_01.c       *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           6/15/07                                       *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

inherit "/players/earwax/housing/land";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIB+"Country Lot 1"+NORM;
  long_desc =
"  This is a 20 acre lot. It is a large corn field off of\n\
HW 35 near I-69. The corn fields extends in all directions\n\
as far as the eye can see. The air is clean and at night the\n\
sky is clear. Most nights the stars fill the sky.\n";

  items =
  ({
  "corn",
  "The corn on the stalks are ready to be harvested. They are a\n\
fresh green color with ripe silk interior!",
  "lot",
  "This is a piece of land with a wonderful view", 
  "stars",
  "They light up the night sky with their twinkling",
  "sky",
  "It is clear and full of stars",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/hw_354", "highway",
  });
/*
  set_cost(500000);
  set_realm_name("Gas City");
  set_lot_size(9);
  setup_land();
*/  
}

init() {
  ::init();
    add_action("cmd_smell","smell");
}

cmd_smell(str) {
  write("You smell the fresh country air.\n");
  return 1;
}