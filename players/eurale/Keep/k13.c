#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("disir 3")) {
move_object(clone_object("players/eurale/Keep/NPC/disir3"),TO); }
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The tunnel here has much better lighting, almost as if it \n"+
	"were leading to some place special.  The torches are larger\n"+
	"and there are more of them and you can hear a hissing kind of\n"+
	"of noise up ahead.\n";

items = ({
	"floor","Solid rock and smooth",
	"torches","Wooden handles with lighted, burning ends",
});

dest_dir = ({
	"players/eurale/Keep/k12.c","west",
	"players/eurale/Keep/k14.c","south",
});

}

init() {
  ::init();
  add_action("listen","listen");
  add_action("south","south");
  add_action("west","west");
}

listen(str) {
if(!str || str == "hissing") {
  write("The sound is too far off but it's definitely there.\n");
  return 1; }
}

south() {
if(present("disir")) {
  write("The disir steps in front of you blocking your way..\n");
  say("The disir steps in front of "+capitalize(TPRN)+"..\n");
  return 1; }
else {
  TP->move_player("south#players/eurale/Keep/k14.c");
  return 1; }
}

west() {
if(present("disir")) {
  write("The disir blocks your exit... and drools...\n"+
        "It growls: I've been waiting for a meal for some time..\n\n");
  say("The disir quickly blocks your retreat...\n");
  return 1; }
else {
  TP->move_player("west#players/eurale/Keep/k12.c");
  return 1; }
}
