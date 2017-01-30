inherit "room/room";	/*  p1.c  */
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
"You have come to the end of the walkway, the only exit for the living\n"+
"being back to the south.  Off to the north is a landscape of flames.\n"+
"There are various platforms of rock visible among the flames, each of\n"+
"which are carrying hordes of demons.  The heat is amazing here.\n";
 items=({
 "walkway",
"The brown rock walkway is rather smooth, and leads to the south from\n"+
"here.  Off to the south other walkways can be seen",
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
   "/players/zeus/realm/d/r1.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
