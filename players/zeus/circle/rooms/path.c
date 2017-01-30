inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, south, north, east;

reset(arg){
 if(!arg){

 teleport = 0;  if(random(2)) teleport = 1;
 south = 0;
 north = 0;
 east = 0;

  set_light(0);
  long_desc=
"This part of the forest has very thick undergrowth.  There is no defined\n"+
"path at all here, you are completely surrounded by plants.  The trees\n"+
"are creating a very thick canopy, which is blocking out almost all light.\n";
  items=({
   "forest",
"The forest is extremely thick here, making it impossible to see in which\n"+
"directions travel is possible.  The undergrowth is crowding in all around\n"+
"you, and the trees are blocking out nearly all of the light",
   "undergrowth",
"The undergrowth here is made of many different plants, including huge\n"+
"leafy ferns and flowery bushes.  They are growing extremely close together,\n"+
"making it practically impossible to see the forest floor",
   "ferns",
"There are some very large, green ferns growing here, blocking your line of\n"+
"sight in nearly every direction",
   "bushes",
"Some of the bushes growing here are over six feet tall, making travel\n"+
"extremely difficult.  A few of them have pretty blossoms on them",
   "floor",
"The forest floor is all but invisible because of the undergrowth",
   "ground",
"The ground, which is somewhat grassy here, is very hard to see because of\n"+
"the amount of plants which are growing here",
   "grass",
"A few small, delicate blades of green grass can be seen beneath the plants",
   "trees",
"The towering evergreen trees are creating a very thick canopy here, which\n"+
"is blocking out nearly all the avalible light.  It's strange that the\n"+
"plants are growing so well here",
   "plants",
"There are many different types of plants here, and they are growing so\n"+
"thickly that they are making travel next to impossible",
   "canopy",
"The canopy created by the branches of the trees is blocking out nearly\n"+
"all of the light.  Only tiny fragments of the blue sky can be seen",
   "sky",
"It is next to impossible to see the sky from here, there are just way\n"+
"too many branches on the evergreen trees",
  });
  dest_dir=({});
}  }

short(){ return "The Fallen Lands"; }

  init(){
  ::init();
/*  this_player()->set_fight_area(); */
  add_action("n_dirr", "n");
  add_action("ne_dirr", "ne");
  add_action("e_dirr", "e");
  add_action("se_dirr", "se");
  add_action("s_dirr", "s");
  add_action("sw_dirr", "sw");
  add_action("w_dirr", "w");
  add_action("nw_dirr", "nw");
}

/* exit(){    if(TP) TP->clear_fight_area();     } */

realm(){   if(teleport) return "NT"; }
okay_follow(){ return 1; }

status n_dirr(){
  write("You walk north through the undergrowth...\n");
  if(n_dir()) return 1;
  if(this_player()->query_attack() && random(4))
  {
    write("You become entangled in the plants...\n");
    return 1;
  }
  if((string)TP->query_guild_name() == "fallen" || north >= 2+random(2))
  {
    TP->MP("north#/players/zeus/realm/city/path4.c");
    if(north >= 3)
      north = 0;
  }
  else 
  {
    north += 1;
    east = 0;
  }
  return 1; 
}

status ne_dirr()
{
  write("You walk northeast through the undergrowth...\n");
  if(ne_dir()) return 1;
  TP->MP("northeast#/players/zeus/circle/rooms/path.c");
  return 1; 
}

status e_dirr()
{
  write("You walk east through the undergrowth...\n");
  if(e_dir()) return 1;
  /** WTF, remove GNAR 06/16/2014
  if(east > 30+random(20))
  {
    TP->MP("east#/players/zeus/workroom.c");
    east = 0;
    return 1;
  }
  **/
  TP->MP("east#/players/zeus/circle/rooms/path.c");
  east += 1;
  return 1; 
}

status se_dirr()
{
  write("You walk southeast through the undergrowth...\n");
  if(se_dir()) return 1;
  TP->MP("southeast#/players/zeus/circle/rooms/path.c");
  return 1; 
}

status s_dirr()
{
  write("You walk south through the undergrowth...\n");
  if(s_dir()) return 1;
  if(TP->query_attack() && random(4))
  {
    write("You become entangled in the plants...\n");
    return 1;
  }
  if((string)TP->query_guild_name() == "fallen" || south >= 2+random(2))
  {
    TP->MP("south#/players/zeus/circle/rooms/ghall.c");
    if(south >= 3)
      south = 0;
  }
  else 
  {
    south += 1;
    east = 0;
  }
  return 1; 
}

status sw_dirr()
{
  write("You walk southwest through the undergrowth...\n");
  if(sw_dir()) return 1;
  TP->MP("southwest#/players/zeus/circle/rooms/path.c");
  return 1; 
}

status w_dirr()
{
  write("You walk west through the undergrowth...\n");
  if(w_dir()) return 1;
  TP->MP("west#/players/zeus/circle/rooms/path.c");
  return 1; 
}

status nw_dirr()
{
  write("You walk northwest through the undergrowth...\n");
  if(nw_dir()) return 1;
  TP->MP("northwest#/players/zeus/circle/rooms/path.c");
  return 1; 
}
