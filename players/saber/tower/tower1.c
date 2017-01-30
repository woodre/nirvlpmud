#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Tower Entrance";
long_desc=
 "The echo of silence pervades your senses and creeps through\n"+
 "your consciousness as you glance in wonder about the chamber.\n"+
 "You stand in a cold, damp room of worked stone.  It is dimly\n"+
 "illuminated by flickering torches which cast strange shadows\n"+
 "across the chamber walls.  A sign hangs upon the wall, and a\n"+
 "door leads to the east.\n";

items=({
 "sign","     You have entered the tower of portals.\n"+
 "                 Welcome",
 "torch","A blazing torch\n"+
   "It is secured to the wall",
  "door","A solid archway of worked stone",
  "torches","One of many blazing torches.\n",
     "It is secured to the wall",
 "room","A chamber of worked stone",
 "chamber","A chamber of worked stone",
 "ground","The chamber floor has been constructed from worked stone",
 });

  dest_dir=({
 "/players/saber/ryllian/gv2.c","out",
 "/players/saber/tower/tower2.c","east",
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


