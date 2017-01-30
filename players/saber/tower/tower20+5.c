#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Mountain Plain";
long_desc=
 "You stand upon a great icy plane of irregularly packed snow, extending to\n"+
 "the east and west.  The wind howls over the plane, chilling you to thebone.\n";

items=({
 "clouds","Dark, ominous looking storm clouds",
 "mountain","A mountain peak, far to the west",
 "peak","A mountain peak, far to the west",
 "plain","A large plain running both east and west.\n"+
     "It is covered with ice",
 "ice","An icy plane of irregularly packed frozen snow.\n"+
    "Something could be hidden here",
 "ground","The ground is covered with great chunks of frozen ice",
 });

  dest_dir=({
 "/players/saber/tower/tower20+6.c","east",
 "/players/saber/tower/tower20+4.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
  write("You find large footprints leading to the east.\n");
say (tp +" searches the area\n");
 return 1;  }
