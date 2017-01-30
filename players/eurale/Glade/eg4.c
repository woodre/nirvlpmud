#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  The forest seems thicker here.  The trees are taller and fuller\n"+
  "which makes it somewhat darker.  Farther south you can see light\n"+
  "from an opening in the woods.  The scent of fresh earth permeates\n"+
  "the air.\n";

items = ({
  "trees","Large hardwood trees.  One in particular looks to be much\n"+
  	  "larger than the others",
});

dest_dir = ({
  "players/eurale/Glade/eg3.c","north",
  "players/eurale/Glade/eg5.c","south",
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("climb","climb");
}

search(str) {
if(!str) {
  write("You search the area and find nothing special.\n");
  return 1; }
if(str == "trees") {
  write("You look the trees over very carefully, especially the large\n"+
	"one.  You discover a lower branch away from the path that just\n"+
	"might let you climb this huge oak.\n");
  return 1; }
}

climb(str) {
if(!str) { write("There are lots of choices, be specific.\n"); return 1; }
if(str == "tree") {
  write("You try to climb a nearby hickory but it just isn't possible.\n");
  return 1; }
if(str == "oak") {
  tp->move_player("up the tree#players/eurale/Glade/oak1.c");
  return 1; }
}
