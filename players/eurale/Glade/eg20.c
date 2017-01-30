#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  You stand outside a well concealed hut hidden deep within the\n"+
  "forest.  The path goes westward up the hill and south further into\n"+
  "the forest.  Faint wisps of smoke can just be seen as they drift\n"+
  "out of the stack sticking through the roof of the hut.\n";

items = ({
  "hut","A log styled hut nearly overgrown with moss",
  "path","A well traveled game trail",
  "smoke","Blueish white wisps",
  "stack","A crude smoke stack",
});

dest_dir = ({
  "players/eurale/Glade/eg21.c","enter",
  "players/eurale/Glade/eg22.c","south",
  "players/eurale/Glade/eg19.c","west",
});

}

init() {
  ::init();
  add_action("search","search");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }
