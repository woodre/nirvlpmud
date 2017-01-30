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
"This is a slight clearing in the forest.  The main path breaks into\n"+
"three parts here.  To the west and south the path is very easy to\n"+
"see, however the path to the north is less used.  On the side of the\n"+
"path a small hole has been formed which is holding muddy water.  A few\n"+
"leaves are scattered here and there, as well as a large branch.\n";
  items=({
   "trees", 
"The mighty evergreen trees reach high into the sky",
   "branches",
"The branches of the evergreen trees are blocking out much of the sky",
   "canopy",
"The branches are creating a bit of a canopy, although it is not a\n"+
"very dense one.  Must light is reaching the forest floor",
   "undergrowth",
"The undergrowth is alive with variety here.  Some small flowers are\n"+
"growing at the base of some trees, and some thorny bushes are growing\n"+
"here as well",
   "bushes",
"The thorny bushes look very tough and resilient",
   "flowers",
"The small yellow flowers are very delicate and pretty",
   "path",
"The path opens up slightly here.  It is very well defined, mostly\n"+
"because it is used so frequently by the animals here",
   "hole", 
"The hole is the apparent result of erosion.  It is full of brown, muddy\n"+
"water and is partially covered by a few leaves",
   "water",
"The water in the hole is very dark and muddy.  There are some leaves\n"+
"floating in it",
   "clearing", 
"The path widens here into a slight clearing",
   "branch", 
"The thick branch is lodged into the ground.  It has been there for\n"+
"a very long time, and it doesn't look like it's going anywhere soon",
   "leaves", 
"The browish red leaves are dirty and torn, mashed into the ground",
  });
  dest_dir=({
"/players/zeus/realm/city/path22.c", "north",
"/players/zeus/realm/city/path16.c", "south",
"/players/zeus/realm/city/path19.c", "west",
  });
}    }

  init(){
  ::init();
  add_action("n_dir", "north");
  add_action("s_dir", "south");
  add_action("w_dir", "west");
  add_action("pull_cmd", "pull");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }

status pull_cmd(string str)
{
	if(!str) return 0;
	if(str=="branch")
	{
		write("You try to pull the branch free, but fail miserably.\n");
		say(TP->QN+" pulls hard on the branch, but to no avail.\n");
	}
return 1; }
