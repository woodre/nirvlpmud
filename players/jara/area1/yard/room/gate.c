/* Gateway to the Graveyard, Created <6/22/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Gate to the Graveyard";
  long_desc=
"  The gate to the graveyard is just beyond the path outside the city\n"+
"wall. Delicate vines of ivy have intertwined between the thick, metal\n"+
"bars of the gate, blocking much of the view of the graveyard within.\n"+
"There is a chapel visible within the distance, and the path continues\n"+
"toward the field and the city to the southwest.\n";
  items=({
    "gate",
    "An arched, metal gate with vines of ivy that have overgrown",
    "vines", 
    "The vines of ivy are deep green in color and delicate, white flowers",
    "grow on the vines",
    "ivy",
    "The ivy grows in thick vines, upward on the gate to the graveyard",
    "fence",
    "The metal fence has high points and the bars are narrow",
    "fields",
    "The fields outside the city walls are well mainted, and the grass is\n"+
    "lush and green. The wild flowers grow in abundance",
    "wall",
    "The wall is approximately twelve feet high and made of dark, grey\n"+
    "stone bricks",
    "bricks",
    "Large, grey stone bricks, square in shape",
    "graveyard",
    "Bordered by a metal fence, the graveyard has a sinister appearance",
    "chapel",
    "A small, white chapel with stained glass windows",
    "windows",
    "The windows depict images of angels",
    "path",
    "A dirt path, mixed with sand and bits of gravel",
    "grass",
    "The recently trimmed grass has few weeds and a lush, green color",
    "flowers",
    "The wild flowers are lavender and yellow in color" });
  dest_dir=({ 
    "/players/jara/area1/paths/room/path11.c","southwest" });
}
