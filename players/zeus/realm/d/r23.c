inherit "room/room";	/*  r23.c  */
#include "/players/zeus/realm/d/defs.h"

reset(arg){

 if(!random(DC))
   move_object(clone_object(
	   "/players/zeus/realm/NPC/demon_small.c"), this_object());

	if(arg) return;

 short_desc="The demon plane";
 long_desc=
"You are standing on a rock walkway which is winding through the demon\n"+
"plane.  As you look around, it appears to be the only solid surface to\n"+
"stand on.  All around the walkway flames are burning constantly.  The\n"+
"heat is constant, pummeling you in waves.  There is no relief.\n";
 set_light(1);
 set_no_clean(1);
 items=({
  "walkway",
"The walkway is made of smooth rock, and appears to be the only solid\n"+
"surface in this whole plane.  All around it, above and below flames\n"+
"are burning constantly",
  "flames",
"The flames are the only other thing in this plane besides the demons\n"+
"and the single walkway upon which you stand.  There is no place to\n"+
"hide from the constant heat",
 });
 dest_dir=({
   "/players/zeus/realm/d/r18.c", "north",
   "/players/zeus/realm/d/r28.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
