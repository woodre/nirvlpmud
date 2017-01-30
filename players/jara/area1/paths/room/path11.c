/* Path 11, Created <5/21/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway";
  long_desc=
    "  The path winds through the lush, green fields just east of the city\n"+
    "walls. The grass here is well maintained, and patches of wild flowers\n"+
    "spread in all directions. The gate to the graveyard lies to the north\n"+
    "and east, and vines have begun to grow through the bars. The graveyard\n"+
    "is bordered by a metal fence, and a small chapel within the graveyard\n"+
    "is further along the path to the north.\n";
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
    "walls",
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
    "/players/jara/area1/yard/room/gate.c","northeast",
    PATH+"path10","south",
    PATH+"path12","northwest" });
}
