inherit "room/room";	/*  r11.c  */
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
"The rock walkway leads to the north and south from this point.  Off\n"+
"to the west and south, numerous other walkways can be seen.  Off to\n"+
"the east various large platforms of rock can be seen.  The heat that\n"+
"is coming from the flames is almost unbearable.\n";
 items=({
   "walkway",
"The rock walkway leads to the north and south.  It is quite smooth,\n"+
"very flat, and made of a grainy brownish looking rock",
   "flames",
"There are flames all around, the heat from which is immense",
   "platforms",
"Far off in the distance to the east, large platforms of rock are\n"+
"visible among the flames carrying hordes of small demons",
   "demons",
"There appear to be many small demons riding on each of the platforms\n"+
"visible off in the distance.  They are quite far away",
   "walkways",
"There are a few other walkways visible which look similar to this one",
 });
 dest_dir=({
   "/players/zeus/realm/d/r7.c", "north",
   "/players/zeus/realm/d/r16.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }