inherit "room/room";	/*  circle6.c  */

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
"You are on a path that winds through a dark part of the forest.  The\n"+
"path leads to the northwest and southeast from here.  There is a\n"+
"strange mist around the trees to the northeast of the path.  The\n"+
"path is scattered with many brown leaves that looks odd in the darkness\n"+
"of the forest.  The forest feels almost alive.\n";
 set_light(0);
 items=({
   "forest",
"The forest is dark here, and feels strangely alive",
   "trees",
"There are many maple trees scattered among the forest of evergreens",
   "mist",
"A soft mist drifts slowly about the trees to the northeast of the\n"+
"path.  At no point does the mist seem to cross the path",
   "path",
"The path is clearly defined leading through the forest.  Many leaves\n"+
"are scattered across it",
   "leaves",
"The path is covered by a layer of golden brown leaves that look odd\n"+
"in the darkness of the forest",
 });
 dest_dir=({
   "/players/zeus/realm/taus/circle4.c", "northwest",
   "/players/zeus/realm/taus/circle8.c", "southeast",
 });
}

void init(){
  ::init();
  add_action("nw_dir", "northwest");
  add_action("se_dir", "southeast");
  add_action("mist_dir", "northeast");
}
