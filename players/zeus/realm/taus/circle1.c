inherit "room/room";	/*  circle1.c  */

int teleport;

#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"
#include "/players/zeus/realm/taus/mist.h"

reset(arg){
 if(arg) return;

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;
 set_no_clean(1);

 short_desc="The Fallen Lands";
 long_desc=
"You are on a path that leads through a dark part of the forest.  It\n"+
"curves here, leading to the southwest and southeast.  The forest to\n"+
"the south seems to be enshrouded in a soft mist.  The path is covered\n"+
"in a layer of brown leaves.  To the north the forest is very dark.\n";
 set_light(0);
 items=({
   "forest",
"The forest is very dark and dense around the path.  There is a soft\n"+
"mist lurking around the trees to the south",
   "trees",
"The towering evergreen and maple trees climb high into the sky.  They\n"+
"make the forest very dark and dense",
   "mist",
"There is a soft mist lurking around the trees to the south of the path.\n"+
"It does not seem to be coming past the path.  It makes the forest feel\n"+
"almost alive",
   "path",
"The very clearly defined path leads through the forest to the southwest\n"+
"and southeast from here.  It is covered by a a layer of brown leaves",
   "leaves",
"The brown leaves look very creepy in the darkness",
 });
 dest_dir=({
   "/players/zeus/realm/taus/circle3.c", "southeast",
   "/players/zeus/realm/taus/circle2.c", "southwest",
 });
}

void init(){
  ::init();
  add_action("se_dir", "southeast");
  add_action("sw_dir", "southwest");
  add_action("mist_dir", "south");
}
