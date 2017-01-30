#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  This is the edge of a large stand of trees.  You can see the tree\n"+
  "line stretching off to the north and east.  Tall, swaying grasses\n"+
  "enjoy the sun of an open area but it's too tall to see very far.\n"+
  "The safety of the trees is immediately west.\n";

items = ({
  "trees","Tall, thick trees extending north and east",
  "grasses","Sharp, tall grass...almost your height",
  "stand","Thick trees, close together",
});

dest_dir = ({
  "players/eurale/Glade/eg5.c","west",
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("north","north");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

north() {
  tp->move_player("into the tall grass#players/eurale/Glade/eg7.c");
  return 1; }
