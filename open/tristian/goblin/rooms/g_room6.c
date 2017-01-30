#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Encampment"; 

long_desc =
" The camp continues across the clearing. Small tents dot the\n"+
"ground here, leaving little space between them. Cookfires are spread\n"+
"out amongst the tents. The blue sky and the green trees off to the\n"+
"west make a striking backdrop, broken only by the low picket line\n"+
"that prevents anyone wandering off into the forest.\n";

items = (
{
"tents", 
  "Crude tents that leak at the seams, made from some\n"+
  "unknown tanned material",
"sky",
  "A beautiful light blue sky overhead with whispy white clouds",
"clouds",
  "White puffy clouds, does that one look like a deer?",
"deer",
  "A puffy cloud, nothing more, it was your imagination that made it look like a deer",
"picket",
  "A low fence of sticks, twigs and small logs that prevents\n"+
  "going out into the forest, but more importantly prevents\n"+
  "intruders from coming in that way",
"line",
  "A low fence of sticks, twigs and small logs that prevents\n"+
  "going out into the forest, but more importantly prevents\n"+
  "intruders from coming in that way",
"paintings",
  "Crude stick figure paintings depicting battles and pillaging",
"pines", 
  "Evergreen pines well over 100' tall",
"forest",
  "An array of hardwoods and evergreens with a dazzaling display\n"+
  "of light that falls down through the tree tops that tower far above",
"firepit",
  "Being a little far away makes it hard to determine what it looks like, but\n"+
  "there are a  few bones and a skull visible even from here",
"trees",
  "These tall pines have probably been growing since this forest was new", 
"clearing",
  "An open area of the woods, mostly beaten down grass and dirt",
"grass",
  "Beaten down grass, mostly dead and sparrodic at best",
"dirt", 
  "Dirt. Plain old ordinary dirt",
"trash",
  "Debris and garbage",
"debris",
  "Trash and garbage",
"garbage", 
  "GARBAGE - you know GARBAGE!",
}
);

if(!present("goblin1",this_object()))
  move_object(clone_object(NPC+"goblin_regular.c"),
  this_object());

if(!present("goblin2",this_object()))
  move_object(clone_object(NPC+"goblin_regular.c"),
  this_object());

if(!present("goblin3",this_object()))
  move_object(clone_object(NPC+"goblin_regular.c"),
  this_object());


dest_dir = (
{
RMS+"g_room12.c",    "south",
RMS+"g_room1.c",      "northeast",
}
);

}

init()
{
::init();
  add_action("Smell","smell");
  add_action("Search","search");
  add_action("Listen","listen");
}

Smell(str)
{
if(!str || str == "air") {
write("The smells of wood smoke and dirty goblins wafts through the air.\n");
return 1;
}
return 1;
}

Search()
{
write("You find nothing special.\n");
return 1;
}

Listen()
{
write("The general din of the goblin camp, and off further into the forest,\n"+
"the sounds of birds chirping float on the afternoon breeze.\n");
return 1;
}



