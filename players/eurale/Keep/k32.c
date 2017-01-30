#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("horax")) {
move_object(clone_object("players/eurale/Keep/NPC/horax"),TO); }
  if(arg) return;
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You are at the end of the tunnel. It looks as if whoever was\n"+
	"digging the tunnel gave up here.  The sides and floor are still\n"+
	"very rough.  The rocks that have fallen have left a small pocket\n"+
	"above your head, giving you just enough room to turn around to \n"+
	"to get out.\n";

items = ({
	"pocket","A tall hole in the roof of the tunnel that you might\n"+
		"be able to stand in",
});

dest_dir = ({
	"players/eurale/Keep/k31.c","out",
});

}

init() {
  ::init();
  add_action("stand","stand");
}

stand() {
  write("You slowly stand up wiggling into the pocket overhead.\n");
write("\n\n\n");
  TP->move_player("standing up#players/eurale/Keep/k33.c");
  return 1; }
