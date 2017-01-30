inherit "room/room";	/*  circle4.c  */

int teleport, wall;

#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"
#include "/players/zeus/realm/taus/mist.h"

reset(arg){
 if(arg) return;

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;
 wall = 0;
 set_no_clean(1);

 short_desc="The Fallen Lands";
 long_desc=
"At this point the trees block out much of the light, making it feel like\n"+
"night all around.  The path is very clearly defined, which leads through\n"+
"the forest in three different directions from here.  The path is covered\n"+
"by a layer of brown leaves.  A soft mist lurks among the trees to the\n"+
"east, making it look almost alive.\n";
 set_light(0);
 items=({
   "forest",
"The forest is so dark here that it feels like night.  The trees are\n"+
"growing close together, blocking out the sky",
   "trees",
"The forest consists primarily of evergreen and maple trees, all of which\n"+
"seem to be growing very close together, blocking out the light",
   "mist",
"The mist to the east is flowing around the trees, making the forest\n"+
"seem alive.  The mist does not seem to be crossing the path",
   "path",
"The path is covered by a layer of brown leaves.  It leads away from\n"+
"here in three different directions",
   "leaves",
"The path is covered by a layer of brown leaves that look very strange\n"+
"in the darkness of the forest",
 });
 dest_dir=({
   "/players/zeus/realm/taus/circle2.c", "northeast",
   "/players/zeus/realm/taus/circle6.c", "southeast",
   "/players/zeus/realm/taus/guth16.c", "west",
 });
}

void init(){
  ::init();
  add_action("ne_dir", "northeast");
  add_action("se_dir", "southeast");
  add_action("w_dir", "west");
  add_action("wall", "west");
  add_action("mist_dir", "east");
}

wall(){
  if(1 == wall && !this_player()->query_ghost())
  {
    write("A strong force is stopping you from going west.\n");
    return 1;
  }
}

set_wall(x){ wall = x; }
query_wall(){ return wall; }

