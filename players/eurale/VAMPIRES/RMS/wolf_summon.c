#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("rock")) {
  move_object(clone_object("players/eurale/VAMPIRES/OBJ/wolf_rock.c"),
      this_object()); }
  if(arg) return;
set_light(0);

short_desc = "Eerie forest";
long_desc =
  "  This is a strange place.  It's as if there is some kind of moving\n"+
  "forest surrounding you.  You can hear the muffled sound of growling\n"+
  "coming from the dark behind the trees and occasionally there is the\n"+
  "howl of a wolf nearby in the moving forest.\n";

items = ({
  "lettering","Something is carved into the back rock you might be "+
              "able to read",
  "forest","Large, forboding trees that seem to change places each\n"+
           "time you turn your back",
  "trees","Tall with thick canopys, they darken the ground beneath them",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/wolf_path.c","east",
});

}

realm() { return "NT"; }
