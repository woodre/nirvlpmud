inherit "room/room";
#include "check.h"
#include "/players/eurale/defs.h"

reset(arg) {
  if(arg) return;
set_light(-2);

short_desc = HIR+"Nosferatu"+NORM+" Lounge";
long_desc = "\
Soft, comfortable couches and chairs are carelessly arranged about this\n\
exclusive room.  The floor is covered with a thick, blood-red carpet\n\
to muffle any ambient noise, and the walls are covered with rich mahogany\n\
paneling.  A fire burns merrily in a fireplace cut into the north wall.\n\
This welcoming place is where those Vampires who have attained the rank \n\
of "+HIR+"Nosferatu"+NORM+" meet to relax and to share tales of victory and defeat.\n";

items = ({
  "paneling","\
The wooden panelling is carved with scenes of fantastic creatures and\n\
great battles, and has been known to change when in the presence of an\n\
especially good story",
  "couches","\
The couches and chairs are worn but not worn-out, evidence of many\n\
evenings of the Family putting them to their intended use",
  "chairs","\
The couches and chairs are worn but not worn-out, evidence of many\n\
evenings of the Family putting them to their intended use",
  "couch","\
The couches and chairs are worn but not worn-out, evidence of many\n\
evenings of the Family putting them to their intended use",
  "chair","\
The couches and chairs are worn but not worn-out, evidence of many\n\
evenings of the Family putting them to their intended use",
  "floor","\
A soft, deep carpet, appropriately colored blood red",
  "fire","\
Close inspection reveals the fire gives off no actual heat or even light,\n\
instead being present merely for effect",
  "fireplace","\
A large stone fireplace, with a fire seemingly lit",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/lounge","west",
  "players/eurale/VAMPIRES/RMS/cafe.c","south",
});

}

realm() { return "NT"; }
