inherit "room/room";	/*  r26.c  */
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
"The rock walkway is fairly narrow here, leading to the north and to\n"+
"the south.  On either side of the walkway flames can be seen for what\n"+
"seems like miles.  Off to the north and west other walkways can be\n"+
"seen.  There also appear to be large rock platforms visible far off\n"+
"among the flames to the east.\n";
 items=({
   "walkway",
"The smooth rock walkway leads to the north and south from here.\n"+
"It is made of a grainy looking brown rock",
 "flames",
"The flames are all around, in every direction.  There is no place\n"+
"to escape from the immense heat",
 "platforms",
"The large platforms of rock are visible through the flames to the\n"+
"east primarily.  Each one is carrying a horde of demons",
 "demons",
"There are many demons visible on the platforms, however they are very\n"+
"far away and thus hard to see any details",
  "walkways",
"There are other walkways similar to the one you are standing on off\n"+
"to the north and west.  They can't be reached from here however",
 });
 dest_dir=({
   "/players/zeus/realm/d/r21.c", "north",
   "/players/zeus/realm/d/r31.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }