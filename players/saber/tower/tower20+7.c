#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Mountain Plain";
long_desc=
 "You stand at the end of the great icy plane.  There are towering walls of\n"+
 "vertical stone ascending towards the heavens in all directions but to the\n"+
 "east.  You believe that you might be able to scale the wall.\n";

items=({
 "clouds","Dark, ominous looking storm clouds",
 "mountain","A mountain peak, far to the west",
 "peak","A mountain peak, far to the west",
 "plain","A large plain running both east and west.\n"+
     "It is covered with ice",
 "ice","Large chunks of frozen ice",
 "wall","Large, towering walls which disappear up into the clouds",
 "walls","Large, towering walls which disappear up into the clouds",
 "ground","The ground is covered with great chunks of frozen ice",
 });

  dest_dir=({
 "/players/saber/tower/tower20+71.c","up",
 "/players/saber/tower/tower20+4.c","east",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
  write("You find nothing.\n");
say (tp +" searches the area\n");
 return 1;  }
