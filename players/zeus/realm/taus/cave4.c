inherit "room/room";	/*  cave4.c  */
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

	if(!present("demon")) 
		MO(CO("/players/zeus/realm/NPC/demon_large.c"), TO);

 short_desc="A cavern";
 long_desc=
"This is a narrow part of the cavern.  The tunnel apears to have, at one\n"+
"time continued on to the south, however it has collapsed.  The walls of\n"+
"the room are very hard and condensed water is visible on them.  A very\n"+
"cold wind can be felt blowing through the cavern.\n";
 set_light(0);
 items=({
	 "walls",
"The walls are rather smooth, and the ground almost looks similar to\n"+
"clay.  They are extremely moist, drops of water are running down them",
	 "droplets",
"Tiny droplets of water are running down the walls of the cavern",
	 "water",
"Tiny droplets of water are condensing on the walls of the cavern,\n"+
"slowly running down to the floor",
	 "tunnel",
"It seems as though the tunnel used to continue to the south, however\n"+
"A large amount of dirt and rocks has fallen, blocking the tunnel",
	 "rocks",
"Large rocks are blocking the passage to the south",
	 "dirt",
"Lots of dirt has fallen in around the tunnel, blocking travel to the\n"+
"south.  There are also many large rocks in the way",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/cave2.c", "north",
 });
}

exit(){    if(TP) TP->clear_fight_area();     }
realm() {  return "NT"; }
okay_follow() { return 1; }