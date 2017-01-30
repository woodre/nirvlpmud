#define tp this_player()->query_name()
inherit "room/room";
int i, search_count;
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
 short_desc="More Forest";
long_desc=
 "The trees part to form a large clearing.  The clearing seems to\n"+
 "have been converted into some sort of temporary campsite, and\n"+
 "is littered with sleeping furs, cooking fires and assorted gear.\n"+
 "A large tent is centrally located amidst the chaos.\n";

items=({
 "tree","A big, tall green thing",
 "trees","Many big, tall green things",
 "path","A dirt path leading through the forest",
 "forest","Lots of big, green things",
 "clearing","A lot of dirt with no trees growing from it",
 "tent","A large tent sewn from the pelts of many wolves",
 });

dest_dir=({
 "players/saber/tower/tower10.c","north",
 "players/saber/tower/tower10+4.c","east",
 "players/saber/tower/tower10+6.c","south",
 "players/saber/tower/tower10+3.c","west",
 "players/saber/tower/tower10+2.c","tent",
 });
}  }
init(){
 ::init();
  add_action("search","search");
}

search() {
if (search_count == 2)  {
search_count = search_count + 1;
write("You find a stash of grass!\n");
 move_object(clone_object("players/saber/stuff/grass.c"),this_player());
say (tp +" searches the area\n");
 return 1;  }
else
{
search_count = search_count +1;
write("You find nothing.\n");
say(tp+" searches the area.\n");
return 1;
}   }

