inherit "room/room";	/*  r5.c  */
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
"You are standing on a somewhat wide section of the walkway.  Off in\n"+
"the distance to the north, you can see numerous large platforms of\n"+
"rock floating on the flames.  The walkway continues in three ways\n"+
"from this point, to the east, south and west.\n";
 items=({
 "platforms",
"The large rock platforms are carrying large amounts of small planar\n"+
"demons.  There are a lot of them riding off in the distance",
 "demons",
"The small demons are too far away to see any details",
 "walkway",
"The walkway at this point is somewhat circular, leading off in three\n"+
"directions from this point.  Looking over the edge, flames fill your\n"+
"view",
 "flames",
"There are flames all around you, in every direction",
 });
 dest_dir=({
   "/players/zeus/realm/d/r6.c", "east",
   "/players/zeus/realm/d/r10.c", "south",
   "/players/zeus/realm/d/r4.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

