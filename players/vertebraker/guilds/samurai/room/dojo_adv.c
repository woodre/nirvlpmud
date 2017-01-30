#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(!present("pai mei")) {
    move_object(clone_object(OBJDIR+"paimei"), this_object());
  }
  if(arg) return;
  set_light(1);
  set_short("Dojo - Advancement Room");
  set_long("\
Dojo - Advancement\n\
A simple brown mat rests on the ground, decorated with yin-yang\n\
symbols. Bamboo shoots have been strategically placed around the\n\
corners of the room as a decorative touch.\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_shomen","north",
  });
}
