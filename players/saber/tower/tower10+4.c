#define tp this_player()->query_name()
inherit "room/room";
int i;
int t;
reset(int arg){
if(!present("bandit")) {
move_object(clone_object("/players/saber/monsters/banditguard.c"),this_object());
}
 if(!arg){
  set_light(1);
 short_desc="Bandit Guard";
long_desc=
 "A small, quite grove with many trees.\n"+
 "There is a small cave to the south.\n";

items=({
 "tree","A big, tall green thing",
 "trees","Many big, tall green things",
 "forest","Lots of big, green things",
 "cave","A small cave to the south that you could probably go 'in'.\n"+
   "It looks dark inside",
 "ground","Lots of leaves cover the ground",
 });
 dest_dir=({"/players/saber/tower/tower10+1.c","west",});
 }}

in(){
if(!present("bandit")){
call_other(this_player(),"move_player","in#players/saber/tower/tower10+5.c");
 say(tp+" leaves south\n");
 return 1;}
else
{
write("The bandit guard steps in front of you.\n");
write("Bandit says: No strangers in there.\n"+
   "Now get out of here before I gotta hurt you.\n");
say("Bandit steps in front of "+tp+".\n");
say("Bandit says: No strangers in there.\n"+
   "Not get outta here before I got to hurt you.\n");
return 1;
}
}
init(){
 ::init();
  add_action("search","search");
add_action("in","in");
add_action("pet","pet");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }
