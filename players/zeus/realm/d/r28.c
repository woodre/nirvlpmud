inherit "room/room";	/*  r28.c  */
#include "/players/zeus/realm/d/defs.h"

reset(arg){

 if(!random(DC))
   move_object(clone_object(
	   "/players/zeus/realm/NPC/demon_small.c"), this_object());

	if(arg) return;

 short_desc="The demon plane";
 long_desc=
"All around you flames are burning endlessly.  You are standing upon\n"+
"a rock walkway which leads through the flames.  It turns at this\n"+
"point, continuing to the north and west.  There is no other solid\n"+
"surfaces anywhere to be seen.\n";
 set_light(1);
 set_no_clean(1);
 items=({
  "walkway",
"The walkway which you are standing on is made of a smooth rock, and\n"+
"seems to be resting on the flames beneath it.  It leads to the north\n"+
"and west from this point",
  "flames",
"There are flames all around you, in every direction.  The only thing\n"+
"which is not made of flames is the walkway beneath you",
 });
 dest_dir=({
   "/players/zeus/realm/d/r23.c", "north",
   "/players/zeus/realm/d/r27.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

