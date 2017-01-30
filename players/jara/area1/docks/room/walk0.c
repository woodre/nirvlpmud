/* Eastern end of the boardwalk, Created <5/9/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="The boardwalk";
  long_desc=
    "  The boardwalk is raised up off the beach by massive wooden pilings,\n"+
    "and a large warehouse stands to the north, the entrance just to the\n"+
    "east. Thick grasses, standing several feet high, border the beach to\n"+
    "the north, and the high tide comes up to the pilings of the boardwalk.\n"+
    "The waters are filled with seaweed and debris, and the boardwalk\n"+
    "continues to the east and west.\n";
  items=({
    "boardwalk",
    "The boardwalk is made of wooden planks and is approximately twelve feet wide",
    "warehouse", 
    "A large, two-story building. Several windows in the upper portion of wall\n"+
    "are covered in a thick layer of dust",
    "pilings",
    "The thick, wooden posts hold the building level, up off the beach",
    "grasses",
    "The thick grass is a deep green in color, and stands several feet high",
    "beach",
    "The beach stretches for several miles in each direction, with high sand dunes\n"+
    "and rock formations",
    "dunes",
    "The sand dunes vary in size, and extend far to the east",
    "formations",
    "The rock formations are covered with moisture and a thick, green moss",
    "waters",
    "The tide is in, and the waters are littered with seaweed and other debris",
    "seaweed",
    "Green strands of vegetation from the sea",
    "debris",
    "Small bits of wood and other items float within the tangles of seaweed" });
  dest_dir=({
    PATH+"walk1","east",
    PATH+"walk2","west" });
  if(!present("sailor")) {
    ob=clone_object("/players/jara/area1/docks/mon/sailor.c");
    move_object(ob,this_object());
  }
}
