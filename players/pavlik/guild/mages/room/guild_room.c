#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Mage's Tower";
  long_desc=
	"Elaborate tapestries decorate the huge rounded walls of this level.\n"+
	"The spiral staircase leads both upwards and downwards from this\n"+
	"vantage.  A huge iron-wood door in the north wall leads to the Vault\n"+
	"Room and a smaller wooden door to the west will take you into the\n"+
	"Party Room.  A window in the east wall provides a breath-taking view\n"+
	"of the realms, although the picture can sometimes be obstructed by\n"+
	"clouds when looking from such a high vantage point as this.  There is\n"+
	"even a tiny telescope perched on the sill for viewing the stars at night.\n";

  items=({
    "window",
	"You gaze out the window onto the beautiful (?) landscape of Nirvana",
    "tapestries",
	"The huge woven tapestries depict strange magical beasts.  You have no\n"+
	"doubt that any mage could best these monsters in battle",
    "telescope",
	"The tiny telescope is for viewing pleasure of the midnight star-scape.\n"+
	"You put your eye to the lens and look out across the sky.  Little\n"+
	"points of light become huge fiery masses through the telescope\n"+
	"... So much for romanticism",
  });

  dest_dir=({
	ROOM_DIR+"vault_room", "north",
/*
	ROOM_DIR+"party_room", "west",
*/
	ROOM_DIR+"stairs1", "down",
	ROOM_DIR+"guild_room2", "up",
  });

}

query_mguild(){ return "Guild Room 1"; }

init(){
  ::init();
  if(!mage_check()) return;
  add_action("guild_move","gm");
}

