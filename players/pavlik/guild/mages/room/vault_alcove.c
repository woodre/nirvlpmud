#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=HIY+"Vault "+NORM+YEL+"Alcove"+NORM;
  long_desc=
	"This alcove is a tiny room hidden in the shadows of the Mage's Vault.\n"+
	"Members of the guild can leave items here that they plan to come back\n"+
	"for later.  Please DO NOT take any items from here other than your own\n"+
	"without permission.\n"+
	"Water slowly drips from a crack on the ceiling.\n";

  items=({
    "ceiling",
	"A tiny fracture disrupts the smooth surface of the ceiling.  Droplets of water\n"+
	"cling to the surface until they grow to heavy and plummet to the floor.\n" +
	"There is something strange about this water ... ",
  });

  dest_dir=({
	ROOM_DIR+"vault_room",		"east",
  });

}

query_mguild(){ return "Alcove"; }

init(){
  ::init();
  if(!mage_check()) return;
  add_action("guild_move","gm");
}

