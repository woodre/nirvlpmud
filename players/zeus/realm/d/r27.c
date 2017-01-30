inherit "room/room";	/*  r27.c  */
#include "/players/zeus/realm/d/defs.h"

reset(arg){

 if(!random(DC))
   move_object(clone_object(
	   "/players/zeus/realm/NPC/demon_small.c"), this_object());

	if(arg) return;

 short_desc="The demon plane";
 set_light(1);
 set_no_clean(1);
 long_desc=
"You are standing on a rock walkway which is winding through the\n"+
"flames of the demon plane.  There is no way to deviate from the\n"+
"walkway.  The sky is a giant mass of burning flames.  The endless\n"+
"heat is pressing down on you like a weight.\n";
 items=({
 "walkway",
"The rock walkway is leading through the flames.  It is rather smooth,\n"+
"and there is no way to deviate from it.  It leads to the east and\n"+
"west from this point",
 "flames",
"The torturous flames are all around you.  The heat is almost unbearable",
 "sky",
"When you look up, all you can see is a single, gigantic fireball.  It\n"+
"is what makes up the sky in this place",
 });
 dest_dir=({
   "/players/zeus/realm/d/r28.c", "east",
   "/players/zeus/realm/d/p5.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
