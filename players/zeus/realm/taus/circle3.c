inherit "room/room";	/*  circle3.c  */

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
"This is a dark part of the forest.  You are on a path that winds\n"+
"through the trees.  Leaves are scattered all over the path.  A\n"+
"soft mist is lurking among the trees southwest of the path.\n";
 set_light(0);
 items=({
   "forest",
"The forest consists mainly of evergreen and maple trees.  They\n"+
"block out much of the sky, making the forest feel like night",
   "trees",
"The evergreen and maple trees all tower high above your head,\n"+
"blocking out almost all of the sky",
   "mist",
"To the southwest a soft mist slow moves between the trees.  The\n"+
"mist does not seem to cross over the path at any point",
   "path",
"The path you walk upon is very clearly defined among the trees.\n"+
"It is almost entirely covered in dark brown leaves",
   "leaves",
"Multicolored leaves are scattered over the path",
 });
 dest_dir=({
   "/players/zeus/realm/taus/circle1.c", "northwest",
   "/players/zeus/realm/taus/circle5.c", "southeast",
 });
}

void init(){
  ::init();
  add_action("nw_dir", "northwest");
  add_action("se_dir", "southeast");
  add_action("mist_dir", "southwest");
}
