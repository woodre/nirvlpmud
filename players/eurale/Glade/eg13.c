#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  The river disappears into the ground here at the foot of a sheer\n"+
  "rock face.  The tall grass to the north seems to leave room for\n"+
  "the river to sneak through.  You can still see the river off to\n"+
  "west and it's raging waters are even angrier here before it dis-\n"+
  "appears into the earth.\n";

items = ({
  "grass","Tall, wide grass",
  "rock","Flat, smooth, gray rock going straight up.  Too steep to climb",
  "river","Boiling, angry green water flowing very fast",
});

dest_dir = ({
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("north","north");
  add_action("south","south");
  add_action("east","east");
  add_action("west","west");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

north() {
  tp->move_player("into the grass#players/eurale/Glade/eg14.c");
  return 1; }
south() {
  write("The river looks much too dangerous to enter here so you change\n"+
	"your mind.\n");
  return 1; }
east() {
  write("You peer straight up the rock face and decide it isn't worth\n"+
	"it to try to climb.\n");
  return 1; }
west() {
  tp->move_player("into the grass#players/eurale/Glade/eg12.c");
  return 1; }
