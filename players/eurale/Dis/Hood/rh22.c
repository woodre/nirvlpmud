#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("john")) {
  move_object(clone_object("players/eurale/Dis/Hood/NPC/pjohn"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Nottingham Castle";
long_desc =
	"  A long red runner leads from the rotunda to the base of the\n"+
	"platform where the throne-like chair is.  The walls are well-\n"+
	"lit by large candles in sconces showing off prizes won in battle.\n"+
	"There are two smaller chairs to either side of the Kings for \n"+
	"his advisors to sit.\n";

items = ({
	"chair","A stuffed, comfortable chair done in wine-colored velvet",
	"prizes","Armor and weapons of vanquished foes as well as pieces\n"+
		"of the local history of the area",
	"candles","Large candles with big wicks",
	"runner","A red-velvet welcome for guests",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh21.c","east",
});

}
