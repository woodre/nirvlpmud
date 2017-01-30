#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    This is the nurse's station on the third floor.  It is also\n"+
  "where information on newborn babies, born at the hospital can be\n"+
  "obtained.  Also there are several chairs and couches located here\n"+
  "for people waiting for a baby to be born. The hallway extends\n"+
  "from this room to the west.\n";
set_light(1);

items = ({
  "desk","This is the help desk.",
  "walls","The walls are a dull blue, with chairs lined against them.",
  "chairs","Several wooden chairs lined against the walls.",
  "hallways","Long sterilized hallways extend in the north,east,west directions.",
  "path","A small worn path leding to the southwest",
});

dest_dir = ({

  "/players/pestilence/hospital/room/3whall.c","west",
});
}
