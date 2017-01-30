inherit "room/room";	/*  r8.c  */
#include "/players/zeus/realm/d/defs.h"

reset(arg){

 if(!random(DC))
   move_object(clone_object(
	   "/players/zeus/realm/NPC/demon_small.c"), this_object());

	if(arg) return;

 short_desc="The demon plane";
 long_desc=
"You are standing on a walkway leading through the demon plane.  All\n"+
"around you flames are burning endlessly.  The heat which is all\n"+
"around you is nearly unbearable.  The walkway continues to the east\n"+
"and west from this point.\n";
 set_light(1);
 set_no_clean(1);
 items=({
  "walkway",
"The smooth rock walkway seems to be floating on the flames.  It is\n"+
"the only safe place to walk in this place",
  "flames",
"The flames rise up all around you.  There is no escape in this place\n"+
"from the unending heat which pours out from them",
 });
 dest_dir=({
   "/players/zeus/realm/d/r9.c", "east",
   "/players/zeus/realm/d/p3.c", "west", });
 set_heart_beat(1);
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

heart_beat(){
  tell_room(this_object(), "A honey bee flies into the room.\n");
}
