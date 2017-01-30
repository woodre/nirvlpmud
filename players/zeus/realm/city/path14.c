inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;
  if(!present("bear")) MO(CO("/players/zeus/realm/NPC/bear1.c"), TO);

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"This is a dark corner of the forest.  To the north and west the trees\n"+
"grow so close together that travel is blocked.  The undergrowth is\n"+
"surprisingly thick considering how little light is reaching this point.\n"+
"A small pool of water has collected at the base of a large tree.\n";
  items=({
   "trees",
"The mighty evergreen trees climb high into the sky, their branches\n"+
"blocking out most of the sky.  One large oak tree stands among them",
   "pool", 
"The small pool of water is only a few inches deep, and about a foot wide",
   "water",
"The water in the pool is perfectly calm, and very clear",
   "branches",
"The branches of the trees are blocking out most of the sky above",
   "sky",
"Only small patches of the blue sky can be seen through the canopy",
   "forest", 
"The forest here is fairly dark.  A little light is able to peak through\n"+
"the canopy above.  To the north and west there is nothing but darkness",
   "bushes",
"Some of the bushes are over six feet tall.  Most of them have plain green\n"+
"leaves, highlighted by pretty red veins which run through them",
   "undergrowth",
"There are many tangly vines growing amongst the bushes and trees, creating\n"+
"a virtual wall to the north and west",
   "oak tree", 
"The large oak tree is about five feet wide at it's base and climbs very\n"+
"high into the sky.  It is taller than all of the evergreen trees around it",
   "canopy",
"The canopy created by the branches of the towering trees is blocking out\n"+
"most of the light in this little area.  To the north and west, the forest\n"+
"is extremely dark",
  });
  dest_dir=({
"/players/zeus/realm/city/path15.c", "east",
"/players/zeus/realm/city/path10.c", "south",
  });
}   }

  init(){
  ::init();
  add_action("s_dir", "south");
  add_action("e_dir", "east");
  add_action("drink_cmd", "drink");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }

status drink_cmd(string str)
{
  if(!str) return 0;
  if(str=="water")
  {
    write("You drink some water from the pool...\n"+
	      "It has a bitter taste, making you feel slightly ill.\n");
    TP->hit_player(5+random(4));
    say(TP->QN+" drinks some water from the pool on the ground.\n");
    return 1;
  }
  else return 0;
}
