#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Master's Hallway";
  long_desc=
	"You have ascended into the ante chamber of the "+HIC+"Spell Masters"+NORM+".  This\n"+
	"triangular room is the portal to the most powerful of Guild Masters.\n"+
	"The Spell Masters are responsible for "+MAG+"training"+NORM+" a Mage in the specific spheres\n"+
	"of magical powers and "+HIW+"teaching"+NORM+" new spells to aspiring Magi.  There are\n"+
	"doorways to the north, south and west.  The sound of soft piano music can\n"+
	"be heard to the north.  Dark foreboding shadows darken the southern door.\n"+
	"A sprial staircase leads down.\n";

  dest_dir=({
	ROOM_DIR+"yshir_room",		"north",
	ROOM_DIR+"ansari_room",		"west",
	ROOM_DIR+"dycedakis_room",	"south",
	ROOM_DIR+"masters_hall",	"down",
  });

}

query_mguild(){ return "Masters Hallway"; }

init(){
  ::init();
  if(!mage_check()) return;
  add_action("guild_move","gm");
}

