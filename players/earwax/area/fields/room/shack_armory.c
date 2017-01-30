#include "../defs.h"

inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("Guard Armory");
  set_long("This is the armory for the "+ENG+" Special Beano Control Detachment.  In one corner of the room lie some dusty racks.  The C.O.'s office is to the south.");
  add_exit("south", RPATH+"shack_office");
  add_desc("racks", "The racks might once have held weapons, it's hard to tell without disturbing the inch-thick dust.");
  add_desc("dust", "It's thick and gray, obviously high quality.");
  add_desc("racks", "The racks are covered in dust.");
  add_desc("corner", "Racks that may or may not have been used for storing weapons are in a corner of this room.");
}
