#include "../defs.h"

inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A "+HIK+"Dirt"+NORM+NORM+HIG+" Road");
  set_long("A dirt road extends both north and south.  To each side of it are grassy fields, and a ways to the north is a castle.");
  add_exit("south", RPATH+"road1");
  add_exit("north", RPATH+"road3");
  add_exit("east", RPATH+"fields2");
  add_exit("west", RPATH+"fields7");
  add_desc("road", "It's a dirt road that shows signs of heavy travel.  It extends both to the north and south from here.");
  add_desc("castle", "It's a rather large castle replete with towers and high, stone walls.  There are a number of flags waving from the towers as well.");
  add_desc("walls", "They look like they are very thick.");
  add_desc("towers", "There are defensive towers at each corner of the castle walls, with flags flying from each.  There are also towers to either side of the drawbridge.");
  add_desc("drawbridge", "It appears to be up, but it's difficult to be sure at this distance.");
  add_desc("flags", "The standard of Earwax (a "+HIR+"red Q-Tip"+NORM+NORM+" on a "+HIK+"field of black"+NORM+NORM+") proudly waves from each tower.");
  add_desc("clearing", "There is a grass-covered clearing south of here.");
  add_desc("fields", "There are grassy fields to the east and west.");
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("corporal", this_object()) && random(100) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());
}
