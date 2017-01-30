#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("sheriff")) {
  move_object(clone_object("players/eurale/Dis/Hood/NPC/sheriff"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Nottingham Castle";
long_desc =
	"  You stand in the rotunda of the castle in Nottingham.  King \n"+
	"Richard has gone off to the Crusades and Prince John has been \n"+
	"left in charge.  The stone walls are draped in rich tapestry \n"+
	"and there is a large picture hanging on the main wall.  To the\n"+
	"west is the King's audience room.\n";

items = ({
	"tapestry","Rich clothe done in the King's colors",
	"picture","King Richard in full battle armor",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh20.c","leave",
	"players/eurale/Dis/Hood/rh22.c","west",
});

}

init() {
  ::init();
  add_action("west","west"); }

west() {
object ob;
  ob = present("sheriff");
if(ob) {
  write("The Sheriff sneers: Not so fast my good man!\n");
  say("The Sheriff stops "+capitalize(TPRN)+" from entering.\n");
  return 1; }
}
