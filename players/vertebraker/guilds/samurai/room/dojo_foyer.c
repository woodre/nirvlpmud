#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  set_short("Dojo - Foyer");
  set_long("\
Dojo - Foyer\n\
The private entrance to the west leads back out to the overgrown\n\
Japanese forest. To the east, you see the Shomen. Kanban on the\n\
walls are decorated with beautiful paintings of samurai in\n\
various forms of combat.\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_shomen","east",
    ROOMDIR+"1","west",
  });
}
