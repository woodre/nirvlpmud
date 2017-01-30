#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "A gray rock";
long_desc =
  "  You stand on the inside of a hollowed out rock.  What strength\n"+
  "it must have taken to hollow out a solid stone.  The walls are all\n"+
  "curved to conform to the shape of the outside of this huge rock.\n"+
  "there are chips of stone across the floor of this strange space.\n";

items = ({
  "walls","The walls, amazingly enough, appear to have been either\n"+
	  "chewed or clawed away",
  "chips","Small pieces of rock, piled on the floor to provide a cushion\n"+
	  "for sleeping or sitting?",
});

dest_dir = ({
  "players/eurale/Glade/eg9.c","out",
});

}

init() {
  ::init();
  add_action("search","search");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }
