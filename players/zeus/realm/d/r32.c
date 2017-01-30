inherit "room/room";	/*  r32.c  */
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
"From this point the walkway continues to the north and south.  Far\n"+
"to the south, large platforms of rock can be seen floating on the\n"+
"endless flames.  Each one seems to be carrying untold amounts of\n"+
"demons.  The flames can be seen burning endlessly all around.\n";
 items=({
 "walkway",
"The rock walkway continues to the north and south from where you\n"+
"stand.  Off in the distance, numerous other walkways can be seen",
 "flames",
"In every direction red hot flames can be seen.  There is no relief\n"+
"from the heat which beats down upon you",
 "platforms",
"There are countless large platforms of rock floating off in the distance\n"+
"to the south, each of which has hordes of small demons on them",
 "demons",
"The demons are very far away and quite hard to see",
 });
 dest_dir=({
   "/players/zeus/realm/d/r29.c", "north",
   "/players/zeus/realm/d/p6.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

