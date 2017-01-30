inherit "room/room";	/*  p5.c  */
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
"You have come to an end of the walkway.  The only way to go from here\n"+
"is back to the east.  As you look off in the distance to the west, all\n"+
"you can see is miles of fire.  It is an amazing sight as the flames\n"+
"dance endlessly through the sky.\n";
 items=({
 "walkway",
"The rockwalk comes to and end at this point, leading only back to the\n"+
"east.  It is rather smooth, and seems to be riding on the flames",
 "fire",
"The flames stretch out for miles upon miles.  There seems to be no end\n"+
"to them.  It is the essence of this plane",
 "flames",
"The flames stretch out for miles upon miles.  There seems to be no end\n"+
"to them.  It is the essence of this plane",
 "sky",
"What you would consider to be the sky, is simply a gigantic fireball.\n"+
"It stretches on for as far as you can see",
 });
 dest_dir=({
	"/players/zeus/realm/d/r27.c", "east", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
