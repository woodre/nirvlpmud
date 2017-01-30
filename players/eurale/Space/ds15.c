#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("aartuk")) {
  move_object(clone_object("players/eurale/Space/NPC/aartuk1"),TO); }
set_light(0);

short_desc = "Deep Space";
long_desc =
  "  You manage to squeeze yourself into the dark, cramped tunnel and\n"+
  "work your way to what appears to be the end.  This confined space\n"+
  "provides no room to stand or move about.  You'll have to back out\n"+
  "if you want to leave\n";

items = ({
});

dest_dir = ({
	"players/eurale/Space/ds14.c","out",
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("west","west");
}

search() {
  write("You feel forward toward the end of the tunnel and discover \n"+
	"that it actually makes a turn to the west but it's concealed\n"+
	"by the darkness.\n");
  return 1; }

west() {
  this_player()->move_player("tunnel#players/eurale/Space/ds16.c");
  return 1; }
