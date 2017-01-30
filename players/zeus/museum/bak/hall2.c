/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

 short_desc="The Museum";
 long_desc=
"This is the main hallway of the museum.  The hallway continues to the east\n"+
"and west, and to the north is a smaller room.  All of the walls are made\n"+
"of a clear material which allows you to see the vastness of space beyond\n"+
"the museum.  A soft light is coming from the ceiling above you.\n";
 set_light(1);
 items=({
	"walls",
"The walls are made of a perfectly clear material, quite similar to glass.\n"+
"Looking through the walls, the infinite blackness of space can be seen",
	"stars",
"Space is scattered with many tiny stars, all millions of miles away",
	"space",
"Outer space is so black and cold...  and yet so beautiful",
	"ceiling",
"The ceiling is glowing with a soft light, allowing you to see",
 });
 dest_dir=({
	"/players/zeus/museum/npc4.c", "north",
	"/players/zeus/museum/hall3.c", "east",
	"/players/zeus/museum/npc9.c", "south",
	"/players/zeus/museum/hall1.c", "west",
 });
}


