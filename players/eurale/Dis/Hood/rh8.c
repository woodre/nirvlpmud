#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("friar tuck")) {
  move_object(clone_object("players/eurale/Dis/Hood/NPC/tuck"),TO); }

  if(arg) return;
set_light(1);

short_desc = "King's Way";
long_desc =
	"  The pine trees have gotten much thicker here and much taller.\n"+
	"Just a little farther to the east is the beginning of what looks\n"+
	"to be a major forest.  The forest spreads out and extends nearly\n"+
	"as far as the eye can see.\n";

items = ({
	"trees","Spruce and fir mixed in with towering hardwoods",
	"forest","Towering and colorful hardwoods of all types",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh9.c","east",
	"players/eurale/Dis/Hood/rh7.c","west",
});

}

init() {
  ::init();
  add_action("east","east"); }

east() {
object ob;
  ob = present("friar tuck");
if (ob) {
  write("Friar Tuck stops you..\n");
    say("Sorry, can't let you by me....\n");
    return 1; }
}
