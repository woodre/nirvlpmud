#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  The trees have definitely thinned out some here.  The bushes\n"+
  "that have grown here are much thicker than some of the other parts\n"+
  "of the glade.  To the east it looks as if the stand of trees is\n"+
  "ending as there is much more light in that direction.\n";

items = ({
  "trees","The large trees are spaced much farther apart even allowing\n"+
	  "some sunlight to filter through",
  "bushes","Wicked looking bushes with long, pointed spikes growing\n"+
	   "off each of the branches",
});

dest_dir = ({
  "players/eurale/Glade/eg4.c","north",
  "players/eurale/Glade/eg6.c","east",
});

}

init() {
  ::init();
  add_action("search","search");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }
