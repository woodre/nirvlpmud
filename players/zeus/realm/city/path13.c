inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;
  if(!present("lion")) MO(CO("/players/zeus/realm/NPC/lion1.c"), TO);

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"This is what looks to have once been a building.  A large portion\n"+
"of the ground is still flat stone, although the roots of the trees have\n"+
"also made some uneven.  Part of a wall is standing up to the east,\n"+
"beyond which is forest.  The other walls lie on the ground in pieces.\n";
  items=({
   "forest",
"The forest is fairly dense here.  The branches of the trees are criss\n"+
"crossing, and creating a canopy which is blocking some of the sky",
   "trees",
"The gigantic evergreen trees look centuries old.  They tower high into\n"+
"the sky, their branches mixing with one another creating a thick canopy\n"+
"which blocks out much of the sky",
   "sky",
"Pieces of the beautiful blue sky can be seen through the canopy of\n"+
"branches created by the forest",
   "branches",
"The branches of the evergreen trees are creating a patchy canopy",
   "canopy",
"The canopy created by the branches isn't terribly thick here, allowing\n"+
"plenty of daylight to reach the forest floor",
   "pieces",
"The walls of the building which are no longer standing lay on the ground\n"+
"in pieces.  There are many small fragments of white stone scattered all\n"+
"over the area",
   "floor",
"The floor of the building is still fairly intact, however the roots of\n"+
"the trees have hade much of it uneven.  Many of the white stones are\n"+
"faded and cracked",
   "trees",
"The towering evergreen trees reach high into the sky, their branches\n"+
"twisting and weaving amongst one another",
   "plants",
"There are many different types of plants growing around the building,\n"+
"including some beautiful flowers with violet pedals",
   "flowers",
"There are some very pretty flowers growing here.  Some of them have\n"+
"violet pedals and look very pretty.  Others have white pedals",
   "undergrowth",
"The undergrowth around the building is quite thick, although it is not\n"+
"crowding the path too terribly",
   "roots",
"The big roots from the trees have caused the floor stones here to become\n"+
"dangerously uneven.  Many of them are cracked and broken now because of\n"+
"how the forest has seemingly grown up around them",
   "building",
"You are standing in what was once a building.  Pieces of white stone\n"+
"are scattered on the floor, and to the east part of a wall remains upright",
   "ground",
"The ground is made mostly of flat white pieces of stone.  Many of them\n"+
"are cracked or broken now",
   "stone",
"There are many pieces of stone scattered across the ground.  Many of them\n"+
"are still somewhat solid, however others are broken to almost rubble",
   "wall", 
"The east wall is for the most part still standing, blocking much of\n"+
"the forest in that direction.  There is some faded blood on it",
   "blood",
"There is a faded blood stain marking the east wall.  The stain is in the\n"+
"shape of a splatter mark, almost as though someone fell a long way and\n"+
"then splattered against the wall",
  });
  dest_dir=({
"/players/zeus/realm/city/path16.c", "north",
"/players/zeus/realm/city/path8.c", "south",
"/players/zeus/realm/city/path12.c", "west",
  });
}  }

  init(){
  ::init();
  add_action("n_dir", "north");
  add_action("s_dir", "south");
  add_action("w_dir", "west");
  add_action("smell_cmd", "smell");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }

smell_cmd(){
  write("You lift your nose to the wind and take a whiff....\n"+
    "You can smell the freshness of the forest, and the distinct smell\n"+
    "of the blood on the wall.\n");
  say(TP->QN+" smells carefully.\n");
  return 1; 
}
