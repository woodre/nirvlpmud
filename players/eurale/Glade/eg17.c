#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  The path continues through the trees.  It is a peaceful and serene\n"+
  "place.  You can hear the songs of birds high up in the trees as they\n"+
  "sing their melodious music for all to hear.\n";

items = ({
  "path","A narrow dirt path covered with fallen leaves",
});

dest_dir = ({
  "players/eurale/Glade/eg16.c","south",
  "players/eurale/Glade/eg18.c","east",
});

}

init() {
  ::init();
  add_action("search","search");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }
