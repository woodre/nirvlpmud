inherit "room/room";	/*  cave3.c  */
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

	if(!present("demon")) 
		MO(CO("/players/zeus/realm/NPC/demon_large.c"), TO);

 short_desc="A cavern";
 long_desc=
"You are standing in a dug out area of the cavern.  The walls are very\n"+
"hard and solid, appearing to be made out of clay.  They are very wet,\n"+
"as droplets of water are visible slowly dripping down them.  A small\n"+
"hole is visible in the roof of the room, and cold air can be felt blowing\n"+
"out of it.\n";
 set_light(0);
 items=({
	 "walls",
"The walls are rather smooth, and the ground almost looks similar to\n"+
"clay.  They are extremely moist, drops of water are running down them",
	 "hole",
"The hole leads up into darkness.  It is too small to enter.  Cold\n"+
"air can be felt constantly blowing down out of it",
	 "droplets",
"Tiny droplets of water are running down the walls of the cavern",
	 "water",
"Tiny droplets of water are condensing on the walls of the cavern,\n"+
"slowly running down to the floor",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/cave2.c", "west",
 });
}


exit(){    if(TP) TP->clear_fight_area();     }
realm() {  return "NT"; }
okay_follow() { return 1; }