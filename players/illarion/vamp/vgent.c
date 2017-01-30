inherit "room/room";
#include "DEFS.h"

reset(arg) {
  if(arg) return;
  if(!present("board")) {
    move_object("/players/eurale/VAMPIRES/OBJ/app_board.c");  
  }
set_light(0);

short_desc = "Vampire Guild Entrance";
long_desc = "\
This large, circular room appears to have been cut from the solid rock\n\
of the cliff at the end of East Road.  At the north end of room, a large\n\
hold leads downward, and a smaller opening has been cut into the wall to\n\
the west.  A small sign is mounted on the wall just above the hole.\n";

items = ({
  "sign","A neatly printed sign for all to read",
  "hole","\
A neatly-carved hole with perfectly smooth sides, leading down into the\n\
darkness"
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
  HIR+"Vampire Guild Entrance - Guild Members Only!\n"+NORM);
  return 1; }
}
