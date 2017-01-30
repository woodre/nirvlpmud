inherit "room/room";	/*  r29.c  */
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
"endless flames of the demon plane.  It turns here, leading off to\n"+
"the east and south.  The sky is one gigantic fireball.\n";
 items=({
 "walkway",
"The rock walkway is made of a smooth brown rock, and seems to be\n"+
"riding on the flames.  It continues to the east and south",
 "flames",
"In every direction flames can be seen, burning endlessly",
 "sky",
"The sky is a single burning red fireball",
 });
 dest_dir=({
   "/players/zeus/realm/d/r30.c", "east",
   "/players/zeus/realm/d/r32.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

