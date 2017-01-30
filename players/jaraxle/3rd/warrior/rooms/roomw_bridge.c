#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth";
long_desc =
  "   The cobblestone walkway quickly reaches a short bridge\n"+
  "over the River of Despair to the west. The forest ends at\n"+
  "the foot of the bridge making a short, small area of dirt\n"+
  "and short blades of grass patches.\n";
items = ({
  "forest","High reaching trees with thick branches stretching out everywhere",
  "branches","Large branches which grow low to the ground",
  "trees","High reaching trees with thick branches stretching out everywhere",
  "walkway","A manmade walk of small stones",
  "stones","Small round stones of various sizes",
  "bridge","A small wooden bridge crossing over the River of Despair",
  "river","A wonderously clean looking river",
  "river of despair","A wonderously clean looking river",
  "foot","The start of a bridge crossing the River of Despair",
  "grass","Small patches of grass that only grow in salty dirt",
  "grass patches","Small patches of grass that only grow in salty dirt",
  "blades","Small patches of grass that only grow in salty dirt",
  "patches","Small patches of grass that only grow in salty dirt",
  "dirt","Soft dirt, fertalized from the river",
});

dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/roomw2.c","east",
  "/players/jaraxle/3rd/warrior/rooms/despair_bridge_ooze.c","cross",
});
}
