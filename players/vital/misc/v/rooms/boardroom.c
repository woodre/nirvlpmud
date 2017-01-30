#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("mirror")) {
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/guild_board"),
    this_object()); }
set_light(0);

short_desc = "Vampire Board Room";
long_desc =
  "Set against the wall is a large board to provide members of the family\n"+
  "a place to communicate with one another.  All around the room are metal\n"+
  "holders with candles in sconces to provide light.  A stone bench lines\n"+
  "the rear wall.\n";

items = ({
  "holders","Sturdy iron holders supporting large candles",
  "candles","Large, yellow wax candles, flickering",
  "bench","A thick stone bench to provide respite to travelers",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/titles","south",
  "players/eurale/VAMPIRES/RMS/vguild_hall","west",
});

}

realm() { return "NT"; }
