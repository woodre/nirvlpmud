inherit "room/room";	/*  r3.c  */
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
"The walkway curves here, heading off to the north and east.  In\n"+
"the distance to the south, numerous other walkways are visible.\n"+
"Off to the north, various large platforms of rock can be seen\n"+
"riding on the flames.  It is very hot.\n";
 items=({
 "walkway",
"The walkway is made of a smooth brown rock, and leads north and\n"+
"east from here",
 "walkways",
"Off to the south, various other walkways can be seen which look\n"+
"very similar to the one you are standing on now",
 "platforms",
"The large flat rock platforms are carrying many small planar demons.\n"+
"They are all quite a distance away",
 "demons",
"The small planar demons are very hard to see from this distance",
 "flames",
"There are flames all around you.  The walkways and platforms seem\n"+
"to be riding on them.  They heat is almost unbearable",
 });
 dest_dir=({
   "/players/zeus/realm/d/r1.c", "north",
   "/players/zeus/realm/d/r4.c", "east", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

