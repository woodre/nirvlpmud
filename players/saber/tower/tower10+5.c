#define tp this_player()->query_name()
inherit "room/room";
int i;
int t;
reset(int arg){
if(!present("pelt"))
{
move_object(clone_object("players/saber/stuff/wolfskin.c"),this_object());
if(!present("axe")) {
move_object(clone_object("players/saber/weapons/haxe.c"),this_object());
}
if(!present("jacket")){
move_object(clone_object("players/saber/armor/ljacket.c"),this_object());  }
if(!present("cloak")){
move_object(clone_object("players/saber/armor/bluecloak.c"),this_object());  }
if(!present("mirror")){
move_object(clone_object("players/saber/stuff/mirror.c"),this_object());
}
if(!present("sword")){
move_object(clone_object("players/saber/weapons/ssword.c"),this_object());
}
}
 if(!arg){
  set_light(0);
 short_desc="Bandit Treasure";
long_desc=
  "A small dark cave.\n";

items=({
 "cave","A small dark cave",
 "ground","The floor of the cave is made of stone",
 });

dest_dir=({
 "players/saber/tower/tower10+4.c","out",
 });
} }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing.\n");
say(tp+" searches the area.\n");
return 1;
}
