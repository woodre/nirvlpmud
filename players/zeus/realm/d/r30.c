inherit "room/room";	/*  r30.c  */
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
"You are standing on a rock walkway which is winding through the\n"+
"flames of the demon plane.  Off in the distance, far to the south,\n"+
"large flat stones can be seen carrying many small demons.  The\n"+
"walkway continues to the north and west from here.\n";
 items=({
 "walkway",
"The smooth brown rock walkway bends here, leading off to the north\n"+
"and to the west",
 "flames",
"There are flames all around the walkway, and can be seen in every\n"+
"direction.  They are the main characteristic of the demon plane",
 "stones",
"The large flat stones are floating on the flames, and are carrying\n"+
"countless numbers of small demons.  They are very far away",
 "demons",
"The small demons are too far away to see any details",
 });
 dest_dir=({
   "/players/zeus/realm/d/r24.c", "north",
   "/players/zeus/realm/d/r29.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

