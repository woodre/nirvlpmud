#include "defs.h"
inherit "room/room";

reset(arg) {
if(!present("barber")) {
  move_object(clone_object("players/eurale/Drygulch/NPC/barber"),TO); }
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
  "You stand in the Drygulch barbershop.  There is a single, swivel\n"+
  "chair in the center of the room.  Behind it, a long, oval mirror\n"+
  "atop a narrow shelf.  A large window takes up most of the south\n"+
  "wall and a small sign hangs above the door.\n";

items = ({
	"sign","The sign reads:  Haircut/Shave - 5 cents",
  "chair","A tiltable, swivel chair that the barber uses to give both\n"+
          "haircuts and shaves",
  "mirror","You see a reflection of yourself looking back from the\n"+
           "silver mirror",
  "shelf","A shelf holding a small mug with a handle sticking out of it",
  "mug","A soup mug for shaving with a brush to apply the lather",
  "window","A large, glass window overlooking the street and the only\n"+
           "stable in town",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs13.c","out",
});

}
