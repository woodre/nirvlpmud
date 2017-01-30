inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The muddy path appears to end here at the riverbank.  To the south\n"+
"of the path a large growth of plants is sticking out into the river\n"+
"slightly, blocking the view downriver.  A few large stones are visible\n"+
"through the water.  Some large ferns block the view to the north.\n";
  items=({
   "trees",
"Towering evergreen trees climb ever so high into the sky, grasping at\n"+
"the wonderous blue sky",
   "canopy",
"The branches of the evergreen trees reach out like the begging arms of\n"+
"a child, grasping at the sunlight.  They block out much of the sky",
   "path", 
"The path is very wet and muddy here, making it difficult to traverse",
   "undergrowth",
"The plants grow very well here because it is so wet.  Some beautiful\n"+
"cattails are growing along the edge of the river",
   "cattails",
"The cattails are very pretty growing along the bank of the river",
   "river", 
"The river is about twenty feet wide.  It is flowing extremely quickly\n"+
"at this point, and many rocks are poking out of it",
   "riverbank", 
"The riverbank on the opposite side of the river is very steep, and would\n"+
"be next to impossible to climb up from the water",
   "ferns", 
"The large bushy green ferns completely block the view to the north",
   "water", 
"The water itself looks very cold.  It is clear and flowing dangerously\n"+
"fast downstream",
   "stones", 
"A few stones are poking out of the water.  They are for the most part\n"+
"smooth because of the water",
   "branches",
"The branches of the evergreen trees are criss crossing, creating a canopy\n"+
"which blocks out a good portion of the blue sky",
   "sky",
"The blue sky is somewhat hidden by the trees.  It can be seen very well\n"+
"above the river however.  A few white clouds can be seen",
   "clouds",
"The clouds are white and look very fluffy",
   "plants",
"To the south a large growth of plants is jutting out over the river\n"+
"slightly, blocking the view to the south",
  });
  dest_dir=({
"/players/zeus/realm/city/path17.c", "west",
  });
}  }

  init(){
  ::init();
  add_action("north_dir", "north");
  add_action("search_cmd", "search");
  add_action("w_dir", "west");
  add_action("n_dir", "north");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }

north_dir(){
 write("You part the undergrowth and walk north.\n");
 TP->MP("leaves north#/players/zeus/realm/city/path23.c");
return 1; }

status search_cmd(){
 write("You search the room carefully and discover a less used path hidden\n"+
          "by the oversized ferns to the north.\n");
return 1; }
