inherit "room/room";	/*  circle2.c  */

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
"This is a clear path that leads through a dark part of the forest.  The\n"+
"path itself is covered in brown leaves which look eerie in the darkness.\n"+
"The forest is very dense all around the path, and looks especially\n"+
"strange to the southeast, where a soft mist is clinging to the trees.\n";
 set_light(0);
 items=({
   "forest",
"The forest is very dark and dense around the path, however the path is\n"+
"very clearly defined.  A soft mist lurks around the trees to the southeast",
   "trees",
"The forest consists mainly of evergreen and maple trees, which are\n"+
"blocking out all natural light.  In every direction the forest is\n"+
"very dense and forboding",
   "mist",
"The soft mist which is clinging to the trees to the southeast of the\n"+
"path makes the forest seem alive.  It does not seem to be crossing\n"+
"the path however",
   "path",
"The path you are on leads to the northeast and southwest.  It is very\n"+
"clearly defined and covered in brown leaves.  There appears to be no\n"+
"way to deviate from it here",
   "leaves",
"The brown leaves which are scattered across the path look strange\n"+
"in the darkness",
 });
 dest_dir=({
   "/players/zeus/realm/taus/circle1.c", "northeast",
   "/players/zeus/realm/taus/circle4.c", "southwest",
 });
}

void init(){
  ::init();
  add_action("ne_dir", "northeast");
  add_action("sw_dir", "southwest");
  add_action("mist_dir", "southeast");
}
