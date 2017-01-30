inherit "room/room";
#include "DEFS.h"

reset(arg) {
  if(arg) return;
if(!present("board")) {
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/app_board.c"),TO); }
set_light(0);

short_desc = "Vampire Guild Entrance";
long_desc =
  "Cut into the solid, black rock is a circular room.  A large, irregular\n"+
  "hole in the floor leads down into the darkness below.  Another opening\n"+
  "has been cut into the stone wall to the west.  There is a small sign\n"+
  "attached to the wall just above the opening in the floor.\n";

items = ({
  "sign","A neatly printed sign for all to read",
  "hole","A black hole chiseled into the floor with the edges smoothed\n"+
         "from constant use",
  "darkness","Nothing is visible in the blackness below",
  "opening","A door of some kind",
});

dest_dir = ({
  "room/eastroad5","south",
  "players/eurale/VAMPIRES/RMS/cafe","west",
  "players/eurale/VAMPIRES/RMS/vguild_hall","down",
});

}

init() {
  ::init();
  add_action("Down","down");
  add_action("read","read");
}


Down() {
if(!present("vampire fangs",TP)) {
  write(HIR+
    "A voice from below whispers, 'Only the children of the night\n"+
    "may come down to the darkness below... Be gone with you!'\n"+NORM);
  return 1; }
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign") { write(
  "The sign reads:\n"+
  HIR+"Vampire Guild Entrance - Authorized Only!\n"+NORM);
  return 1; }
}
