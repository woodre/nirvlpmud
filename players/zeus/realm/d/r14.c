inherit "room/room";	/*  r14.c  */
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
"At this point on the rock walkway, it divides into three seperate\n"+
"directions.  You can continue north, east or west from this point.\n"+
"Looking out across the flames, you can see various other walkways\n"+
"which seem to be riding on the flames.\n";
 items=({
 "walkway",
"This rock walkway divides into three different directions at this\n"+
"point.  There are numerous other walkways visible in the distance",
 "flames",
"The flames are burning all around.  The walkways seem to be riding\n"+
"on them",
 });
 dest_dir=({
   "/players/zeus/realm/d/r10.c", "north",
   "/players/zeus/realm/d/r15.c", "east",
   "/players/zeus/realm/d/r13.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
