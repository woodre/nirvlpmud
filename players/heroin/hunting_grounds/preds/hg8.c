 
inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
 
reset (arg){
if (!arg){
set_light(2);
}
if(!present("predator")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx2.c"), this_object());
if(!present("predator2")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx7.c"), this_object());
if(!present("predator3")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx6.c"), this_object());
short_desc="On the Path East   ";
dest_dir=({
"/players/heroin/hunting_grounds/preds/hg9","east",
"/players/heroin/hunting_grounds/preds/hg2","west"});
long_desc =
"You follow the path to the east and are jumped\n"+
"by some Predator hoodlums...No honor what so ever!\n"+
"Kick There fangy asses!!!\n";
 
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
   
