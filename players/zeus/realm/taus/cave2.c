inherit "room/room";	/*  cave2.c  */
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

 short_desc="A cavern";
 long_desc=
"You are standing in a dark, dank cave.  The walls are smooth and rather\n"+
"wet, with some roots protruding from them.  Numerous small tunnels\n"+
"continue on from this point, including the one that leads out to the\n"+
"surface to the west.  The cave is terribly cold.\n";
 set_light(0);
 items=({
	 "walls",
"The walls are rather smooth, and the ground almost looks similar to\n"+
"clay.  They are extremely moist, and roots can be seen in them",
	 "roots",
"Some brown roots are protruding from the walls of the cave",
	 "tunnels",
"The cave breaks away into numerous small tunnels from this point",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/cave1.c", "out",
	 "/players/zeus/realm/taus/cave3.c", "east",
	 "/players/zeus/realm/taus/cave4.c", "south",
	 "/players/zeus/realm/taus/cave5.c", "down",
 });
}


exit(){    if(TP) TP->clear_fight_area();     }
realm() {  return "NT"; }
okay_follow() { return 1; }