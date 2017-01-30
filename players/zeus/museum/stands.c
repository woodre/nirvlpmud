/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

 short_desc="The Museum";
 long_desc=
"This is the obervation stands for the museum arena.  The deck is very\n"+
"spacious, easily accomodating dozens of people at a single time.  The\n"+
"floor and walls are made of glass, allowing one to see the entire arena\n"+
"virtually unobstructed, save for the few pieces of steel that give the\n"+
"deck its structure.\n";
 set_light(1);
 items=({
  "arena",
"Far below, you can make out the entire arena.  Your blood races and you\n"+
"find yourself dizzy from the height",
  "floor",
"The floor is made almost entirely of glass, allowing you to see the center\n"+
"of the arena from a birds-eye view",
  "wall",
"The walls are made from glass and offer a striking view of the museum's\n"+
"expansive arena",      
 	"steel",
"There is only a few pieces of steel to give the deck its form", 
 });
 dest_dir=({
	"/players/zeus/museum/catwalk.c", "cross",
 });
}

