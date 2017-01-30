#define tp this_player()->query_name()
inherit "room/room";
int i;
int t;
reset(int arg){
if(!present("axe")) {
move_object(clone_object("/players/saber/weapons/haxe.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Bandit Forest";
long_desc=
 "You are on a dirt path in the middle of a forest.  To the south\n"+
 "the trail continues through the forest, while to the north is a\n"+
 "portal leading back to the tower.\n";

items=({
 "tree","A big, tall green thing",
 "trees","Many big, tall green things",
 "path","A dirt path leading through the forest",
 "portal","A portal of empty black light",
 "forest","Lots of big, green things",
 "ground","Lots of leaves cover the ground",
 });
dest_dir=({"/players/saber/tower/tower10.c","south",
   "/players/saber/tower/tower6.c","portal",
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
