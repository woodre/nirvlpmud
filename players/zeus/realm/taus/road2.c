inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;

  if(arg) return;
  short_desc="The Fallen Lands";
  long_desc=
"The path is fairly wide here, and the forest is thick.  There are\n"+
"quite a few stumps in the forest.  Up above the branches cross over\n"+
"each side of the path, making it feel more like a tunnel.  A large\n"+
"boulder is sitting amongst the trees on the west edge of the path\n";
  set_light(1);
  items=({
	"path",
"The path is about six feet wide here, and is very uneven.  There are\n"+
"many small holes that make it hard to walk on",
	"holes",
"The holes in the path make it extremely difficult to walk on",
	"forest",
"The forest is very thick here, making it hard to see to the east or\n"+
"west.  The trees block out nearly all of the light",
	"trees",
"The trees are very thick here, making it hard to see to the east or\n"+
"west.  They block out nearly all of the light",
	"stumps",
"There are some stumps in the forest here.  They look as though the\n"+
"trees were knocked over and then taken away",
	"branches",
"The branches criss-cross in such away that it makes you feel like\n"+
"you're in a tunnel and not a forest.  They block out nearly all light",
	"boulder",
"The huge boulder is half covered in moss.  There are some small mushrooms\n"+
"growing around the base of the boulder",
   "mushrooms",
"The mushrooms are only a few inches tall, and have small, irregularly\n"+
"shaped brown spots on them",
   "sky",
"The blue sky is for the most part hidden through the trees",
  });
  dest_dir=({
"/players/zeus/realm/taus/road3.c", "northwest",
"/players/zeus/realm/taus/road5.c", "east",
"/players/zeus/realm/taus/road1.c", "south",
 });
}

init(){
  ::init();
  add_action("nw_dir", "northwest");
  add_action("e_dir", "east");
  add_action("s_dir", "south");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT";    }
