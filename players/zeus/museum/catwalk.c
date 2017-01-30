/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

 short_desc="The Museum";
	

 long_desc=
"This is a small circular platform high above the museum lounge.  From here\n"+
"a ladder leads down through a circluar hole, to the lounge.  Directly ahead\n"+
"is a shimmering, transparent walkway of energy that spans the distance from\n"+
"this platform to an observation deck directly over the museum arena.\n";
 set_light(1);
 items=({
 	"platform",
"A circluar platform of metal that seems to float above the museum lounge",
  "ladder",
"Made of a single pole with rods protruding from each end, the ladder leads\n"+
"back to the museum lounge below",
  "hole",
"A circluar hole has been cut into the floor of the platform.  A ladder leads\n"+
"down through it",
  "walkway",
"Some sort of energy field exists between the platform you stand on to a large\n"+
"observation deck above the arena.  Every now and then you see it flicker",
  "deck",
"High above the arena floats a massive steel and glass platform where people\n"+
"can watch the arena battles take place",
 });
 dest_dir=({
	"/players/zeus/museum/stands.c", "cross", 	
	"/players/zeus/museum/lounge.c", "down",
 });
}

