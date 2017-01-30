/* Path 13, Created <5/21/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway";
  long_desc=
    "  The path winds through the lush, green fields just east of the city\n"+
    "walls. The grass here is well maintained, and patches of wild flowers\n"+
    "spread in all directions. A forest borders the graveyard to the east,\n"+
    "and the path continues to the northeast.\n";
  items=({
    "forest", 
    "The forest has a thick, green canopy and dense underbrush",
    "canopy",
    "The forest canopy lets little light through the leaves",
    "underbrush",
    "Dense shrubs and bushes of underbrush",
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
    "path",
    "A dirt path, mixed with sand and bits of gravel",
    "grass",
    "The recently trimmed grass has few weeds and a lush, green color",
    "flowers",
    "The wild flowers are lavender and yellow in color" });
  dest_dir=({ 
    PATH+"path14","northeast",
    PATH+"path12","south" });
}
