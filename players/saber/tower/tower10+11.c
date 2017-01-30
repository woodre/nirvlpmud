#define tp this_player()->query_name()
inherit "room/room";
int i;
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Bandit Forest";
long_desc=
 "You are on a dirt path in the middle of a forest.  To the south\n"+
 "the trail continues through the forest, while to the north is a\n"+
 "path leading back towards the ambush sight.\n";

items=({
 "tree","A big, tall green thing",
 "trees","Many big, tall green things",
 "path","A dirt path leading through the forest",
 "forest","Lots of big, green things",
 "ground","Lots of leaves cover the ground",
 });
dest_dir=({"/players/saber/tower/tower10+1.c","south",
   "/players/saber/tower/tower10.c","north",
   });
 }}

init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }
