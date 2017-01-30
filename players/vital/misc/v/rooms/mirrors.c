#include "/players/eurale/closed/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("mirror")) {
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/crystalball"),
    this_object()); }
set_light(0);

short_desc = "Vampire Dressing Room";
long_desc =
  "A small, octagonal room. It is shielded from the main vampire guild\n"+
  "hall so that family members can equip and make sure they're present-\n"+
  "able before venturing forth. A large, grey crystal ball provides a\n"+
  "the room with an interesting centerpiece.\n";

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/equip","east",
});

}

realm() { return "NT"; }
