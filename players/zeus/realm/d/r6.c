inherit "room/room";	/*  r6.c  */
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
"Here the walkway leads to the east and west.  Off to the south, there\n"+
"are numerous other rock walkways visible through the flames.  Also, to\n"+
"the north there are large rock platforms visible.  The heat which is\n"+
"all around you is almost unbearable.\n";
 items=({
 "walkway",
"The rock walkway is rather smooth, leading to the east and west.\n"+
"Looking beneath the walkway, all that is visible are flames",
 "walkways",
"Off to the south, numerous other similar walkways are visible",
 "platforms",
"Primarily visible to the north from here, there are large, flat rock\n"+
"platforms riding on the flames.  Each one appears to be carrying large\n"+
"hordes of small black demons",
 "demons",
"There are many hordes of demons riding on the platforms which are\n"+
"visible to the north from here.  Many screams can be heard over the\n"+
"flames coming from them",
 "flames",
"The ever burning flames are what makes up this plane.  There is no\n"+
"place to hide from the immense heat which is being made by the fires",
 });
 dest_dir=({
   "/players/zeus/realm/d/r7.c", "east",
   "/players/zeus/realm/d/r5.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

