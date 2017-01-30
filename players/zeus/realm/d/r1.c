inherit "room/room";	/*  r1.c  */
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
"The walkway is leading to the north and south from here.  Off in the\n"+
"distance to the north you can see various large platforms of rock\n"+
"which are riding on the flames.  Also, to the south there are a few\n"+
"other walkways which look similar to this one visible among the fire.\n";
 items=({
 "walkway",
"The rock walkway is quite smooth, leading to the north and south",
 "walkways",
"Off in the distance to the south various other rock walkways can\n"+
"be seen among the burning flames of the demon plane",
 "platforms",
"There are numerous rock platforms visible through the flames off\n"+
"to the north.  It looks as though they are carrying many demons",
 "demons",
"It looks as though there are hordes of demons riding on the large\n"+
"rock platforms which are visible off to the north",
 "flames",
"There are flames rising up all around.  In every direction that you\n"+
"look, flames view your vision",
 });
 dest_dir=({
   "/players/zeus/realm/d/p1.c", "north",
   "/players/zeus/realm/d/r3.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
