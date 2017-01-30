inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;
  if(!present("creature")) MO(CO("/players/zeus/realm/NPC/creature1.c"), TO);

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The path appears to end here at the river.  The river is flowing\n"+
"quickly and too wide to be able to cross.  The trees are towering\n"+
"high above, blocking out a lot of the sunlight.  The plants grow\n"+
"well here thanks to the water, and create a solid wall to the north.\n"+
"The plants to the south are a bit more sparse.\n";
  items=({
   "trees", 
"The evergreen trees are extremely tall, their branches criss crossing\n"+
"in such a way that much of the sky is blocked out",
   "canopy", 
"The branches of the evergreen trees are creating a canopy which is\n"+
"blocking out much of the sky",
   "path", 
"The path is very muddy here because of all the moisture coming from\n"+
"the river.  There are some large footprints in the mud",
   "mud",
"The path is extremely muddy here, and there are some footprints in it",
   "footprints",
"The footprints seem to have been made by a creature of the forest",
   "water", 
"The fast flowing water looks very cold",
   "undergrowth", 
"The undergrowth is quite diverse here, and growing very well despite\n"+
"the lack of natural light",
   "wall",
"To the north the plants and trees are so crowded that travel in that\n"+
"direction would be absolutely impossible",
   "river", 
"The river is about 15 feet wide and flowing extremely quickly.  There\n"+
"are a number of large rocks jutting out of the water",
   "rocks",
"A few large rocks can be seen poking out of the water",
   "bank", 
"The other side of the river is at least 15 feet away, and would be\n"+
"nearly impossible to get across to from here",
   "plants", 
"The plants are growing well here despite how little light there is.\n"+
"A few colorful bushes are growing to the north",
   "bushes",
"There are some dark red and green bushes growing here",
  });
  dest_dir=({
"/players/zeus/realm/city/path8.c", "west",
  });
}  }

  init(){
  ::init();
  add_action("south_dir", "south");
  add_action("search_cmd", "search");
  add_action("listen_cmd", "listen");
  add_action("s_dir", "s");
  add_action("w_dir", "w");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT"; }

status south_dir(){
 write("You part the undergrowth and walk south.\n");
 TP->MP("south#/players/zeus/realm/city/path5.c");
return 1; }

status search_cmd(){
 write("You search the room carefully and discover a less used path hidden\n"+
          "by the undergrowth to the south.\n");
 say(TP->QN+" searches around.\n");
return 1; }

status listen_cmd(){
	write("The rushing waters of the river are all that can be heard.\n");
	say(TP->QN+" listens carefully.\n");
return 1; }
