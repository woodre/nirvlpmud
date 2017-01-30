#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Mountain Plain";
long_desc=
 "You stand upon a great icy plane, extending to the east and west.  A small\n"+
 "path leads down the mountain to the north.  Far to the west you can vaguely\n"+
 "make out the mountains peak, hidden as it is amidst the dark storm clouds.\n";

items=({
 "trail","A thin, icy trail covered with a fresh layer of virgin snow",
 "clouds","Dark, ominous looking storm clouds",
 "mountain","A mountain peak, far to the west",
 "peak","A mountain peak, far to the west",
 "plain","A large plain running both east and west.\n"+
     "It is covered with ice",
"ice","Large chunks of frozen snow",
 "ground","Large chunks of frozen ice cover the ground",
 });

  dest_dir=({
 "/players/saber/tower/tower20+3.c","north",
 "/players/saber/tower/tower20+7.c","west",
 "/players/saber/tower/tower20+5.c","east",
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
