#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("katrina")) {
  move_object(clone_object("players/eurale/Dis/Slpy/NPC/kat"),TO); }
if(!present("baltus")) {
  move_object(clone_object("players/eurale/Dis/Slpy/NPC/baltrus"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Van Tassel Estate";
long_desc =
	"  You stand in the foyer of the Van Tassel estate.  The tile \n"+
	"floor and open ceiling make the room seem much larger than it\n"+
	"actually is.  Curved banister staircases lead up to the second\n"+
	"floor.\n";

items = ({
	"homested","A large house with a pillared front and two stories",
});

dest_dir = ({
	"players/eurale/Dis/Slpy/sl8.c","exit",
});

}
