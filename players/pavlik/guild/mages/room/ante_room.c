#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Ante Chamber";
  long_desc=
	"This tiny ante-chamber is the entrance to the "+CYN+"Master's Quarters"+NORM+".  The\n"+
	"Masters of the Mages Tower both live and teach from within these walls.\n"+
	"The aura of ancient and powerful magic permeates every stone.  "+HIC+"Calador's\n"+NORM+
	"chambers are to the north.  A hallway to the west leads to the other Master's\n"+
	"quarters.  It is best not to intrude upon the Masters of the Tower unless you\n" +
	"have good reason to do so.\n";

  dest_dir=({
	ROOM_DIR+"masters_hall",	"west",
	ROOM_DIR+"advance_room",	"north",
	ROOM_DIR+"guild_room4",		"east",
  });

}

query_mguild(){ return "Ante Chamber"; }

init(){
  ::init();
  if(!mage_check()) return;
  add_action("guild_move","gm");
}

