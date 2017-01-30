inherit "room/room";	/*  r19.c  */
#include "/players/zeus/realm/d/defs.h"

reset(arg){

 if(!random(DC))
   move_object(clone_object(
	   "/players/zeus/realm/NPC/demon_small.c"), this_object());

	if(arg) return;

 short_desc="The demon plane";
 long_desc=
"You are standing on a rock walkway which leads through the flames\n"+
"of this place.  Flames can be seen all around you, the waves of\n"+
"heat pressing against you.  The walkway continues to the east and\n"+
"west from this point.\n";
 set_light(1);
 set_no_clean(1);
 items=({
  "flames",
"The flames are all around you.  Looking up, all you can see is\n"+
"flames burning endlessly.  Beneath the walkway, only fire can\n"+
"be seen",
  "walkway",
"The brown rock walkway leads to the east and west from this point.\n"+
"It seems to be floating on the flames",
 });
 dest_dir=({
   "/players/zeus/realm/d/ent.c", "east",
   "/players/zeus/realm/d/r18.c", "west",  });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
