#include "../defs.h"

inherit ROOM;

void
on_init()
{
  add_action("show_sign", "read");
}

int
show_sign(string arg)
{
  if (query_verb() == "read" && arg != "sign")
  {
    notify_fail("What is it you're trying to read?\n");
    return 0;
  }

  write("\
Due to the ongoing building process, this castle is not open yet.\n\
-"+EACOE+".\n");
  return 1;
}

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("The End of a "+HIK+"Dirt"+NORM+NORM+HIG+" Road");
  set_long("A dirt road ends here, at the edge of a moat.  On the other side of the moat stands an enormous castle and to the south the dirt road continues.  To either side of the path grassy fields extend, and far to the east and west mountains define the borders of this valley.  There is a small sign here that can be read.");
  add_exit("south", RPATH+"road2");
  add_exit("east", RPATH+"fields5");
  add_exit("west", RPATH+"fields8");
  add_desc("road", "It's a dirt road.  It ends at the moat, and extends to the south.");
  add_desc("moat", "You can see all sorts of life moving around in it.  It looks dangerous.");
  add_desc("life", "All sorts of predatory water-life abound in the moat.");
  add_desc("castle", "The castle lies on the other side of the moat.  Its drawbridge is currently raised, which would leave the castle unaccessible at the moment.\n");
  add_desc("sign", "&show_sign");
  add_desc("towers", "Mighty towers rise from each corner of the castle as well as smaller ones on either side of the raised drawbridge.");
  add_desc("drawbridge", "The drawbridge is raised.");
  add_desc("fields", "They extend from each side of the road.");
  add_desc("mountains", "Tall mountains define the boundaries of this realm.");
  add_desc("valley", "You're in a valley in the middle of a group of huge mountains.");
  if (!present("corporal", this_object()) && random(100) <  CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());
}
