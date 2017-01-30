#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("hermit")) {
  move_object(clone_object("players/eurale/Glade/NPC/hermit"),TO); }
set_light(1);

short_desc = HIG+"Hermit Hut"+NORM;
long_desc =
  "  This is a small, quaint hut.  It is a single room with a small\n"+
  "window facing west and a narrow doorway leading out into the forest\n"+
  "to the south.  There is a small, stone fireplace against the rear\n"+
  "wall, pine needles spread on the floor and nothing else for comfort\n"+
  "anywhere else.\n";

items = ({
  "window","You get a good view of the hill and forest to the west",
  "doorway","A crude wooden door",
  "fireplace","A stone fireplace, loosely put together with smoldering\n"+
		"ashes in it",
  "needles","A thick mat that is probably used as a bed",
  "pine needles","Green boughs from the forest",
});

dest_dir = ({
  "players/eurale/Glade/eg20.c","exit",
});

}

init() {
  ::init();
  add_action("search","search");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }
