#include "../defs.h"

inherit ROOM;

int
go_north(string arg)
{
  write("You emerge from the dark tunnel into a bright clearing.\n");
  this_player()->move_player("north#"+RPATH+"sanctuary");
  return 1;
}

void
on_create()
{
  set_color(HIK);
  set_no_clean(0);
  set_short("A dark tunnel");
  set_long("This is a long, narrow tunnel dimly lit by long strips across its top.  To the north the tunnel opens out into a lush green field.");
  add_desc("field", "It looks like the tunnel opens out into a grassy field.");
  add_desc("tunnel", "The workmanship is superb, no tool marks whatsoever on the walls.");
  add_desc("strips", "Long white strips that lie flush along the ceiling of the tunnel light this area dimly.");
  add_exit("south", RPATH+"tunnel2");
  add_exit("north", "&go_north");
}
