inherit "room/room";	/*  circle7.c  */

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
"This is a path that winds through a dark part of the forest.  The path\n"+
"is covered in dark brown leaves.  To the northwest there is a soft\n"+
"mist lurking among the trees.  There appears to be no way to deviate\n"+
"from the path.\n";
 set_light(0);
 items=({
   "forest",
"The forest is dark, however it does not crowd the path, which is very\n"+
"clearly defined.  There appears to be no way to deviate from the path",
   "trees",
"All of the trees climb high into the sky, blocking it out.  The trees\n"+
"appear to mainly be maple and evergreen trees",
   "sky",
"Only small blotches of sky are visible through the dense trees which\n"+
"tower over you",
   "mist",
"To the northwest a soft mist lurks among the trees.  It flows slowly\n"+
"and very smoothly, as though it is almost alive",
   "path",
"The path which is covered in leaves winds through the dark trees.  It\n"+
"is very clearly defined, as though it is used often",
   "leaves",
"Many brown and golden leaves cover the path",
 });
 dest_dir=({
   "/players/zeus/realm/taus/circle5.c", "northeast",
   "/players/zeus/realm/taus/circle8.c", "southwest",
 });
}

void init(){
  ::init();
  add_action("ne_dir", "northeast");
  add_action("sw_dir", "southwest");
  add_action("mist_dir", "northwest");
}
