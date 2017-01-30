inherit "room/room";	/*  r17.c  */
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
"The rock walkway leads to the east and west from this point.  To\n"+
"the north and south, flames are rising up all around.  There are\n"+
"a few other walkways visible off to the west.  There are also some\n"+
"large platforms of rock visible to the east.\n";
 items=({
   "walkway",
"The rock walkway is brownish and quite smooth.  It leads to the east\n"+
"and west from where you stand on it",
   "walkways",
"Numerous other walkways are visible among the flames off in the\n"+
"distance.  You can't get to them from here",
   "platforms",
"There are some large, flat rock platforms visible off to the east.\n"+
"They are hard to see through the flames, but it looks as though\n"+
"they are carrying many demons",
   "demons",
"They are hard to see because of the flames, but there appear to be\n"+
"many small demons riding on the platforms to the east",
   "flames",
"There are flames visible in every direction that you look.  The heat\n"+
"that is being produced by them is almost unbearable",
 });
 dest_dir=({
   "/players/zeus/realm/d/p4.c", "east",
   "/players/zeus/realm/d/r16.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }