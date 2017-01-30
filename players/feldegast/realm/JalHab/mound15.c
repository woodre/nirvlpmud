#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  if(!arg)
  {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  This tunnel seems older than the other ones you have been through.\n\
The rock appears strangely melted, as though the sand and rock were\n\
melted rather than dug.  Strange, neatly spaced marks are scratched\n\
on the tunnel walls, almost as though it were writing.  The tunnel\n\
bends to the north and the west, so that it is impossible to see the\n\
tunnel's entire length.\n";
    items=({
      "tunnel", "The tunnel is about twelve feet in diameter and its surface\n"+
                "is smooth and melted",
      "rock", "It appears strangely melted",
      "sand", "The sand has turned to glass",
      "marks", "It appears to have some purpose to it, but you can't understand\n"+
               "what it means",
    });
    dest_dir=({
      PATH+"mound10.c","west",
      PATH+"mound16.c","northeast",
    });
  }
  if(!present("myrmidar") && random(2))
    move_object(clone_object(MON_PATH+"myrm-worker.c"),this_object());

}
