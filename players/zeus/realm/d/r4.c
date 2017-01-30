inherit "room/room";	/*  r4.c  */
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
"The walkway leads to the east and west here.  Looking out among the\n"+
"flames, numerous other walkways can be seen, which are all similar\n"+
"to this one.  Far off to the north there are large platforms of rock.\n";
 items=({
 "walkway",
"The smooth walkway is made of a brownish rock, and leads to the east\n"+
"and west from where you stand now",
 "walkways",
"Looking off into the distance, numerous other walkways similar to\n"+
"this one can be seen riding on the flames",
 "flames",
"There are flames all around.  They are incredibly hot, make it very\n"+
"uncomfortable for you to breathe",
 "platforms",
"The large, flat rock platforms are carrying hordes of planar demons",
 "demons",
"The demons are hard to see from this distance",
 });
 dest_dir=({
   "/players/zeus/realm/d/r5.c", "east",
   "/players/zeus/realm/d/r3.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

