#include "defs.h"
inherit "room/room";
int ant;

reset(arg) {
  if(arg) return;
set_light(1);
ant = 1;

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  You work your way through the tall grass and come upon a large\n"+
  "mound.  It is also covered but out of place.  There is a strange\n"+
  "sound coming from the mound if you listen very carefully.  Above\n"+
  "the grass you can make out the tops of trees off to the west and\n"+
  "and well off to the south.\n";

items = ({
  "grass","Wide-blades African grass",
  "trees","The green tops of tall trees",
  "mound","A large earth mound covered with grass.  Maybe you could\n"+
	  "dig up whatever is underneath?",
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
  add_action("listen","listen");
  add_action("dig","dig");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

north() {
  TP->move_player("into the grass#players/eurale/Glade/eg9.c");
  return 1; }
south() {
  TP->move_player("into the grass#players/eurale/Glade/eg7.c");
  return 1; }
east() {
  TP->move_player("into the grass#players/eurale/Glade/eg11.c");
  return 1; }
west() {
  TP->move_player("into the grass#players/eurale/Glade/eg3.c");
  return 1; }

listen(str) {
if(!str || str == "carefully" || str == "very carefully") {
  write("You hold your breath and listen........\n"+
	"It almost sounds like something large is chewing...\n");
  return 1; }
}

dig(str) {
if(!str) { write("Dig what?\n"); return 1; }
if(str == "mound") {
if(!present("shovel",TP)) {
  write("The dirt is too hard to dig by hand, it appears you'll need\n"+
	"a shovel for this undertaking.\n");
  return 1; }

if(present("shovel",TP) && ant == 1) {
  write("You shovel away the dirt of the mound.....\n"+
	"   The mound caves in and........\n");
  move_object(clone_object("players/eurale/Glade/NPC/redant"),TO);
  ant = 0;
  return 1; }
else {
  write("You dig into the mound and find nothing.\n");
  return 1; }
return 1; }
}
