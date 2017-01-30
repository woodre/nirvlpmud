#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("stfolk")){ 
    move_object(clone_object("players/softly/algiers/mobs/folks.c"),this_object());
  }

  if(arg) return;
  set_light(1);

  short_desc = "Algiers";
  long_desc ="\n\
At the end of a side road is a large industrial looking\n\
wooden building with a tin roof.  A few small open windows\n\
are high on the walls.  In the center of the wall facing the\n\
road is an open door.  The building looks as if it has not\n\
been used in a very long time.\n";

  items = ({
    "wall",
    "The wood planked front of an industrial building",
    "walls",
    "The building is faced with horizontal wooden planks", 
    "road",
    "The brown earthen road is very dusty",
    "building",
    "The building is made of broad unpainted wood planks placed\n\
horizontally, topped with a dull silver roof",
    "roof",
    "The roof is composed of large flat sheets of a silver metal", 
    "windows",
    "High on the sides of the building small narrow windows have\n\
been hacked into the sides of the building",
    "door",
    "The door is of the same unpainted wood as the walls of the\n\
building.  It is standing open",

  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road16.c","southwest",
    "/players/softly/algiers/rooms/mill.c","enter",
  });
}
