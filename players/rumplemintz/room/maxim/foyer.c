/* ========================================================================== */
/*                                                                            */
/*   foyer.c                                                                  */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Entryway/Foyer inside Maxim's castle                                     */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types
#include "/obj/door.h"

inherit "room/room.c";
object obj_1, obj_2;

void reset(status arg) {
  if(arg) return;
  set_light(1);
  short_desc = "King Maxim's foyer";
  long_desc =
"     You are standing in the foyer of King Maxim's castle.  The vast\n"+
"room continues north almost like a hallway.  There are doors on either\n"+
"side leading east and west. There are various portraits hanging from\n"+
"walls, and suits of knight-like armor standing at attention.\n";
  items = ({
    "room", "It is obnoxiously large, spanning the entire first floor",
    "doors", "They lead east and west",
    "portraits", "Various portraits of people you don't recognize",
    "walls", "They are lined with portraits and empty suits of armor",
    "armor", "Empty suits of armor from various time periods",
    "suits", "Empty suits of armor from various time periods"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/room1","south",
    "/players/rumplemintz/room/maxim/foyer2","north",
    "/players/rumplemintz/room/maxim/east1","east",
    "/players/rumplemintz/room/maxim/west1","west"
  });
  /* Setup the doors - This sets the door for both rooms */
  MAKE_DOORS(
    "players/rumplemintz/room/maxim/foyer","east", /* Room 1 and exit direction */
    "players/rumplemintz/room/maxim/east1","west", /* Room 2 and exit direction */
    "broken", /* Type of lock - description */
    "maxim", /* Code of key */
    "This is a stone door.\n", /* long_desc of door */
    1, /* is_closed - boolean */
    0, /* is_locked - boolean */
    0  /* can_lock - boolean */
    );
  MAKE_DOORS(
    "players/rumplemintz/room/maxim/foyer","west",
    "players/rumplemintz/room/maxim/west1","east",
    "broken",
    "maxim",
    "This is a stone door.\n",
    1,
    0,
    0
    );
}
