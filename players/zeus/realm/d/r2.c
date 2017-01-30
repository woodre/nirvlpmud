inherit "room/room";	/*  r2.c  */
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
"This is a rock walkway leading through the flames of the demon plane.\n"+
"It leads to the north and south, and there is no way to deviate from\n"+
"it.  On either side of you an endless expanse of flames is visible.\n"+
"Far off to the north and east large platforms of rock can be seen.\n";
 items=({
   "platforms",
"Far off in the distance to the north and east, large platforms of rock\n"+
"can be seen carrying hordes of small demons",
   "demons",
"There appear to be many small demons riding on each of the platforms\n"+
"visible off in the distance",
   "flames",
"In every direction that you look flames are visible",
   "walkway",
"The rock walkway leads to the north and south.  It is rather smooth,\n"+
"from the constant exposure to the flames.  There is no way to deviate\n"+
"from its path",
 });
 dest_dir=({
   "/players/zeus/realm/d/p2.c", "north",
   "/players/zeus/realm/d/r7.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }