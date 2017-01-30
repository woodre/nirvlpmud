/* Will document this shit later, prolly in separate file */

#include "defs.h"

inherit "/room/room.c";

void reset(status arg) 
{
  if (arg)
  {
    return;
  }

  short_desc = "Advanced Combat Testing Center";
  long_desc = "A better long description will go here later.\n";
  set_light(1);
  dest_dir = ({ "/room/vill_green", "green",
                "/players/earwax/workroom", "wax",
  });
}

void init()
{
  ::init();
}
