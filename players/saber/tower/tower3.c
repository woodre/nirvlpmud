#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
  if(!present("sign"))  {
move_object(clone_object("/players/saber/food/shop3.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Tower Shop";
long_desc=
 "The echo of silence pervades your senses and creeps through\n"+
 "your consciousness as you glance in wonder about the chamber.\n"+
 "You stand in a cold, damp room of worked stone.  It is dimly\n"+
 "illuminated by flickering torches which cast strange shadows\n"+
 "across the chamber walls.  You get the distinct impression\n"+
 "that this room is a shop of some sort.\n";

items=({
 "torch","A blazing torch\n"+
   "It is secured to the wall",
 "stone","Dark black stone",
 "shop","Yes, you are in a shop",
 "chamber","A cold, damp chamber of worked stone",
 "room","A cold, damp room of worked stone",
  "torches","One of many blazing torches.\n",
     "It is secured to the wall",
 });

  dest_dir=({
 "/players/saber/tower/tower2.c","south",
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


