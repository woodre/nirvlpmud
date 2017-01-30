inherit "room/room";	/*  r31.c  */
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
"You are standing on a fairly narrow part of the walkway as it winds\n"+
"through the flames.  You can only walk to the north and south from\n"+
"here.  Off in the distance, platforms of rock and various other\n"+
"similar looking walkways can be seen.  The flames are everywhere.\n";
 items=({
 "walkway",
"The rock walkway leads to the north and south from where you stand.\n"+
"It is floating on the flames which burn up all around",
 "flames",
"There is no place to escape from the flames of the demon plane",
 "sky",
"When you look up, all that can be seen is flames.  It is almost as\n"+
"though the sky itself is on fire",
  "walkways",
"There are other walkways which look like the one you are standing on\n"+
"visible among the flames",
  "platforms",
"Far off platforms of rock can be seen riding on the flames",
 });
 dest_dir=({
   "/players/zeus/realm/d/r26.c", "north",
   "/players/zeus/realm/d/p7.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
