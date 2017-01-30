#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Entrance to the Volcano Mountain";
long_desc =
"  This is the large mouth of the cave.  All around lie\n"+
"the remains of past visitors, their whitened bones picked\n"+
"clean of all equipment and flesh. Ahead to the west the\n"+
"cave deepens, growing very dark. To the east is the\n"+
"plains.  Overhead, at the top of the mountain, the\n"+
"volcano smokes and churns.\n";

items = ({
  "bones",
  "The remains of those foolish enough to enter this terrible\n"+
  "place. All that remain of them are the bones, no flesh\n"+
  "remains",
  "foothills",
  "The low foothills of the southern lands",
  "cave",
  "A large cave, its mouth standing nearly 30 feet tall. It continues\n"+
  "straight into the side of the mountain",
  "volcano",
  "A huge volcano that seems to still be active"

});

dest_dir = ({
  "/players/maledicta/cont/rooms/879.c","east",
  "/players/maledicta/cont/rdragon/rooms/r2.c","west",
});

}
