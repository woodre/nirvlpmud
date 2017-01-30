 
inherit "room/room";
 
#define tp this_player()->query_name()
 
reset (arg){
if (!arg){
set_light(5);
}
short_desc="The Center of Hell   ";
dest_dir=({
"/room/church","mommy",
"/players/heroin/quests/room/hell2", "enter",});
long_desc =
"You should be proud of yourself, You have worked hard and now look\n"+
"where you are: HELL.  I think you know what you have to do...get it over\n"+
"with...complete your destiny\n";
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
write(" Its a secret...Im not telling you!\n");
say(tp + "ponders the situation \n");
return 1;
}
smell(){
write("Something's burning-SNIFF SNIFF..Shit its you..KILL THE CORD\n");
say (tp + "turns and sniffs his burning ass.\n");
say (tp + "says: can u sniff your own butt?\n");
return 1;
}
listen(){
write("In the distance, you could swear you hear someone selling\n popcorn and beer.  Sounds like its coming from the north.\n");
say(tp + "begins to drool and rub his tummy\n");
return 1;
}
    
