/* Eastern end of the boardwalk, Created <5/2/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The boardwalk";
  long_desc=
    "  The boardwalk comes to an abrupt end, blocked by rock formations and\n"+
    "sand dunes to the east. A large warehouse stands further up the beach,\n"+
    "held up by wooden pilings. A sturdy plank connects the boardwalk and\n"+
    "the wide double doors of the warehouse, and a smaller door marks the\n"+
    "entrance to the building.\n";
  items=({
    "boardwalk",
    "The boardwalk is made of wooden planks and is approximately twelve feet wide",
    "formations",
    "The rock formations are covered with moisture and a thick, green moss",
    "dunes",
    "The sand dunes vary in size, and extend far to the east",
    "warehouse", 
    "A large, two-story building. Several windows in the upper portion of wall\n"+
    "are covered in a thick layer of dust",
    "pilings",
    "The thick, wooden posts hold the building level, up off the beach",
    "plank",
    "A wide, wooden plank that extends from the boardwalk to the warehouse",
    "doors",
    "The double doors of the warehouse are approximatey ten feet wide, and slide\n"+
    "on metal railings",
    "door",
    "A small door, left slightly ajar" });
  dest_dir=({
    PATH+"wrhs4","enter",
    PATH+"walk0","west" });
}
