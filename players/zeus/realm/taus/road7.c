inherit "room/room";
#include "/players/zeus/closed/all.h"    /* road7 */
#include "/players/zeus/closed/fl_demon.h"

int teleport, guth, clone;

reset(arg){

    teleport = 0;  if(random(TFL_TLP)) teleport = 1;

    if(!present("gurther")){   clone = random(9);   switch(clone){
    case 0..6: break;
    case 7:  MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
    case 8: for(guth = 0; guth < 2; guth++)
              MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
    return 1; }}

    if(arg) return;
  short_desc="The Fallen Lands";
  long_desc=
"The path you are on leads north and south through the forest.  To the\n"+
"south is a small river with a wooden bridge crossing over it.  On both\n"+
"sides of the path tall trees climb high into the sky, their branches\n"+
"crossing over the path blocking out much of the sky.  The path is\n"+
"scattered with brown leaves.\n";
  set_light(1);
  items=({
	"path",
"The path leads north and south through the trees.  It is uneven and\n"+
"scattered with brown leaves of various shapes and sizes.  The path is\n"+
"a little muddy in places",
	"forest",
"The forest consists primarily of tall evergreen and maple trees.  It\n"+
"is hard to see for any distance through the trees",
	"trees",
"The trees are all very tall, their branches crossing over the path\n"+
"blocking out much of the sky",
	"branches",
"The branches criss-cross over the path, blocking out much of the\n"+
"beautiful blue sky",
    "sky",
"The blue sky is for the most part hidden by the branches of the\n"+
"evergreen and maple trees",
    "leaves",
"Some brown leaves are scatted across the path",
    "river",
"To the south a river is flowing beneath the path, running through the\n"+
"forest to the east and west.  A simple wooden bridge has been constructed\n"+
"over the river",
	"bridge",
"The wooden bridge is simply five large trees which have been placed\n"+
"over the river.  The trees are tied together by thick green vines",
    "vines",
"The thick green vines are helping to hold the bridge in place",
  });
  dest_dir=({
"/players/zeus/realm/taus/guth15.c", "north",
"/players/zeus/realm/taus/road6.c", "south",
 });
}

init(){
  ::init();
  add_action("n_dir", "north");
  add_action("s_dir", "south");
}

exit(){    if(this_player()) this_player()->clear_fight_area();   }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT";    }
