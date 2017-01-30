inherit "room/room";
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"Here the path leads straight north to south.  Through the forest\n"+
"to the west pieces of a large structure can be seen.  Most of it\n"+
"however is covered by the undergrowth.  To the east of the path a\n"+
"large stump is sitting amongst the plants and trees.\n";
  items=({
   "path", 
"The dirt path is fairly dry here, and quite well defined",
   "trees", 
"The mighty evergreen trees seem to have existed here forever.  They\n"+
"climb endlessly into the sky, their branches fanning out over you",
   "branches",
"The branches of the evergreen trees criss cross in such a way that\n"+
"you feel as though you are in more of a tunnel than a forest",
   "canopy",
"The canopy created by the branches is blocking out much of the sky",
   "sky",
"The beautiful blue sky is for the most part hidden by the trees",
   "undergrowth",
"The various types of plants are pushed back from the path.  There are\n"+
"some thin plants with sharp thorns and black berries on them",
   "berries",
"The black berries that are growing on the thorny plant are perfectly\n"+
"smooth, and appear to be very juicy",
   "structure", 
"Most of the structure has been consumed by the forest, however some\n"+
"parts of it show through, which are a dull white color.  The stones\n"+
"are very faded because of the weather",
   "stump", 
"The stump is very wide, and about five feet tall.  Mostly covered in moss\n"+
"and vines, it is slowly rotting away",
   "plants", 
"There are many different plants in the undergrowth, some of which\n"+
"are extremely colorful",
  });
  dest_dir=({
"/players/zeus/realm/city/path20.c", "north",
"/players/zeus/realm/city/path13.c", "south",
  });
}     }

  init(){
  ::init();
  add_action("n_dir", "north");
  add_action("s_dir", "south");
  add_action("pick_cmd", "pick");      /* just for fun   */
  add_action("eat_cmd", "eat");        /*   more fun     */
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }


status pick_cmd(string str)
{
int type;
 if(!str) return 0;
 if(str == "berry" || str == "black berry")
 {
  type = random(4);
  switch(type)
  {
  case 0:
	  write("You reach to pick a berry, but then change your mind.\n");
      break;
  case 1:
	  write("As you reach to pick a berry, you cut yourself on a thorn.\n");
	  TP->adj_hp(-5-random(4));
      break;
  case 2:
	  write("You think about picking a berry, but decide against it.\n");
	  break;
  case 3:
	  write("As you reach to pick a berry, a noise in the forest distracts "+
		    "you, and\nyou forget all about the berries.\n");
	  break;
  }
  return 1; 
 }
 else return 0;
return 1; 
}


status eat_cmd(string str)
{
 if(!str) return 0;
 if(str== "berry" || str == "black berry")
 {
	 write(
"You use your best judgement and decide not to eat one of the berries.\n");
	 say(TP->QN+" stares intently at the berries.\n");
 return 1; 
 }
 else return 0;
}


