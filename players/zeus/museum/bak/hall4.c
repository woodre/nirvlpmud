/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

 short_desc="The Museum";
 long_desc=
"This is the main hallway of the museum.  The main hallway continues\n"+
"to the east and west, and to the south is a smaller room of the\n"+
"museum.  The ceiling is glowing with a soft light which illuminates\n"+
"the hallway.  All of the walls are perfectly clear, allowing you to\n"+
"see through them.\n";
 set_light(1);
 items=({
	 "ceiling",
"The ceiling is perfectly clear, through it you can see the blackness\n"+
"of space, scattered with stars.  The ceiling is glowing softly",
	 "space",
"Outer space is very black, and there are many stars.  It is always\n"+
"a beautiful sight to see",
	 "stars",
"The stars are as beautiful as anything you have ever seen",
	 "walls",
"The walls are made of a material very similar to glass.  They are\n"+
"perfectly clear, providing you with a wonderful view of outer space",
 });
 dest_dir=({
	"/players/zeus/museum/hall5.c", "east",
	"/players/zeus/museum/npc5.c", "south",
	"/players/zeus/museum/hall3.c", "west",
 });
}
