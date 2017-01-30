#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(!present("samurai")) {
    move_object(clone_object(OBJDIR+"npc"), this_object());
  }
  if(arg) return;
  set_light(1);
  set_short("Dojo - Heal Shop");
  set_long("\
Dojo - Heal Shop\n\
A large counter wraps around the walls, with several stools\n\
alongside it. Wonderous paintings decorate the wall of past\n\
Samurai victories under Ieyasu Tokugawa.\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_shomen","west",
  });
}
