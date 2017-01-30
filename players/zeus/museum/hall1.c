/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

 short_desc="The Museum";
 long_desc=
"This is the main hallway of the museum.  The main hallway leads to the\n"+
"east from this point, and smaller rooms are to the north, south and west.\n"+
"All of the walls are perfectly clear, allowing you to see outer space,\n"+
"scattered with stars beyond.  The ceiling is glowing with a soft light.\n";
 set_light(1);
 items=({
	"walls",
"The walls are made of a perfectly clear material, quite similar to glass.\n"+
"Looking through the walls, the infinite blackness of space can be seen",
	"stars",
"Space is scattered with many tiny stars, all millions of miles away",
	"space",
"Outer space is very beautiful, scatted with stars.",
	"ceiling",
"The ceiling is glowing softly, providing light for the hallway",
 });
 dest_dir=({
	"/players/zeus/museum/npc2.c", "north",
	"/players/zeus/museum/hall2.c", "east",
	"/players/zeus/museum/npc3.c", "south",
	"/players/zeus/museum/npc1.c", "west",
 });
}


