inherit "room/room";
#include "/players/zeus/closed/fl_demon.h"
#include "/players/zeus/closed/all.h"

int teleport;

reset(arg){
 if(!arg){

 teleport = 0;  if(random(2)) teleport = 1;

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"At this point the forest path is very open.  Large, flat pieces of\n"+
"stone are in the ground, indicating that perhaps once a structure\n"+
"stood here.  The undergrowth is thick where it grows,  concealing\n"+
"the secrets of the forest.  The trees tower high into the sky.\n";
  items=({
   "trees", 
"The ancient evergreen trees climb so high into the sky that their\n"+
"tops remain unseen from this vantage point",
   "canopy", 
"The branches of the evergreen trees slightly cross over, making a bit\n"+
"of a canopy here.  Most of the blue sky is still visible however",
   "path", 
"The path is moderatly muddy here, scattered with flat pieces of stone,\n"+
"small branches, and brown pine needles",
   "stone", 
"The stones look as though they could have once been the floor of\n"+
"a structure, however now are cracked and broken",
   "pieces",
"The flat pieces of stone were probably once the floor of a structure.\n"+
"Most of them are now cracked and broken",
   "undergrowth", 
"The undergrowth is thick in this area of the forest, however the path\n"+
"is open and not being crowded by the plants",
   "plants",
"The healthy green plants are growing very well here, but are not\n"+
"crowding the path, which is clearly defined here",
   "forest", 
"All of the trees look as if they have lived here for centuries, making\n"+
"the forest feel very ancient",
   "ground",
"The ground is somewhat muddy here, scattered with branches, small\n"+
"rocks, flat pieces of stone, and dead pine needles",
   "rocks",
"There are a few small rocks scattered along the ground",
   "branches",
"There are a number of dead branches lying on the ground",
   "needles",
"Scattered across the path are small brown pine needles",
  });
  dest_dir=({
"/players/zeus/realm/city/path13.c", "north",
"/players/zeus/realm/city/path9.c", "east",
  });
}  }

  init(){
  ::init();
  add_action("n_dir", "n");
  add_action("e_dir", "e");
  add_action("listen_cmd", "listen");
}

exit(){    if(TP) TP->clear_fight_area();     }

realm(){   if(teleport) return "NT"; }

status listen_cmd()
{
	write("You can hear rushing water to the east.\n");
	say(TP->QN+" listens carefully.\n");
return 1; }
