inherit "room/room";	/*  circle8.c  */

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
"The path bends here, curving around the trees leading northeast and\n"+
"northwest.  There are many leaves covering the path, although it is\n"+
"still very clearly defined.  The forest is dark all around, and a\n"+
"soft mist is drifting among the trees north of the path.\n";
 set_light(0);
 items=({
   "forest",
"The forest is dark here, and feels strangely alive.  The only way to\n"+
"travel through the forest is via the path",
   "trees",
"There are many maple trees scattered among the forest of evergreens.\n"+
"All of the trees look very forboding in the darkness",
   "mist",
"A soft mist drists among the trees north of the path.  It makes the\n"+
"forest feel strangely alive",
   "path",
"The path, which is a few feet wide, winds through the dark forest.\n"+
"Golden brown leaves are scattered all across it",
   "leaves",
"The leaves, which are primarily golden brown, look very eerie in the\n"+
"darkness.  Many of the leaves look entirely undisturbed",
 });
 dest_dir=({
   "/players/zeus/realm/taus/circle7.c", "northeast",
   "/players/zeus/realm/taus/circle6.c", "northwest",
 });
}

void init(){
  ::init();
  add_action("ne_dir", "northeast");
  add_action("nw_dir", "northwest");
  add_action("mist_dir", "north");
}
