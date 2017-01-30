#include "/players/pestilence/define.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

short_desc = "Ladies's Room"+NORM+"";
long_desc =
  "    This is a very clean bathroom.  There is only one toilet here.\n"+
  "A sink with a paper towel dispenser is on the west wall.  The walls\n"+
  "are covered with flowered yellow wallpaper.  The floor is a clean\n"+
  "white tile.\n";
add_property("NT");
add_property("PK");
set_light(1);

items = ({
  "walls","The walls are covered with yellow flowered wallpaper",
  "wall","The wall is covered with flowered yellow wallpaper",
  "toilet","A white toilet, that appear to be well taken care of",
  "wallpaper","Yellow wallpaper with assorted flowers",
  "sink","A clean white sink",
  "towel dispenser","A brown dispenser of paper towels",
  "dispenser","A brown dispenser of paper towels",
  "tile","White tile covering the whole floor",
  "floor","White tile covering the whole floor",
});

dest_dir = ({
"/players/pestilence/club/room/inside.c","out",
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
