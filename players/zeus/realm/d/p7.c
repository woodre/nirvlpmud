inherit "room/room";	/*  p7.c  */
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
"The walkway ends here, leading only to the north from here.  Looking\n"+
"off to the southeast, a vast expanse of endlessly burning flames can\n"+
"be seen.  It is a truly beautiful sight.  The heat is consuming you.\n"+
"Far off to the southeast rock platforms can be seen among the flames.\n";
 items=({
   "walkway",
"The rock walkway leads to the north.  It is made of a grainy brown\n"+
"rock that seems to be unaffected by the flames",
   "flames",
"There are flames everywhere, there is no place to hide.  As you stare\n"+
"into the depths of them, they almost seem alive",
   "platforms",
"The platforms are very far away and hard to see for the flames",
 });
 dest_dir=({
   "/players/zeus/realm/d/r31.c", "north", });
}

exit(){  if(this_player()) this_player()->clear_fight_area(); }
realm(){   return "NT";  }
okay_follow() { return 1; }