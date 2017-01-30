 
inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
reset (arg){
if (!arg){
set_light(5);
}
if(!present("khan")) move_object(clone_object("/players/heroin/quests/gkhan2.c"), this_object());
short_desc="A large tent  ";
dest_dir=({
"/players/heroin/hunting_grounds/hallway.c","out",});
long_desc =
"You have found yourself in the tent of Genghis Khan.\n"+
"He seems like he's busy studying a piece of paper??\n";
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
    
