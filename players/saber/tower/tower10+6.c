#define tp this_player()->query_name()
inherit "room/room";
int i;
int t;
reset(int arg){
if(!present("bandit")) {
move_object(clone_object("/players/saber/monsters/bandit2.c"),this_object());
}
if(!present("bandit 21")){
move_object(clone_object("/players/saber/monsters/bandit21.c"),this_object());
}
if(!present("bandit 22")){
move_object(clone_object("/players/saber/monsters/bandit22.c"),this_object());  }
if(!present("bandit 23")){
move_object(clone_object("/players/saber/monsters/bandit23.c"),this_object());  }
if(!present("bandit 24")){
move_object(clone_object("/players/saber/monsters/bandit24.c"),this_object());  }
if(!present("bandit 25")){
move_object(clone_object("/players/saber/monsters/bandit25.c"),this_object());  }
if(!present("bandit 26")){
move_object(clone_object("/players/saber/monsters/bandit26.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="More Clearing";
long_desc=
 "This is the south end of the clearing.  The forest seems to press\n"+
 "in towards you, making passage any direction but north nigh well\n"+
 "impossible.\n";

items=({
 "tree","A big, tall green thing",
 "trees","Many big, tall green things",
 "path","A dirt path leading through the forest",
 "forest","Lots of big, green things",
 "clearing","A lot of dirt with no trees growing from it",
 "tent","A large tent sewn from the pelts of many wolves",
 });

dest_dir=({
 "players/saber/tower/tower10+1.c","north",
 });
}  }
init(){
 ::init();
  add_action("search","search");
add_action("hellfire","hellfire");
add_action("demon","demon");
add_action("chain","chain");
}


demon(str)  {
write("You cannot do that here.\n");
return 1;  }
hellfire()  {
write("You cannot do that here.\n");
return 1;  }
chain(str)  {
write("You cannot do that here.\n");
return 1;  }
search() {
write("You find nothing.\n");
say(tp+" searches the area.\n");
return 1;
}
