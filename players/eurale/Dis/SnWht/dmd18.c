#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("sneezy")) {
  move_object(clone_object("players/eurale/Dis/SnWht/NPC/sneezy"),TO); }
if(!present("grumpy")) {
  move_object(clone_object("players/eurale/Dis/SnWht/NPC/grumpy"),TO); }


  if(arg) return;
set_light(0);

short_desc = "Diamond mine";
long_desc =
	"  You have reached the end of the tunnel.  Small pieces of the \n"+
	"rock wall still litter the floor waiting to be carted out.  Puddles\n"+
	"of standing water, green with slime, wait to be stepped in.\n";

items = ({
	"puddles","Dark, black water with floating slime",
	"pieces","Pieces of rock broken away by the pickaxe",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd17.c","up",
});

}
