#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "A large tree";
long_desc =
  "  You have climbed to the top of this old oak.  The view from here\n"+
  "is spectacular.  The ground below is hidden completely by the leaves\n"+
  "and branches.  There is an opening hollowed out in the side of the\n"+
  "tree.\n";

items = ({
  "branches","Thick, sturdy limbs which will support much",
  "leaves","Green, healthy oak leaves",
  "opening","A crude opening chopped into the tree trunk.  It looks like\n"+
	    "it's large enough to enter",
});

dest_dir = ({
  "players/eurale/Glade/oak1.c","down",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("search","search");
  add_action("enter","enter");
}

search() {
  write("You search the leaves and branches and find nothing special.\n");
  return 1; }

enter(str) {
if(!str) { write("Enter what?\n"); return 1; }
if(str == "opening" || str == "tree") {
  tp->move_player("into the tree#players/eurale/Glade/oak3.c");
  return 1; }
}
