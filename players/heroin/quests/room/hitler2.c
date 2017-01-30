 
inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
reset (arg){
if (!arg){
set_light(5);
}
if(!present("driver")) move_object(clone_object("/players/heroin/quests/driver.c"), this_object());
short_desc=" An Army Jeep";
dest_dir=({
"/players/heroin/quests/room/hitler1", "north",
"/players/heroin/quests/room/hitler3", "west",});
long_desc =
"You narrowly escape the battle field by stealing yourself a truck.\n"+
"However, you didn't realize that the driver is still in it!\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
add_action("kill","kill");
   add_action("read","read");
   add_action("search","search");
}
kill(str){
object test;
test=(present("counter", this_player()));
if (test) {test->inc_count();}
}
search(){
write("Nothing.\n");
say(tp + "ponders the situation. \n");
return 1;
}
smell(){
write("Something's burning- Corpses of people slain in battle\n");
say (tp + "retches.\n");
say (tp + "says: war sucks beavis?\n");
return 1;
}
listen(){
write("INCOMING **BOOM**\n");
say(tp + "hits the floor.\n");
return 1;
}
     
