 
inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
reset (arg){
if (!arg){
set_light(5);
}
if(!present("guard")) move_object(clone_object("/players/heroin/quests/guard.c"), this_object());
if(!present("hitler")) move_object(clone_object("/players/heroin/quests/hitler.c"), this_object());
short_desc="HITLER'S HEADQUARTERS  ";
dest_dir=({
"/players/heroin/quests/room/hitler2", "east",});
long_desc =
"You enter the building and you swear that you are standing in\n"+
"front of Hitler.  But he's been dead for a long time???\n"+
"What part does he play in this wholecase?\n";
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
     
