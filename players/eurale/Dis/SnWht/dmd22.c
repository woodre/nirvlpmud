#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("snow white")) {
  move_object(clone_object("players/eurale/Dis/SnWht/NPC/snow"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Woodland cottage";
long_desc =
	"  As you step from the kitchen, you find yourself in what must \n"+
	"surely be a lady's bedroom.  The colors are light and airy and \n"+
	"there are flowers in a vase on the bedstand by the bed.  A mirror\n"+
	"hangs on the wall beside the bed.\n";

items = ({
	"bed","A large, comfortable bed with a hand-sewn quilt",
	"bedstand","A small wooden table, open underneath",
	"flowers","Beautiful flowers from the gardens",
	"mirror","A wooden framed mirror, about half length",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd23.c","south",
});

}
