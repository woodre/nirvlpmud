#define tp this_player()->query_name()
inherit "room/room";
int i;
int t;
reset(int arg){
if(!present("bandit")) {
move_object(clone_object("/players/saber/monsters/kissbandit.c"),this_object());
}
 if(!arg){
  set_light(1);
 short_desc="Kissing Clearing";
long_desc=
  "A small, quiet grove with many trees.\n";

items=({
 "tree","A big, tall green thing",
 "trees","Many big, tall green things",
 "forest","Lots of big, green things",
 "grove","A small grove of trees in the middle of a forest.\n"+
   "Go figure.\n",
 });

dest_dir=({
 "players/saber/tower/tower10+1.c","east",
 });
}  }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing.\n");
say(tp+" searches the area.\n");
return 1;
}
