#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Mountain Path";
long_desc=
 "The path winds across the mountain and ends at the mouth of a large\n"+
 "hole.  Completely surrounded by towering cliffs, you may return south\n"+
 "along the trail or attempt to climb down.\n";

items=({
 "clouds","Dark, ominous looking storm clouds",
 "path","A small animal path leading to the south",
 "hole","A large hole descending into the darkness of this icy mountain",
 "cliff","You stand at the base of a large cliff",
 "mountain","The peak of the mountain looms above you to the west",
 "peak","The peak of the mountain looms above you to the west",
 "ice","Large chunks of frozen ice",
 "ground","The ground is covered with great chunks of frozen ice",
 });

  dest_dir=({
 "/players/saber/tower/tower20+8.c","south",
 "/players/saber/tower/tower20+10.c","down",
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
