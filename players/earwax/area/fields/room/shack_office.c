#include "../defs.h"

inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("Guard Office");
  set_long("This is the office for the world-renowned "+ENG+" Special Beano Control Detachment.  The office itself is rather unimpressive, having only a desk and a clock on the wall.  There are doorways to the north, south, and west from here.  West would most likely take you to where you got here by going east from (go figure).");
  add_exit("west", RPATH + "shack_entrance");
  add_exit("north", RPATH + "shack_armory");
  add_exit("south", RPATH + "shack_oquarters");
  add_desc("clock", "It says it's lunch time.  All the time.");
  add_desc("desk", "There isn't much on it except scuffs from a pair of boots.");
  add_desc("scuffs", "They look like officer grade polish.");
}


void
on_reset()
{
  object ob;

  if (!present("lt", this_object()))
  {
    ob = (object)MOB_SETUP->make_lt();
    move_object(ob, this_object());
    say((string)ob->query_name()+" arrives.\n");
  }
}
