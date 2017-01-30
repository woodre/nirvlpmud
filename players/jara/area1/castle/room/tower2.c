/* Zercher Castle Tower, Created <8/05/01> by Jara */

#include "/players/jara/area1/castle/room/defs.h"
#include "/players/jara/misc/ansi.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="Top of the Tower";
  long_desc=
    "  The stone walls are circular in this room, and a spiral staircase\n"+
    "leads down. A thick layer of hay has been spread out upon the floor,\n"+
    "and there is a large opening in the western wall. A golden plaque is\n"+
    "on the eastern wall and a small chest stands against the wall.\n";
    items=({
    "walls",
    "The dark grey stones of the wall are worn smooth",
    "staircase",
    "The stone staircase is carved of the same stones as the walls. It is\n"+
    "well worn",
    "tower",
    "The inside of the tower is dimly lit and made of stone",
    "opening", 
    "The entire western wall of the tower is open to the elements",
    "light",
    "The light is dim, but the staircase is visible",
    "wall",
    "The dark grey stones of the wall are worn smooth",
    "hay",
    "The hay has been thickly piled all over the floor of the tower",
    "plaque",
    "."+YEL+".............................."+NORM+".\n"+
    ".                              .\n"+
    ".    With eyes of red,         .\n"+
    ".      and a gift of the       .\n"+
    ".        eternal lifeblood..   .\n"+
    ".                              .\n"+
    ".              Vr'uath         .\n"+
    ".                              .\n"+
    "."+YEL+".............................."+NORM,   
    "chest",
    "A metal chest with a small keyhole",
    "keyhole",
    "The design seems to be ancient" });
  dest_dir=({ 
    "/players/jara/area1/castle/room/tower1.c","down" });
}
