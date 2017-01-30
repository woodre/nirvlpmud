#include "/players/eurale/defs.h"
inherit "room/room";
int mv;

reset(arg) {
if(!present("warrior")) {
move_object(clone_object("players/eurale/Keep/NPC/shadow_warrior"),TO); }
  if(arg) return;
mv = 0;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The steps stop here.  It appears the tunnel used to go off\n"+
	"to both the east and south but rocks have fallen an filled in\n"+
	"the tunnel to the east.  Light is coming from the tunnel to\n"+
	"to the south.\n";

items = ({
	"rocks","Pieces of rock from the tunnel ceiling that you could\n"+
		"probably remove if you tried",
});

dest_dir = ({
	"players/eurale/Keep/k30.c","down",
	"players/eurale/Keep/k35.c","south",
});

}

init() {
  ::init();
  add_action("remove","remove");
  add_action("east","east");
  add_action("south","south");
}

remove(str) {
if(!str) { write("Are you trying to remove something?\n"); return 1; }
if(str == "rocks") {
  write("With a great deal of effort, you clean a hole through the\n"+
	"fallen rocks to the east...\n");
  say(capitalize(TPRN)+" moves some of the fallen rocks..\n");
  mv = 1;
  return 1; }
}

east() {
if(mv == 0) {
  write("The tunnel has been made impassible by the fallen rocks..\n");
  return 1; }
if(mv == 1) {
  write("You squeeze through the hole in the rocks the east..\n");
  say(capitalize(TPRN)+" squeezes through the rocks to the east..\n");
  this_player()->move_player("east#players/eurale/Keep/k32.c");
  return 1; }
}

south() {
if(present("warrior")) {
  write("The warrior lowers his shadowstaff and stops you...\n");
  say("The warrior stops "+capitalize(TPRN)+" with his shadowstaff...\n");
  return 1; }
if(!present("warrior")) {
  this_player()->move_player("south#players/eurale/Keep/k35.c");
  return 1; }
}
