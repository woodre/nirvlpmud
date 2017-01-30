#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(!present("board")) {
    move_object(clone_object(OBJDIR+"gc_board"), this_object());
  }
  if(arg) return;
  set_light(1);
  set_short("Dojo - Emperor's Chambers");
  set_long("\
The Dojo - Emperor's Chambers.\n\
Several large thrones sit in the middle of the room, awaiting\n\
the arrival of the Emperors of the Guild. These are the restricted\n\
chambers for the Guild Commanders to discuss potential recruits\n\
and the internal affairs of the guild.\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_sc","south",
  });
}
