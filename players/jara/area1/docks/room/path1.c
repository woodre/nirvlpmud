/* Pathway between city and boardwalk, Created <5/9/00> by Jara */

#include "defs.h"
inherit "room/room";

object ob;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A worn pathway";
  long_desc=
    "  The worn path is bordered by thick, dark green grasses and weeds,\n"+
    "growing several feet high. Delicate, yellow flowers grow in abundance\n"+
    "beneath the thick cover of the grass, and vines of blackberries are\n"+
    "visible further in the brush. The path leads south to the boardwalk\n"+
    "and piers, and continues northwest through the field.\n";
  items=({
    "pathway",
    "The narrow dirt pathway is muddied with sand and dirt",
    "grasses",
    "The grass is a variety of weeds, flowers and thick-bladed grasses",
    "weeds",
    "Dense brushes and flowering plants",
    "flowers",
    "The small, delicate flowers grow on the thick weeds. The petals are rounded,\n"+
    "and the leaves are oval in shape",
    "vines",
    "The blackberry vines grow in long tangles and are covered in thorns and fresh",
    "blackberries",
    "brush",
    "The underbrush is thick with weeds and vines and a wide variety of plants",
    "path",
    "The path is narrow, only a foot or so wide",
    "blackberries",
    "Plump, ripe berries, dark purple in color" });
  dest_dir=({ 
    PATH+"path2","northwest",
    PATH+"walk3","south" });
  if(!present("cat")) {
    ob=clone_object("/players/jara/area1/docks/mon/cat.c");
    move_object(ob,this_object());
  }
}
