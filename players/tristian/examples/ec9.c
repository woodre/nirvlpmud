#include "/players/zeus/desert/r/search.h"
/* For the Inculta Creperum quest */
inherit "room/room";       /* ec9 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  There are many large, block-shaped stones mixed with the sand here.  In\n"+
"the middle of the area is a desolate old well which protrudes from the\n"+
"ground unnaturally.  The darkness overhead is swirling with the winds,\n"+
"which whip the sand into you.  All around the area are mountainous piles\n"+
"of rock which make travel in any direction other than east impossible.\n";
  items=({
  "archway",
"The stone archway is made of the same dry, brown rock that is abundant\n"+
"here.  It leads to the east.  On either side of the archway are large\n"+
"piles of rock",
  "arch",
"The stone archway is made of the same dry, brown rock that is abundant\n"+
"here.  It leads to the east.  On either side of the archway are large\n"+
"piles of rock",
  "rock",
"The rock is brown and very dry.  Much of it is cracking",
  "ground",
"The ground is dry, flat and covered in cracks.  A thin coating of sand\n"+
"and small rocks cover it",
  "sand",
"A thin coating of sand rests upon the ground.  The wind kicks the sand up\n"+
"into the air, which makes it hard for you to see",
  "rocks",
"Many small rocks litter the ground",
  "piles",
"The piles of rock force you to walk beneath the archway if you want to go\n"+
"west from here.  They are quite mountainous",
  "darkness",
"The darkness is all around you",
  "stones",
"The block-shaped stones almost look like they used to make up some sort\n"+
"of floor, but now they are all laying at different angles and make walking\n"+
"here an awkward proposition",
  "well",
"The well is made of similar looking stones to those that are mixed in with\n"+
"the sand on the ground.  Looking into it, all that can be seen is darkness",
  });
  dest_dir=({  "/players/zeus/desert/r/ec10.c", "east", });
  }
 }

void init(){
  ::init();
  add_action("down_dir", "down");
  add_action("enter_dir", "enter");
  add_action("search_cmd", "search");
}

int block()
{
  if(present("zeus_brute_lord_npc", this_object()))
  {
    write("The brute lord is blocking the well.\n");
    return 1;
  }
  return 0;
}

down_dir(){
  if(block()) return 1;
  write("There is no way to descend into the well...\n\n");
  return 1;
}

enter_dir(str){
  if(str != "well") return 0;
  if(block()) return 1;
  write("There is no way to descend into the well...\n\n");
  return 1;
}



