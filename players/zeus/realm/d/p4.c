inherit "room/room";	/*  p4.c  */
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
"You are at the end of the walkway.  From here, it only leads back to\n"+
"the west.  Off in the distance to the east flames can be seen for what\n"+
"feels like miles.  There are numerous platforms of rock visible riding\n"+
"on the flames, each of which appears to be carrying demons.\n";
 items=({
   "walkway",
"The rock walkway is quite smooth, and made of a grainy brown rock.\n"+
"The only way to go from here is back to the west",
   "flames",
"In every direction flames can be seen burning endlessly.  It is\n"+
"actually a very beautiful sight",
   "platforms",
"Each of the platforms of rock looks quite small from here, because\n"+
"of how far away they are.  Small demons appear to be riding on them",
   "demons",
"It is impossible to see any details on the demons, but you can tell\n"+
"for sure that that is what the platforms are carrying",
 });
 dest_dir=({
   "/players/zeus/realm/d/r17.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }