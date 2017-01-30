#include <ansi.h>
inherit "room/room";	/*  ent.c  */

reset(arg){
	if(arg) return;

 short_desc="The demon plane";
 long_desc=
"All around you flames are rising up, burning endlessly.  You are\n"+
"standing on a walkway made of brown rock, around which flames are\n"+
"burning.  The strange trail leads off in numerous directions from\n"+
"this point.  Directly above you is a shimmering red vortex.\n";
 set_light(1);
 items=({
  "flames",
"There are flames burning all around you.  In every direction that\n"+
"you look, flames can be seen.  The heat is almost unbearable",
  "walkway",
"A strange walkway has been constructed here.  It is made of brown\n"+
"rock, and seems to be riding on the flames.  It leads off in a\n"+
"few directions from this point",
  "vortex",
"Directly above you is a shimmering red vortex that you could enter.\n"+
"It presumably leads out of this plane",
 });
 dest_dir=({
   "/players/zeus/realm/d/r13.c", "north",
   "/players/zeus/realm/d/r24.c", "south",
   "/players/zeus/realm/d/r19.c", "west",  });
}

void init(){ 
  ::init(); 
  add_action("enter_cmd", "enter"); 
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }

enter_cmd(str)
{
  if(str != "vortex") return 0;
  write("You step into the vortex...\n\n\n"+
	  RED+"\t\tBurning flames consume you...\n\n\n"+NORM);
  this_player()->hit_player(25);
  this_player()->move_player(
	  "into the red vortex#players/zeus/realm/d/vortex.c");
  return 1;
}

