inherit "room/room";	/*  r9.c  */
#include "/players/zeus/realm/d/defs.h"

reset(arg){

 if(!random(DC))
   move_object(clone_object(
	   "/players/zeus/realm/NPC/demon_small.c"), this_object());

	if(arg) return;

 short_desc="The demon plane";
 long_desc=
"The walkway turns at this pointing, heading to the west and to the\n"+
"south.  In every direction flames burn endlessly.  The sky is a mass\n"+
"of burning flames.  The heat is almost unbearable.\n";
 set_light(1);
 set_no_clean(1);
 items=({
 "walkway",
"The rock walkway leads to the south and west from where you stand.\n"+
"It is floating on the flames which burn up all around",
 "flames",
"There is no place to escape from the flames of the demon plane",
 "sky",
"When you look up, all that can be seen is flames.  It is almost as\n"+
"though the sky itself is on fire",
 });
 dest_dir=({
   "/players/zeus/realm/d/r12.c", "south",
   "/players/zeus/realm/d/r8.c", "west",  });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

