inherit "room/room";	/*  r13.c  */
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
"The rock walkway curves here, lead to the east and to the south.  To\n"+
"the south you can see a red vortex hovering over the walkway.  All\n"+
"around the walkway flames are burning endlessly, the waves of heat\n"+
"pounding against you.  There is no relief.\n";
 items=({
	 "walkway",
"The rock walkway winds through the flames of the demon plane.  It\n"+
"curves here, heading off to the east and south",
 "vortex",
"It is a shimmering red vortex of light, which leads out of this plane",
 "flames",
"In every direction flames can be seen.  They are the essence of the\n"+
"demon plane, and there is no place to hide",
 });
 dest_dir=({
   "/players/zeus/realm/d/r14.c", "east",
   "/players/zeus/realm/d/ent.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
