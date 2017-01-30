#include "../defs.h"

inherit ROOM;

void
on_create()
{
  set_color(HIK);
  set_no_clean(0);
  set_short("A dark tunnel");
  set_long("This is a long, narrow tunnel dimly lit by long strips across its top.");
  add_desc("tunnel", "The workmanship is superb, no tool marks whatsoever on the walls.");
  add_desc("strips", "Long white strips that lie flush along the ceiling of the tunnel light this area dimly.");
  add_exit("south", RPATH+"tunnel1");
  add_exit("north", RPATH+"tunnel3");
}
