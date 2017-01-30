#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
  if(!present("sign"))  {
move_object(clone_object("/players/saber/food/pub.c"),this_object());   }
if(!present("go player")) {
move_object(clone_object("/obj/go_player.c"),this_object());   }
if(!present("girl"))  {
 move_object(clone_object("/players/saber/monsters/ghost.c"),this_object());  }
if(!present("hearth"))  {
move_object(clone_object("/players/saber/fur/fireplace.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Tower Pub";
long_desc=
 "The echo of silence pervades your senses and creeps through your\n"+
 "consciousness as you glance in wonder about the chamber.  You stand\n"+
 "in a warm room constructed from exquisitly worked stone.  The\n"+
 "chamber is lit by a fire blazing in the fireplace on the south wall.\n"+
 "There is a sign on the wall showing pub prices.\n";

items=({
 "stone","Dark black stone",
 "room","A warm room constructed from exquisitly worked stone",
 "chamber","A warm froom constructed from exquisitly worked stone",
 "pub","A warm chamber constructed from exquisitly worked stone",
 "fire","A blazing fire in the hearth",
 });

  dest_dir=({
 "/players/saber/tower/tower2.c","north",
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


