#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  You have come to a small clearing deep in the tall grass.  Before\n"+
  "you, hidden by dense thorn bushes is a small, dark opening in the\n"+
  "rocky earth.  The tall grasses make this a nearly invisible place.\n";

items = ({
  "grass","Tall, wide grass",
  "grasses","Tall, wide, swaying grass",
  "opening","I appears to be the opening to a cave or tunnel of some\n"+
	    "kind.  Maybe you could enter it.\n",
});

dest_dir = ({
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("enter","enter");
  add_action("south","south");
  add_action("east","east");
  add_action("west","west");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

enter(str) {
if(!str) { write("Enter what?\n"); return 1; }
if(str == "opening" || str == "cave" || str == "tunnel") {
  tp->move_player("into the dark opening#players/eurale/Glade/eg15.c");
  return 1; }
else {
  write("I just don't understand what you want to do.\n"); return 1; }
}
south() {
  tp->move_player("into the grass#players/eurale/Glade/eg13.c");
  return 1; }
east() {
  write("The thorny bushes prevent movement that way.\n");
  return 1; }
west() {
  tp->move_player("into the grass#players/eurale/Glade/eg11.c");
  return 1; }
