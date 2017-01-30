 
inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
 
reset (arg){
if (!arg){
set_light(2);
}
if(!present("predator")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx.c"), this_object());
short_desc="The Battle Grounds   ";
dest_dir=({
"/players/heroin/hunting_grounds/preds/bar2.c","west",
"/players/heroin/hunting_grounds/preds/hg1.c","down",});
long_desc =
"You climb up into the think brush. You catch a predator\n"+ 
"by surprise.  Wait a minute, Is he drunk???!!!?!??!\n"+
"You see a hole in the brush to the west.\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
add_action("kill","kill");
   add_action("read","read");
   add_action("search","search");
}
/*
west(){
object predator;
if(present("predator", this_object())){
predator = present("predator", this_object());
destruct (predator);
move_object(this_player(), "/players/heroin/hunting_grounds/preds/bar2.c");
return 1;}}
*/
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
    
