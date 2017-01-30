#include "defs.h"
inherit ROOM;

void on_create() {
  set_area("area");
  set_short("Hallway in Earwax's Old Apartment");
  set_long("You're in a narrow hallways.  To the south is a bedroom, \
and north is a small bathroom.  You can continue through the hall to the \
east, or go back to the living room to the west.");
  add_exit("west",APTR+"living.c");
  add_exit("east",APTR+"kitchen.c");
  add_exit("north",APTR+"bath.c");
  add_exit("south",APTR+"m_bedr.c");
  add_desc("bathroom","Go north and check it out.");
  add_desc("bedroom","Go take a look.");
}
