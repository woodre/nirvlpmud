/* Stairwell to Tower, Created <8/05/01> by Jara */

#include "/players/jara/area1/castle/room/defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="Stairwell to the Tower";
  long_desc=
    "  The stone walls are circular in this room, and a spiral staircase\n"+
    "leads further up within the tower. A small, barred window lets in a\n"+
    "dim light, and the torches upon the wall flicker in the gentle breeze.\n"+
    "An archway in the southern wall leads out to the castle hallway.\n";
    items=({
    "walls",
    "The dark grey stones of the wall are worn smooth",
    "staircase",
    "The stone staircase is carved of the same stones as the walls. It is\n"+
    "well worn",
    "tower",
    "The inside of the tower is dimly lit and made of stone",
    "window", 
    "A small, square window with ribbed, metal bars",
    "light",
    "The light is dim, but the staircase is visible",
    "wall",
    "The dark grey stones of the wall are worn smooth",
    "torches",
    "The torches are mounted upon the wall and have been lit for some time",
    "breeze",
    "You can't see the breeze, but it is cool upon your face",
    "archway",
    "A archway in the southern wall, rounded at the top",
    "hallway",
    "The hallway is visible just beyond the doorway" });
  dest_dir=({ 
    "/players/jara/area1/castle/room/hall4.c","south",
    "/players/jara/area1/castle/room/tower2.c","up" });
}
