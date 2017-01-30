inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;
  if(!present("hunter")) MO(CO("/players/zeus/realm/NPC/hunter1.c"), TO);

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The path is well defined at this point, used frequently by the animals\n"+
"who reside here.  The canopy is very patchy allowing sunlight to nourish\n"+
"the forest floor.  A large tree about 8 feet to the east of the path has\n"+
"died and partly fallen, however the trees around it prevent it from\n"+
"falling across the path.\n";
  items=({
   "path", 
"The path is clearly defined here because it is used so often.  Some\n"+
"small rocks and brown leaves are scattered acoss it",
   "leaves",
"The path is covered in dead brown leaves which are dry and crunchy",
   "rocks",
"The small rocks add some color variation to the otherwise brown path",
   "floor", 
"The forest floor is lush and beautiful here.  The grass is growing very\n"+
"well, and is speckled with rocks and leaves",
   "canopy", 
"The branches of the trees criss cross amongst each other, creating a bit\n"+
"of a canopy which blocks out a little of the blue sky here",
   "sky",
"The beautiful blue sky can be seen peeking through the trees",
   "trees", 
"The tall evergreen trees are working together to hold up the gigantic\n"+
"dead tree which has partially fallen",
   "tree", 
"The dead evergreen tree does not look very stable.  It is leaning up\n"+
"against a number of other evergreen trees, making them bend slightly",
   "undergrowth", 
"The undergrowth is alive with variety here.  There are a few lush green\n"+
"bushes with yellow blossoms on them",
   "bushes",
"There are a few different types of bushes here, including one which has\n"+
"beautiful yellow blossoms on it",
   "blossoms",
"The yellow blossoms seem to be as bright as the sun",
   "grass",
"The lush green grass is growing well on and around the path",
  });
  dest_dir=({
"/players/zeus/realm/city/path12.c", "north",
"/players/zeus/realm/city/path3.c", "south",
"/players/zeus/realm/city/path6.c", "west",
  });
}  }

  init(){
  ::init();
  add_action("n_dir", "north");
  add_action("s_dir", "south");
  add_action("w_dir", "west");
}

realm(){   if(teleport) return "NT"; }
okay_follow(){ return 1; }
