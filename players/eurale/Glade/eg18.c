#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  The forest is thicker here but less sinister.  Rays of light filter\n"+
  "down through the canopy high above.  The rays of sunlight almost\n"+
  "seem to dance as the dust particles play their game of tag through-\n"+
  "out the beams.\n";

items = ({
  "canopy","Bushy tree tops",
});

dest_dir = ({
  "players/eurale/Glade/eg19.c","east",
  "players/eurale/Glade/eg17.c","west",
});

}

init() {
  ::init();
  add_action("search","search");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }
