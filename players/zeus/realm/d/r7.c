inherit "room/room";	/*  r7.c  */
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
"You are standing on a large platform of rock which is riding on the\n"+
"eternal flames of the demon plane.  There are three walkways leading\n"+
"away from here, to the north south and west.  Far off to the north\n"+
"and east, other gigantic platforms of rock can be seen, most of which\n"+
"are carrying large hordes of demons.\n";
 items=({
   "platform",
"You are standing on a large platform of brownish rock.  It is very flat\n"+
"and quite smooth as well",
   "platforms",
"Far off in the distance to the north and east, large platforms of rock\n"+
"can be seen carrying hordes of demons",
   "demons",
"There appear to be many small demons riding on each of the platforms\n"+
"visible off in the distance",
   "flames",
"In every direction that you look flames are visible",
   "walkways",
"There are three brownish rock walkways leading away from here.  Each\n"+
"one is quite smooth",
 });
 dest_dir=({
   "/players/zeus/realm/d/r2.c", "north",
   "/players/zeus/realm/d/r11.c", "south",
   "/players/zeus/realm/d/r6.c", "west", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
