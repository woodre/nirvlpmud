#define tp this_player()->query_name()
inherit "room/room";
int i;
int t;
reset(int arg){
if(!present("bandit")) {
move_object(clone_object("/players/saber/closed/monsters/bandit.c"),this_object());
}
if(!present("bandit 1")){
move_object(clone_object("/players/saber/closed/monsters/bandit+1.c"),this_object());
}
if(!present("bandit 2")){
move_object(clone_object("/players/saber/closed/monsters/bandit+2.c"),this_object());  }
if(!present("bandit 3")){
move_object(clone_object("/players/saber/closed/monsters/bandit+3.c"),this_object());  }
if(!present("bandit 4")){
move_object(clone_object("/players/saber/closed/monsters/bandit+4.c"),this_object());  }
if(!present("bandit 5")){
move_object(clone_object("/players/saber/closed/monsters/bandit+5.c"),this_object());  }
if(!present("bandit 6")){
move_object(clone_object("/players/saber/closed/monsters/bandit+6.c"),this_object());  }
if(!present("frederick")){
move_object(clone_object("/players/saber/closed/monsters/frederick.c"),this_object());
 }
 if(!arg){
  set_light(1);
 short_desc="Bandit Forest";
long_desc=
 "You are on a dirt path in the middle of a forest.  To the north\n"+
 "and south the trail continues through the forest.  This looks like\n"+
 "a really good place for an ambush.\n";

items=({
 "tree","A big, tall green thing",
 "trees","Many big, tall green things",
 "path","A dirt path leading through the forest",
 "forest","Lots of big, green things",
 "ground","Lots of leaves cover the ground",
 });
dest_dir=({"/players/saber/closed/tower/tower10+11.c","south",
   "/players/saber/closed/tower/tower10+01.c","north",
   });
 }}


south(){
if(!present("frederick")){
call_other(this_player(),"move_player","south#players/saber/closed/tower/tower10+1.c");
 say(tp+" leaves south\n");
 return 1;}
write("Frederick steps in front of you.\n");
write("Frederick says: You shall not pass while I live!\n");
say("Frederick steps in front of "+tp+".\n");
say("Frederick says: You shall not pass while I live!\n");
  return 1;
}
init(){
 ::init();
  add_action("search","search");
add_action("south","south");
add_action("hellfire","hellfire");
add_action("chain","chain");
add_action("demon","demon");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

demon(str){
write("You can not do that here.\n");
 return 1;
}
chain(str)  {
write("You cannot do that here.\n");
return 1;  }
hellfire()  {
write("You cannot do that here.\n");
return 1;  }
