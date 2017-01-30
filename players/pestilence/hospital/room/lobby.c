#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    This is the main entrance to the hospital.  It is also \n"+
  "known as the lobby.  There is a desk near the middle\n"+
  "of the room.  Many chairs line the walls for people who\n"+
  "are waiting for patients or just waiting in general.  Hallways\n"+
  "extend from this room to the west.  Out leads back to the\n"+
  "parking lot.\n";
set_light(1);

items = ({
  "desk","This is the help desk.",
  "walls","The walls are a dull blue, with chairs lined against them.",
  "chairs","Several wooden chairs lined against the walls.",
  "hallways","Long sterilized hallways extend in the north,east,west directions.",
  "path","A small worn path leding to the southwest",
});

dest_dir = ({

  "/players/pestilence/hospital/room/whall.c","west",
  "/players/pestilence/hospital/room/parkinglot.c","out",
});
}
