inherit "room/room";	/*  r25.c  */
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
"You are standing on a rockway which winds through the demon plane.\n"+
"All around all that can be seen are waves upon waves of unending\n"+
"flames.  There is no escape.  The walkway continues to the north,\n"+
"and back to the west from this point.\n";
 items=({
 "walkway",
"The walkway is made of a brown rock, and winds through the flames\n"+
"which make up this plane",
 "flames",
"The main characteristic of this plane, in every direction that you\n"+
"look almost all that fills you view is unending flames",
 });
 dest_dir=({
   "/players/zeus/realm/d/r20.c", "north",
   "/players/zeus/realm/d/r24.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
