inherit "room/room";	/*  r20.c  */
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
"The walkway ends here, continuing only back to the south.  Looking\n"+
"around you, numerous other walkways are visible, all of which seem\n"+
"to be floating on the flames which burn endlessly in every direction.\n";
 items=({
 "walkway",
"The smooth rock walkway is the only solid surface around you.  There\n"+
"are numerous other walkways visible in the distance",
 "flames",
"There are flames burning all around, in every direction",
 });
 dest_dir=({
   "/players/zeus/realm/d/r25.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
