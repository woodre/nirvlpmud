inherit "room/room";
#include "/players/zeus/closed/all.h"    /* road6 */
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
"The path leads to the north and south through the forest.  The path\n"+
"itself is rather wide, very uneven, and scattered with brown leaves.\n"+
"The trees of the forest rise up all around, their branches reaching\n"+
"across the path blocking out most of the sky  There is a river to the\n"+
"north, and a small wooden bridge that crosses over it.\n";
  set_light(1);
  items=({
	"path",
"The path leads north and south through the trees.  It is uneven and\n"+
"scattered with brownish leaves",
	"forest",
"The forest is very thick here, making it hard to see very far into it\n"+
"to either the west or east",
	"trees",
"The trees are all very tall, their branches crossing over the path\n"+
"blocking out much of the sky",
	"branches",
"The branches criss-cross over the path, blocking out much of the sky",
    "sky",
"The blue sky is for the most part hidden through the trees",
    "leaves",
"Some brown leaves are scatted across the path",
    "river",
"To the north a river can be seen and heard flowing beneath a small\n"+
"wooden bridge",
	"bridge",
"The wooden bridge is simply four large trees which have been placed\n"+
"over the river.  The trees, which have been stripped clean of their\n"+
"branches, are tied together by thick green vines",
    "vines",
"The thick green vines are helping to hold the bridge in place",
  });
  dest_dir=({
"/players/zeus/realm/taus/road7.c", "north",
"/players/zeus/realm/taus/road5.c", "south",
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
