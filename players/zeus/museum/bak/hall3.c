/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

 short_desc="The Museum";
 long_desc=
"You are standing in the main hallway of the museum.  The hallway contines\n"+
"in all four directions from this point.  Through the clear walls the\n"+
"infinite blackness of space can be clearly seen, scattered with stars.\n"+
"A soft light is eminating from the ceiling.\n";
 set_light(1);
 items=({
	 "walls",
"The walls are made of a clear material similar to glass.  They are\n"+
"perfectly clear.  As you look through them you can see the infinite\n"+
"blackness of space, scattered with many distant stars",
     "space",
"Outer space looks very beautiful.  It seems to go on forever",
     "stars",
"The distant stars are twinkling in space.  They are truly beautiful",
     "ceiling",
"The ceiling is perfectly clear, and through it space can be seen.  The\n"+
"ceiling itself is glowing softly, providing light for the museums halls",
 });
 dest_dir=({
	"/players/zeus/museum/lounge.c", "north",
	"/players/zeus/museum/hall4.c", "east",
	"/players/zeus/museum/entrance.c", "south",
	"/players/zeus/museum/hall2.c", "west",
	});
}
