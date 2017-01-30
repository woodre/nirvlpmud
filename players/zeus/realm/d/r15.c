inherit "room/room";	/*  r15.c  */
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
"This is a rock walkway leading to the east and west.  In every\n"+
"direction an endless scape of flames can be seen, the heat from\n"+
"which is amazing.  There are a few other walkways visible similar\n"+
"to the one you are on now.\n";
 items=({
   "flames",
"The flames are burning red hot, and seem to be fueled by some sort\n"+
"of dark magic.  The heat is almost unbearable",
   "walkway",
"The rock walkway leads to the east and west, and is brownish",
   "walkways",
"There are a few other walkways visible through the flames,\n"+
"however none are accessable from this point",
 });
 dest_dir=({
   "/players/zeus/realm/d/r16.c", "east",
   "/players/zeus/realm/d/r14.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }