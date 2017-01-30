#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Tower Landing 2";
long_desc=
 "The echo of silence pervades your senses and creeps through\n"+
 "your consciousness as you glance in wonder about the chamber.\n"+
 "You stand in a cold, damp room of worked stone.  It is dimly\n"+
 "illuminated by flickering torches which cast strange shadows\n"+
 "across the chamber walls.  A sign hangs upon the wall, and a\n"+
 "staircase ascends up into the darkness above.\n";

items=({
 "sign","The sign reads:\n"+
   "  The portal to the south leads to the realm of dreams. \n"+
  "  It is a mid level realm.\n"+
  "  The portal to the east is very dangerous to enter.\n"+
  "  The portal to the north leads to a mid-high level realm",
 "torch","A blazing torch.\n"+
   "It is secured to the wall",
  "door","A solid archway of worked stone",
 "staircase","A solid stone stairway asending up into the darkness",
 "portal","A dark stone portal filled with a hazy blue aura",
  "torches","One of many blazing torches.\n",
     "It is secured to the wall",
 });

  dest_dir=({
 "/players/saber/tower/bgc/bg8.c","north",
 "/players/saber/tower/tower15.c","east",
 "/players/saber/tower/dream1.c","south",
 "/players/saber/tower/tower6.c","down",
 "/players/saber/tower/tower16.c","up",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }
