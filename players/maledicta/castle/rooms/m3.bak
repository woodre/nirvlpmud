#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "a mountain outcropping";
long_desc =
"  Standing atop a small outcropping, you see that the trail continues\n"+
"over it, down into a small valley, into what looks like a very small\n"+
"town. A broken path leads to the west, away from the mountain. The\n"+
"trail continues to the north and south.\n";

items = ({
  "outcropping",
  "A small rise that flows from the mountain to the east. It is a little\n"+
  "rough and yet the trail on it allows for easy travel",
  "trail",
  "A well worn trail, you see that it leads to the north toward a small\n"+
  "town and also back to the south",
  "valley",
  "A small valley that expands westward into rolling hills",
  "town",
  "Looking closely, you see that the town is surrounded by a wall that\n"+
  "glimmers. A huge building sprouts up from its center, its white washed\n"+
  "walls clearly visible even from this distance",
  "path",
  "A small stone path that leads over the outcropping and down the hill\n"+
  "to the west",
  "mountain",
  "Looking to the east, you see that the mountain looms overhead, its\n"+
  "peak lost from sight",
  "building",
  "It is hard to make out what the building is, but it seems to be very\n"+
  "tall and wide, with what looks like battlements atop its roof",
  "wall",
  "You can't quite make out much detail about it, or why it glimmers",
   });

dest_dir = ({
  "/players/maledicta/castle/rooms/m5.c","north",
  "/players/maledicta/castle/rooms/m4.c","west",
  "/players/maledicta/castle/rooms/m2.c","south",
});

}
