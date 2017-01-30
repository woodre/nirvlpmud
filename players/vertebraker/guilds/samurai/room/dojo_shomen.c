#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(!present("board")) {
    move_object(clone_object(OBJDIR+"mboard"), this_object());
  }
  if(arg) return;
  set_light(1);
  set_short("Dojo - Shomen");
  set_long("\
Dojo - Shomen\n\
In the center of the room is a large kamidana.\n\
Kanban in the Shomen refer to the saying,\n\
\"The Dojo is the Mind\".\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_med","north",
    ROOMDIR+"dojo_heals","east",
    ROOMDIR+"dojo_adv","south",
    ROOMDIR+"dojo_foyer","west",
    ROOMDIR+"dojo_sc","up",
  });
}
