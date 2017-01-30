inherit "room/room";	/*  r22.c  */
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
"The walkway leads to the north and west from here.  There is no way\n"+
"to deviate from the walkway at all, for there are flames all around.\n"+
"Off in the distance to the north and west various other walkways can\n"+
"be seen, and off to the east some platforms are visible.\n";
 items=({
   "walkway",
"The rock walkway bends here, leading off to the north and west",
   "walkways",
"There are a few other walkways visible through the flames, mainly\n"+
"to the north and west",
   "platforms",
"Off to the east, through the flames some large rock platforms can\n"+
"be seen, each of which appears to be carrying many small demons",
   "demons",
"The demons are very far away and hard to see",
   "flames",
"The flames are all around you.  There is no way to escape the heat",
 });
 dest_dir=({
   "/players/zeus/realm/d/r16.c", "north",
   "/players/zeus/realm/d/r21.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }