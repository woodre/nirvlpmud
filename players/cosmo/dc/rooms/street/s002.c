#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"14th and Independence"+NORM;
  long_desc=
"   You walk on fearlessly through the city and arrive at the\n"+
"intersection of 14th Street and Independence Avenue.  Large\n"+
"buildings can be seen to the south, while green grass can\n"+
"actually be seen in other directions.  A light breeze blows\n"+
"through the air, making you feel quite at ease here.  "+GRN+"14th St"+
NORM+"\ncontinues to run north-south here, while "+GRN+"Independence Ave"+
NORM+" runs\neast-west.  Off to the northwest, the "+BLU+"Washington Monument"+
NORM+" rises\nhigh in the sky.\n\n";

  items=({
"grass","The plush green grass is off in the distance to the north",
"buildings", "Old dirty buildings of no particular significance",
  });

  dest_dir=({
    DCSTR+"s002a", "north",
    DCSTR+"s001", "south",
    DCSTR+"s113", "east",
    DCSTR+"s115", "west",
  });
}

init() {
  ::init();
}
