#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
if(!present("ogre")){
for(i=0;i<2;i++){
move_object(clone_object("/players/saber/monsters/ogre3.c"),this_object()); }
}
if(!present("big ogre")){
move_object(clone_object("/players/saber/monsters/ogre4.c"),this_object()); }
 if(!arg){
  set_light(1);
 short_desc="Mountain Plain";
long_desc=
 "You stand at the end of the great icy plane.  There are towering walls of\n"+
 "vertical stone ascending towards the heavens in all directions but to the\n"+
 "west.  The entrance to a cavern begins here.\n";

items=({
 "clouds","Dark, ominous looking storm clouds",
 "mountain","A mountain peak, far to the west",
 "peak","A mountain peak, far to the west",
 "plain","A large plain running both east and west.\n"+
     "It is covered with ice",
 "ice","Large chunks of frozen ice",
 "cave","The entereance to a cave",
 "wall","Large, towering walls which disappear up into the clouds",
 "walls","Large, towering walls which disappear up into the clouds",
 "ground","The ground is covered with great chunks of frozen ice",
 });

  dest_dir=({
 "/players/saber/tower/tower20+61.c","cave",
 "/players/saber/tower/tower20+5.c","west",
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
