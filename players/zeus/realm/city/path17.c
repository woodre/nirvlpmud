inherit "room/room";
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;
  if(!present("troll")) MO(CO("/players/zeus/realm/NPC/troll1.c"), TO);

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The path is muddy in certain places, and the outlines of various\n"+
"animal paw prints are clearly defined.  The path continues slightly\n"+
"to the north but leads into a mass of forest.  To the east the path\n"+
"continues all the way to the river.  To the south and west the forest\n"+
"is very thick, making travel impossible.\n";
  items=({
   "trees",
"The evergreen trees are growing very close together here.  Travel is\n"+
"blocked to the north, west, and south",
   "path",
"The dirt path here is quite muddy and very uneven.  In many places the\n"+
"prints of some type of creature can be seen distinctly",
   "prints", 
"The paw prints are leading to and from the river to the east",
   "paw prints", 
"The paw prints are leading to and from the river to the east",
   "forest",
"The forest is quite thick here, although it is not really crowding the\n"+
"path.  To the north, west, and south the forest is so thick that travel\n"+
"would be entirely impossible",
   "mass",
"The path leads north into an incredibly dense mass of forest.  Five trees\n"+
"are growing almost out of the same spot, and their bases are entirely\n"+
"engrossed in plants and vines",
   "canopy",
"The branches of the evergreen trees are creaing a canopy above",
   "sky",
"Only pieces of the blue sky are visible through the canopy",
   "branches",
"The branches of the trees are making a canopy which is blocking out a\n"+
"good portion of the sky",
   "ground",
"The ground is rather muddy here, although some grass is growing off to\n"+
"the sides of the path, praticularly to the south",
   "grass",
"Some soft green grass is living here amongst the trees and plants.  A\n"+
"healthy looking patch is growing just south of the muddy path",
   "patch",
"This patch of grass looks very pretty, and seems out of place in the forest",
   "river",
"The river can just barely be seen from here.  The sound of the river\n"+
"however, is unmistakably clear",
  });
  dest_dir=({
"/players/zeus/realm/city/path18.c", "east",
  });
}   }

  init(){
  ::init();
  add_action("north_dir", "north");
  add_action("n_dir", "north");
  add_action("e_dir", "east");
  add_action("listen_cmd", "listen");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }


north_dir(){
  write("The path to the north is blocked by a mass of forest.  There\n"+
    "is no way to get past it.\n");
return 1; }


status listen_cmd()
{
	write("To the east, rushing water can be heard.\n");
	say(TP->QN+" listens intently to the sounds of the forest.\n");
return 1;
}

