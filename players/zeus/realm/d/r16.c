inherit "room/room";	/*  r16.c  */
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
"You are standing on a central platform of rock, from which four\n"+
"seperate walkways lead.  There are flames visible all around, the\n"+
"heat from which is next to unbearable.  Far off to the east there\n"+
"are numerous platforms of rock visible among the flames.\n";
 items=({
   "flames",
"There are endless flames curling up around the walkways.  The heat\n"+
"is neverending",
   "walkways",
"Four brown rock walkways lead away from here, to the north, east,\n"+
"south and west",
  "platform",
"You are standing on a somewhat large and almost circular shaped\n"+
"platform of brownish, smooth rock",
  "platforms",
"Off to the east, numerous large platforms of rock can be seen riding\n"+
"on the endless expanse of flames",
 });
 dest_dir=({
   "/players/zeus/realm/d/r11.c", "north",
   "/players/zeus/realm/d/r17.c", "east",
   "/players/zeus/realm/d/r22.c", "south",
   "/players/zeus/realm/d/r15.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }