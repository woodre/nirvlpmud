inherit "room/room";	/*  r24.c  */
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
"The rock walkway seperates into three different directions at this\n"+
"point.  Looking to the east and west you can see more walkways off\n"+
"in the distance, however there is much fire inbetween you and them.\n"+
"There is flames rising up all around this place.\n";
 items=({
 "walkway",
"The walkway is made of a smooth brown rock, and goes in three different\n"+
"directions from this point.  Off in the distance you can see a few\n"+
"other walkways",
 "fire",
"All around you fire rises up, burning endlessly.  There appears to be\n"+
"no way to find relief from the endless heat",
 "flames",
"There are flames all around you.  The sky is one gigantic fireball, and\n"+
"beneath the walkway all you can see are more flames",
 "sky",
"The sky is one gigantic mass of fire",
 });
 dest_dir=({
   "/players/zeus/realm/d/ent.c", "north",
   "/players/zeus/realm/d/r25.c", "east",
   "/players/zeus/realm/d/r30.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
