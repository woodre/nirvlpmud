inherit "room/room";	/*  r12.c  */
#include "/players/zeus/realm/d/defs.h"

reset(arg){

 if(!random(DC))
   move_object(clone_object(
	   "/players/zeus/realm/NPC/demon_small.c"), this_object());

	if(arg) return;

 short_desc="The demon plane";
 long_desc=
"At this point the walkway is heading to the north and south.  On\n"+
"all sides of the walkway flames are burning ceaslessly.  Waves of\n"+
"heat are beating against you, making you feel weak and tired.\n";
 set_light(1);
 set_no_clean(1);
 items=({
  "walkway",
"The smooth rock walkway leads to the north and south from this\n"+
"point.  There is no way to travel off of the walkway",
  "flames",
"In every direction that you look, all that can be seen are flames",
 });
 dest_dir=({
   "/players/zeus/realm/d/r9.c", "north",
   "/players/zeus/realm/d/r18.c", "south",  });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
