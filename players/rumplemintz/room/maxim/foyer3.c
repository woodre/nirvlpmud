/* ========================================================================== */
/*                                                                            */
/*   foyer3.c                                                                 */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Northern end of foyer in King Maxim's castle                             */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types
#include "/obj/door.h"

inherit "room/room.c";
object obj_1, obj_2;

void reset(status arg){
  if(arg) return;
  set_light(1);
  short_desc = "Northern foyer in Maxim's castle";
  long_desc =
"     You are at the northern end of an enourmous foyer. There are\n"+
"tapestries that hang on the wall depicting King Maxim's reign and\n"+
"rise to power. There are doors that lead east and west, and the\n"+
"foyer continues to the south.\n";
  items = ({
   "foyer", "It is enourmous, you are at the northern end of it",
   "tapestries", "They show King Maxim in various battles",
   "doors", "They lead east and west"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/foyer2", "south",
    "/players/rumplemintz/room/maxim/east3", "east",
    "/players/rumplemintz/room/maxim/west3", "west"
   });
  MAKE_DOORS(
    "/players/rumplemintz/room/maxim/foyer3", "east",
    "/players/rumplemintz/room/maxim/east3", "west",
    "broken",
    "maxim",
    "This is a stone door.\n",
    1,
    0,
    0
  );
  MAKE_DOORS(
    "/players/rumplemintz/room/maxim/foyer3", "west",
    "/players/rumplemintz/room/maxim/west3", "east",
    "broken",
    "maxim",
    "This is a stone door.\n",
    1,
    0,
    0
  );
}
