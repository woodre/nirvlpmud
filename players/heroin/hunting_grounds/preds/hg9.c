inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
 
reset (arg){
if (!arg){
set_light(2);
}
if(!present("predator")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx4.c"), this_object());
short_desc = "Behind the Rocks";
dest_dir=({
"/players/heroin/hunting_grounds/preds/hg8","west"});
long_desc =
"A DEAD END!!!!!!\n"+
"You seem to have caught a predator taking a nap.\n"+
"He's pretty big..I'ld back up if I were you!\n";
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
       
