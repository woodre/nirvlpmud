#include "../defs.h"

inherit ROOM;


void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("Outside a Stone Building");
  set_long("To the west and north this grassy field continues.  The eastern and southern ends of this grass-covered valley end here, where mountains begin.  There is a large stone building here.");
  add_exit("north", RPATH+"fields3");
  add_exit("west", RPATH+"fields1");
  add_exit("enter", RPATH+"shack_entrance");
  add_desc("grass", "It's thick.");
  add_desc("fields", "Thick grass covers the fields here, and north and west of here.");
  add_desc("field", "Thick grass covers the fields here, and north and west of here.");
  add_desc("valley", "This is a large valley nestled in a mountain range.");
  add_desc("building", "It's made of thick stone, and has no windows.  You can "+HIW+"enter"+NORM+NORM+" it.");
  add_desc("mountains", "Immense mountains rise to the east and south of here.");
  add_desc("mountain", "Immense mountains rise to the east and south of here.");
  add_desc("mountain range", "Immense mountains rise to the east and south of here.");
  add_desc("range", "Immense mountains rise to the east and south of here.");
  add_desc("building", "It's a simple brick building.  Enter it to check it out.");
  add_desc("brick", "Yup, it's terra-cotta, alright.");
  if (!present("corporal", this_object())) move_object((object)MOB_SETUP->make_cpl(), this_object());
}
