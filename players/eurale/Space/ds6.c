#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("messenger")) {
  move_object(clone_object("players/eurale/Space/NPC/mess6"),TO); }
set_light(0);

short_desc = "Deep Space";
long_desc =
  "  You are standing at the bottom of a "+RED+"red crater"+NORM+".  It is dark and \n"+
  "you cannot make out anything more than a few feet away.  The air,\n"+
  "which should be damp and calm, has a quality to it that makes you\n"+
  "think that you are not alone.....\n";

items = ({
});

dest_dir = ({
	"players/eurale/Space/ds5.c","up",
});

}

init() {
  ::init();
  add_action("east","east");
  add_action("west","west");
  add_action("south","south");
}

east() {
  this_player()->move_player("darkness#players/eurale/Space/ds9.c");
  return 1; }

west() {
  this_player()->move_player("darkness#players/eurale/Space/ds8.c");
  return 1; }

south() {
  this_player()->move_player("darkness#players/eurale/Space/ds7.c");
  return 1; }
