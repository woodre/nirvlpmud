inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int searched, teleport;

reset(arg){
 if(!arg){

 teleport = 0;  if(random(2)) teleport = 1;
 searched = 0;   /*  They haven't searched yet   */

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The path ends here at the river.  The river is flowing very fast and\n"+
"looks incredibly dangerous.  The plants growing near the rivers edge\n"+
"are very thick and healthy.  They entirely block the view to the south\n"+
"of the path.  A pile of large rocks sits among the undergrowth on the\n"+
"north side of the path.\n";
  items=({
   "river", 
"The river looks very cold, and is flowing very fast",
   "water",
"The water looks very cold, and is flowing extremely quickly downstream",
   "plants", 
"The plants are alive with variety, and are very thick.  To the south\n"+
"it is just a wall of plants",
   "trees", 
"The mighty evergreen trees all appear to be as old as the area itself,\n"+
"each one acting as a guardian of the forest",
   "canopy", 
"The evergreen trees are creating a canopy over the path with their\n"+
"branches, which is blocking out a little of the sky",
   "path", 
"The path is very muddy here, making it hard to keep your footing",
   "undergrowth", 
"The undergrowth is alive with variety here and very thick.  There are\n"+
"some very full bushes and ferns growing to the south of the path",
   "bushes",
"The bushes are green with flat leaves.  They are concealing the secrets\n"+
"of the forest",
   "ferns",
"The ferns branch out, absorbing all the light they can.  They are doing\n"+
"their best to conceal the secrets that lie hidden within the forest",
   "riverbank", 
"The riverbank is very slippery and dangerous because it is so muddy.\n"+
"It would be easy to accidentally slip into the river",
   "plants", 
"Most of the lush plants are growing extremely well here, including some\n"+
"very pretty ferns and bushes to the south of the path",
   "rocks",
"The rocks themselves are large and grey.  Some have moss growing on them",
   "pile", 
"The pile of rocks is a few feet high and wide, with the help of the plants\n"+
"and trees is creating a wall to the north",
   "moss",
"There is some fluffy green moss growing on the pile of rocks",
   "branches",
"The branches of the evergreen trees are making the forest very dark,\n"+
"although this area is very light because there are no trees over the river",
  });
  dest_dir=({
"/players/zeus/realm/city/path22.c", "west",
  });
}    }

int searched(){  return searched(); }

  init(){
  ::init();
  add_action("south_dir", "south");
  add_action("s_dir", "south");
  add_action("w_dir", "west");
  add_action("search_cmd", "search");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT"; }

south_dir()
{
	if(searched)
	{
	    write("You part the undergrowth and walk south.\n");
        TP->MP("leaves south#/players/zeus/realm/city/path18.c");
	return 1;
	}
	else 
	{   
		write("What?\n");  
		return 1; 
	}
return 1; 
}

status search_cmd(string str)
{
 if(str=="plants" || str=="ferns" || str=="bushes" || str=="undergrowth")
 {
	 if(searched == 1)
	 {
		 write("Someone has already uncovered the path to the south.\n");
		 return 1;
	 }
	 write("You search the "+str+" and uncover a path to the south.\n");
	 say(TP->QN+" uncovers a hidden path to the south.\n");
     searched = 1;
	 return 1;
 }
 if(str=="pile" || str=="rocks" || str=="pile of rocks")
 {
     write("You search the pile of rocks and discover nothing right now.\n");
     return 1; 
 }
 else
 {
	 write("You search the area briefly and find nothing of interest.\n");
	 say(TP->QN+" searches around.\n");
	 return 1;
 }
 return 1;
}
