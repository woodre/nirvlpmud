#include "/players/pestilence/define.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

short_desc = "Men's Room"+NORM+"";
long_desc =
  "    This is the very small men's bathroom.  The walls have a dark\n"+
  "stained look, that covers the white paint.  A small urinal is on\n"+
  "the west wall, with a toilet directly next to it.  A small window\n"+
  "is on the south wall, and a dingy sink is on the east wall.\n"+
  "the dancers.\n";
/*
add_property("NT");
add_property("PK");
*/
set_light(1);

items = ({
  "walls","The walls are white with a dark stained color",
  "wall","The wall is white with a dark stained color",
  "urinal","A white porcelain urinal that still has urine in it",
  "toilet","A dingy looking toilet, in need of flushing",
  "window","Out the window, you see a roadway",
  "sink","A very dirty sink, that appears to have a clogged drain",
  "paint","White paint that is stained with a dark dirt like substance",
});

dest_dir = ({
"/players/pestilence/club2/room/inside.c","out",
});

}

init() {
  ::init();
add_action("stop","quit");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}
