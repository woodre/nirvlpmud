inherit "room/room";	/*  circle5.c  */

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
"You are on a path strewn with leaves that winds through the darkness\n"+
"of the forest.  The forest is very dense, and there appears to be no\n"+
"way to leave the path.  A strange looking mist is hovering among the\n"+
"trees west of the path.\n";
 set_light(0);
 items=({
   "forest",
"The trees tend to grow very close together, making the forest quite\n"+
"dense.  The forest is dark in every direction from here",
   "trees",
"The evergreen and maple trees are very tall.  Almost all light is\n"+
"blocking out by the trees",
   "mist",
"A strange looking mist drifts between the trees to the west of the\n"+
"path.  At no point does the mist cross over the path",
   "path",
"The dark path is covered in brown leaves",
   "leaves",
"The leaves are scatted all across the path.  They look eerie in the\n"+
"darkness of the forest",
 });
 dest_dir=({
   "/players/zeus/realm/taus/circle3.c", "northwest",
   "/players/zeus/realm/taus/circle7.c", "southwest",
 });
}

void init(){
  ::init();
  add_action("nw_dir", "northwest");
  add_action("sw_dir", "southwest");
  add_action("mist_dir", "west");
}
