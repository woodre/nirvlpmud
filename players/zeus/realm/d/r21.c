inherit "room/room";	/*  r21.c  */
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
"The walkway bends here, leading only to the east and south.  There is\n"+
"no way to deviate from the walkway.  There are red hot flames everywhere,\n"+
"and there is no way to escape the heat.  There are some other walkways\n"+
"visible off to the north and west.\n";
 items=({
   "walkway",
"The rock walkway is brown and rather smooth.  It leads to the east\n"+
"and south from here",
   "walkways",
"There are a few other walkways visible through the flames, all of\n"+
"which look just like the one you are standing on now",
   "flames",
"The flames are everywhere.  The seem to be fueled by some sort of\n"+
"dark magic.  The heat is tremendous",
 });
 dest_dir=({
   "/players/zeus/realm/d/r22.c", "east",
   "/players/zeus/realm/d/r26.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }