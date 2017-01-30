#include "def.h"

inherit MYROOM;

reset(arg) {
  object door;
  if(!present("stranger"))
    move_object(clone_object(PATH+"Npc/mrwall"),this_object());
  if (arg) return;

/* Clone the generic door object */
  door=clone_object(DOOR);
  door->add_id("door");
  door->set_open_desc("A metal door, painted black, with a worn out handle and a lock.\n"+
                      "Somehow it seems out of place.  ");
  door->set_close_desc("A metal door, painted black, with a worn out handle and a lock.\n"+
                      "Somehow it seems out of place.  ");
  door->set_key(KEY);
  door->set_locked(1);
  door->set_difficulty(12);
  door->set_destination(PATH+"ug1.c");
  move_object(door,this_object());

  set_pk(1);
  set_light(0);
  short_desc="An Alley";
  long_desc=
"     Shadows thankfully obscure most of the trash that litters this\n\
alley that bends around behind a tall office building.  It ends in a\n\
brick wall that is marred only by a simple door that seems out of\n\
place.\n";
  items=({
    "shadows","There is a street lamp just outside the alley, but\n"+
              "it cannot seem to penetrate the thick shadows of\n"+
              "this city",
    "trash","You can't see it through the shadows",
    "street","A crowded street thick with cars",
    "building","A tall office building",
  });
  dest_dir=({
    PATH+"street8","east"
  });
}   
