inherit "room/room";	/*  p3.c  */
#include "/players/zeus/realm/d/defs.h"

reset(arg){

 if(!random(DC))
   move_object(clone_object(
	   "/players/zeus/realm/NPC/demon_small.c"), this_object());

	if(arg) return;

 short_desc="The demon plane";
 long_desc=
"The walkway ends here, beyond which is a wall of flames.  In every\n"+
"direction that you look, all that can be seen are the fires which\n"+
"exist in this plane.  The only way to go is back to the east.\n";
 set_light(1);
 set_no_clean(1);
 items=({
  "walkway",
"The smooth rock walkway is the only solid surface in this place.\n"+
"There is no way to deviate from it in any way, without plummeting\n"+
"into the flames",
  "flames",
"All around you flames are burning constantly.  The heat is almost\n"+
"unbearable.  There is no escape",
 });
 dest_dir=({
	 "/players/zeus/realm/d/r8.c", "east",  });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
