inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"
int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;
  if(!present("wolf")) MO(CO("/players/zeus/realm/NPC/wolf1.c"), TO);

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The path is very muddy here, and the whole environment is much\n"+
"wetter.  The canopy of the trees is very patchy here, allowing\n"+
"much light to penetrate through.  As a result the undergrowth is\n"+
"flourishing, crowding the path making it hard to see.\n";
  items=({
   "trees", 
"The ancient, bark-laden trees reach high into the sky.  There are\n"+
"a number of different types here, including some oak trees and some\n"+
"pine trees",
   "environment", 
"Everything around here is very moist.  The path is extremely muddy,\n"+
"and the leaves of the plants are all slick with water",
   "canopy", 
"The branches of the trees are blocking out some of the sky, however\n"+
"a lot of light is able to shine through",
   "path", 
"The path is very muddy here, and crowded by the thick undergrowth.  A\n"+
"few large footprints are visible in the mud",
   "footprints",
"The deep footprints were made by a very large, heavy creature",
   "undergrowth", 
"The undergrowth is alive with variety here.  Each and every plant\n"+
"seems to be radiating a different color of the rainbow.  You notice\n"+
"a little used path which leads to the south through the thick undergrowth",
  });
  dest_dir=({
"/players/zeus/realm/city/path5.c", "east",
"/players/zeus/realm/city/path3.c", "west",
  });
}  }

  init(){
  ::init();
  add_action("w_dir", "west");
  add_action("e_dir", "east");
  add_action("s_dirr", "south");
  add_action("search_cmd", "search");
}

realm(){   if(teleport) return "NT"; }
okay_follow(){ return 1; }

s_dirr(){
  if(s_dir()) return 1;
  write("You walk south through the undergrowth...\n\n");
  TP->MP("south#/players/guilds/fallen/rooms/path.c");
  return 1;
}

status search_cmd(string str)
{
  if(!present("bwolf"))
  {
    if(str != "undergrowth")
    {
      write("You search the room briefly and find nothing.\n");
      return 1;
    }
    else 
    {
      write(
        "You search the undergrowth and discover a path to the south.\n");
      return 1;
    }
    return 1;
  }
  write("The wolf bites you hard!\n");
  say("The wolf bites "+TP->QN+".\n");
  TP->hit_player(10+random(15));
  return 1; 
}
