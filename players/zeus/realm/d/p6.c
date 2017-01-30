inherit "room/room";	/*  p6.c  */
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
"You are standing on the most southern point of the rock walkway.  As\n"+
"you look to the south, far off in the distance many flat rock platforms\n"+
"can be seen, each of which is carrying hundreds of demons.  The only\n"+
"way to go from point is back to the north.\n";
 items=({
 "walkway",
"The smooth brown rock walkway continues to the north from here",
 "flames",
"There are flames all around, there is no escaping the heat",
 "platforms",
"The giant flat rock platforms are riding on the flames off in the\n"+
"distance.  Each of them is carrying hundreds of small demons",
 "demons",
"There are many small demons riding on the giant rock platforms off\n"+
"in the distance.  It is very hard to see them from where you stand",
 });
 dest_dir=({
   "/players/zeus/realm/d/r32.c", "north", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
