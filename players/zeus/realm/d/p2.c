inherit "room/room";	/*  p2.c  */
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
"The walkway ends here, only leading back to the south.  Looking off\n"+
"to the north, miles of endless flames fill your view.  Numerous\n"+
"large platforms of rock can be seen among the flames.\n";
 items=({
   "walkway",
"The smooth rock walkway leads to the south.  It is made of a grainy\n"+
"looking brown rock",
 "flames",
"The flames are all around, in every direction.  There is no place\n"+
"to escape from the immense heat",
 "platforms",
"The large platforms of rock are visible through the flames to the\n"+
"north.  Each one is carrying a horde of demons",
 "demons",
"There are many demons visible on the platforms, however they are very\n"+
"far away and thus hard to see",
 });
 dest_dir=({
   "/players/zeus/realm/d/r2.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
