 
inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
reset (arg){
if (!arg){
set_light(5);
}
if(!present("army1")) move_object(clone_object("/players/heroin/quests/army1.c"), this_object());
if(!present("army2")) move_object(clone_object("/players/heroin/quests/army2.c"), this_object());
if(!present("army3")) move_object(clone_object("/players/heroin/quests/army3.c"), this_object());
if(!present("army4")) move_object(clone_object("/players/heroin/quests/army4.c"), this_object());
short_desc="WWII Battlefield   ";
dest_dir=({
"/players/heroin/quests/room/cia1","portal",
"/players/heroin/quests/room/hitler2", "south",});
long_desc =
"Sounds of guunfire and the smell of gunpowder are all that\n"+
"you are aware of..You seen to be in the past, in a battlefield!\n"+
"I would duck if I were you, It looks like someone has you in their\n"+
"sights!!\n";
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
write("WOW! You found some dirt!\n");
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
       
