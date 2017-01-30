/* Forest Entrance, Created <6/22/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Forest Entrance";
  long_desc=
"  The forest entrance is shrouded by the thick canopy of dense trees.\n"+
"Very little light enters as the path begins to progress deeper within\n"+
"the forest. The brilliant light of the clearing to the southwest is\n"+
"almost blinding in comparison to the darkness of the forest, and thick\n"+
"patches of wildflowers are visible throughout the field of grass. The\n"+
"city wall is just beyond the field and path that borders the wall.\n";
  items=({
    "trail",
    "The narrow trail enters the forest. It has bits of gravel and dirt,\n"+
    "as well as debris from the forest canopy and underbrush",
    "debris",
    "The debris on the trail consists of twigs, leaves and branches",
    "forest", 
    "The forest has a thick, green canopy and dense underbrush",
    "canopy",
    "The forest canopy lets little light through the leaves",
    "underbrush",
    "Dense shrubs and bushes of underbrush",
    "trees",
    "The trees are growing closely together and many have thick trunks. There\n"+
    "are several mishapen trees and each one has a thick canopy of leaves",
    "field",
    "The field of grass just outside the forest border is thick with lush\n"+
    "grass and delicate wildflowers",
    "clearing",
    "A field of grass, dotted with patches of wildflowers",
    "fields",
    "The fields outside the city walls are well mainted, and the grass is\n"+
    "lush and green. The wild flowers grow in abundance",
    "wall",
    "The wall is approximately twelve feet high and made of dark, grey\n"+
    "stone bricks",
    "bricks",
    "Large, grey stone bricks, square in shape",
    "path",
    "A dirt path, mixed with sand and bits of gravel",
    "grass",
    "The recently trimmed grass has few weeds and a lush, green color",
    "flowers",
    "The wild flowers are lavender and yellow in color" });
  dest_dir=({ 
    "/players/jara/area1/paths/room/path14.c","southwest" });
}
