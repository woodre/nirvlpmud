#define tp this_player()->query_name()
inherit "room/room";
int i;
int z;
reset(int arg){
if(!present("backrub")) {
move_object(clone_object("/players/saber/effects/backrub.c"),this_object());
}
if(!present("sassak")) {
move_object(clone_object("/players/saber/monsters/sassak.c"),this_object());
}
if(!present("bandit 24")){
move_object(clone_object("/players/saber/monsters/bandit24.c"),this_object());
}
if(!present("pelt")){
 move_object(clone_object("/players/saber/stuff/wolfskin.c"),this_object());   }
 if(!arg){
  set_light(1);
 short_desc="Sassak's Tent";
long_desc=
 "You are inside of a large tent made from the pelts of many wolves.\n"+
 "The interior is ablaze with the clashing hues of rainbow colored\n"+
 "cloth, hung from every conceivable nook and cranny.  In the middle\n"+
 "of the tent is a large pile of wolf skins.\n";

items=({
 "tent","A large tent sewn from the pelts of many wolves",
 "cloth","Many hues of cloth hung about the tent in various places",
 });

set_heart_beat(1);

dest_dir=({
 "players/saber/tower/tower10+1.c","out",
 });
}

}
init(){
  ::init();
add_action("search","search");
}
search() {
write("You find nothing.\n");
say(tp+" searches the area.\n");
return 1;
}

heart_beat() {
if(!present("sassak")) {
object ob;
ob = present("backrub");
destruct(ob);
return 1;
set_heart_beat(0);
}
if(!present("bandit")) {
object ob2;
ob2 = present("backrub");
destruct(ob2);
return 1;
set_heart_beat(0);
}
}
