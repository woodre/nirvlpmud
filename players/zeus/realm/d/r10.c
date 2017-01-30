inherit "room/room";	/*  r10.c  */
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
"The walkway is moderatly narrow here, as it seems to ride on the\n"+
"flames which are all around.  It is leading to the north and south\n"+
"from here.  Off in the distance numerous other walkways can be seen.\n";
 items=({
 "walkway",
"This walkway leads to the north and south.  It is made of a smooth\n"+
"brown rock, and is moderatly narrow at this point",
 "walkways",
"Looking off in the distance, numerous other walkways can be seen,\n"+
"all of which look similar to the one you are on now",
 "flames",
"There are burning hot flames all around",
 });
 dest_dir=({
   "/players/zeus/realm/d/r5.c", "north",
   "/players/zeus/realm/d/r14.c", "south", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }
