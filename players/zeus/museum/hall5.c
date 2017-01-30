/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

 short_desc="The Museum";
 long_desc=
"This is the main hallway of the museum.  From this point the main hallway\n"+
"continues only to the west, however there are smaller rooms to the north,\n"+
"east, and south.  Each and every wall is perfectly clear, allowing you\n"+
"a perfect view of outer space.  The ceiling is glowing softly.\n";
 set_light(1);
 items=({
	"walls",
"The walls are made of a perfectly clear material, quite similar to glass.\n"+
"Looking through them, the beauty of space can be openly admired",
	"stars",
"Space is scattered with many stars, all millions of miles away",
	"space",
"Outer space is so beautiful, it is hard to describe",
	"ceiling",
"The ceiling is glowing with a soft light, allowing you to see",
 });
 dest_dir=({
	"/players/zeus/museum/npc6.c", "north",
	"/players/zeus/museum/npc8.c", "east",
	"/players/zeus/museum/npc7.c",  "south",
	"/players/zeus/museum/hall4.c", "west",
 });
}

