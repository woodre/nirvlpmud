/* Mountain room one*/
#if 0 /* Rumplemintz */
#include "/sys/lib.h"
#include "/sys/ansi.h"
#endif

inherit "/room/room";
reset(arg)  {   
  if(arg) return; 
  set_light(1);
  short_desc = "Mountain road";
  long_desc = 
    "Directly overhead the storm rages on. Heavy rain pours down the\n"+
    "sides and the low places are filling quickly with water. Debris\n"+
    "of past washouts gather at a shallow turn before water pours over\n"+
    "a cataract and drops away from the path. The road turns south.\n"+
    "Beyond the turn it appears less threatening with little fast \n"+
    "running water on it. A sign is carefully staked near the edge.\n";
  items=({		/*Remember two deep on noun descriptions*/
    "storm","The storm rages on above. Luckily it is warm enough only rain falls",
	"rain","Great sheets of rain pour down from the heavens soaking all",
    "places","Shallow grooves and indentations in the rock hold the rain ",
	"debris","Twigs, gravel, bits of moss, and other things carried by water",
	"turn","The water swirls at the point the road deverges. Water slows, things drop",
	"cataract","A waterfall carries the water plunging into a basin below",
	"path","The path turns away from the waterway and goes the drier route south",
	"water","The water moves quickly down the slope toward the plummet",
    "sign","A sign placed to warn travelers it can be 'read'",
    "twigs","Broken bits of wood",
    "gravel","Yes small rocks float in fast enough water",
    "moss","Normally grows on the stone but much has been washed to this spot",
    "things","Hard to identify bits, possibly old bones but all worthless",
    "bones","Likely left overs from passing travelers or washed from an animals lair",
    "basin","A large pool of water catches the falls before swirling away underground"
  });

  dest_dir = ({
    "/players/wren/Area/coastline/pass","east",
    "/players/wren/Area/coastline/mountain2","south", 
   }); 
 
  /* Commented out by Sparrow 9/14/06
  set_chance(5);       
  add_msg("A thunderclap explodes above and fades away\n");
  add_msg("Wind swirls up the pass blowing froth from the falling water\n");
  add_msg("Lighting flashes above lighting the area briefly \n");
  add_msg("Water spashes loudly as it tumbles over the rocks \n");
  add_msg("Rain patters loudly around you \n");
  */
  add_listen("main","The storm above and the cateract beside block out most other sounds ");
  add_listen("storm","The densest part of the storm rages above making much noise ");
  add_listen("cateract","The falling water may be soothing if not soaked and cold from the storm ");
  add_smell("main","Moss and damp air pervade");
  add_smell("moss","Earthy and organic, a bit like decay");
  add_smell("air","The air is cool and wet but mostly fresh ");
  add_touch("stone","The solid rock is cold and wet ");
  add_touch("debris","Something feels funny about this stuff");
}

init() {
  ::init();
  add_action("search_room","search");
  add_action("read_sign","read");
  add_action("enter","shift");
}

search_room()  {
  write("Something solid is behind the debris, perhaps 'shift' debris to reveal it\n");
  say (this_player()->query_name() +" searches the area. \n");
  return 1;
}

read_sign(str) {
  if(str != "sign") {
    write("Read what?\n");
    return 0;
  }
  if(str == "sign") {
    write(" |---------------------|  \n");
    write(" |---Beware the Edge---|  \n");
    write(" |---Nirvana is East---|  \n");
    write(" |---Coast is South ---|  \n");
    write(" |---------------------|  \n");
    write("         |I |I            \n");
    write("         |I |I            \n");
    write("         |I |I            \n");
    say(this_player()->query_name() +" looks at the sign.\n");
    return 1;
  }
}   

enter(str) {
  if (!str) {
    write ("Do what?\n"); 
    return 1;
  } 
        
  if (str != "debris") return 0;
  write("Shifting the debris you find a door concealed by branches \n"+
    "It moves as you touch it and overbalanced you fall in.\n");
  this_player()->move_player("disappears into the debris#players/wren/Area/coastline/vale.c");
  tell_object(this_player(),"The hidden door snaps shut behind you.\n");
  return 1;
}

/*Dump them into area leading to my merchant NPCs */
