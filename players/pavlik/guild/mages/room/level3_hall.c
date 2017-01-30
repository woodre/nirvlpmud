#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Mage's Tower";
  long_desc=
	"You are in the Mage's Tower.  This small hallway leads to the residents\n"+
	"quarter of the Mage Tower.  There are heavy oak doors at both ends of\n"+
	"the hall.  A plush red carpet lines the floor, muffling the footsteps\n"+
	"of those who pass through here.\n";

  items=({
    "carpet",
	"The carpet is a very elaborate, very expensive import from the\n"+
	"eastern expanses.  The rug displays a myriad of colors that seem\n"+
	"to be almost hypnotizing if you stare at them too long",
    "door",
	"There are heavy iron doors to the north and south",
  });

  dest_dir=({
	ROOM_DIR+"guild_room3",		"south",
	ROOM_DIR+"mage_lobby",		"north",
  });

}

query_mguild(){ return "Hallway"; }

init(){
  ::init();
}

