#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Master's Hallway";
  long_desc=
	"This simple hallway provides access to the most powerful Magi in Nirvana.\n"+
	"It is here that the Guild Masters of the Mages Tower live, work and teach.\n"+
	"A door to the south leads to the simple chambers of Buepaya and another door\n"+
	"to the north leads to Jhavostrahd's personal library.  A spiral staircase\n"+
	"leads upwards to more chambers.\n";

  dest_dir=({
	ROOM_DIR+"buepaya_room",	"south",
	ROOM_DIR+"jhavostrahd_room",	"north",
	ROOM_DIR+"ante_room",		"east",
	ROOM_DIR+"spell_masters",	"up",
  });

}

query_mguild(){ return "Masters Hallway"; }

init(){
  ::init();
  if(!mage_check()) return;
  add_action("guild_move","gm");
}


