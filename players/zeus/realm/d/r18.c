inherit "room/room";	/*  r18.c  */
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
"The rock walkway splits into three different directions at this point.\n"+
"In every direction all that can be seen are flames.  Unending heat is\n"+
"beating down on your body, making it very hard to breathe.\n";
 items=({
  "walkway",
"The brown walkway splits into three different directions at this\n"+
"point.  It is made of a smooth rock which has indured the unending\n"+
"heat for ages",
  "flames",
"The only thing to look at in this plane besides the walkway which you\n"+
"stand upon, is the flames, which rise up around you in every direction",
 });
 dest_dir=({
   "/players/zeus/realm/d/r12.c", "north",
   "/players/zeus/realm/d/r19.c", "east",
   "/players/zeus/realm/d/r23.c", "south",  });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
