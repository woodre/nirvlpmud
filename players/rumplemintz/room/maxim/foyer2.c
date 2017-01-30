/* ========================================================================== */
/*                                                                            */
/*   foyer2.c                                                                 */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   2nd part of foyer in King Maxim's castle                                 */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types
#include "/obj/door.h"

inherit "room/room.c";
object obj_1, obj_2;

void reset(status arg){
  if(arg) return;
  set_light(1);
  short_desc = "Middle foyer in King Maxim's castle";
  long_desc =
"     You are in the middle of a vast foyer that continues to the north\n"+
"and south. You can see the sky through a dome style window in the\n"+
"ceiling.  Beams of light shine down and make the floor shine like it\n"+
"was just cleaned with a mop. There are doors on both that lead east\n"+
"west. In the center of the room, a spiral staircase leads down.\n";
  items = ({
    "window", "A magnificent window in the ceiling",
    "sky", "You can see the sky through the window",
    "beams", "Light shines down through the window and reflects off the floor",
    "floor", "It shimmers like it was freshly mopped",
    "doors", "They lead east and west",
    "staircase", "It leads down"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/foyer", "south",
    "/players/rumplemintz/room/maxim/foyer3", "north",
    "/players/rumplemintz/room/maxim/east2", "east",
    "/players/rumplemintz/room/maxim/west2", "west",
    "/players/rumplemintz/room/maxim/lower1", "down"
  });
  MAKE_DOORS(
    "/players/rumplemintz/room/maxim/foyer2", "east",
    "/players/rumplemintz/room/maxim/east2", "west",
    "broken",
    "maxim",
    "This is a stone door.\n",
    1,
    0,
    0
  );
  MAKE_DOORS(
    "/players/rumplemintz/room/maxim/foyer2", "west",
    "/players/rumplemintz/room/maxim/west2", "east",
    "broken",
    "maxim",
    "This is a stone door.\n",
    1,
    0,
    0
  );
}
