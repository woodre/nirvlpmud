inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
 
reset (arg){
if (!arg){
set_light(2);
}
if (!present("predator")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx.c"), this_object());
short_desc="The Battle Grounds   ";
dest_dir=({
"/players/heroin/hunting_grounds/preds/hg2","east",
"/players/heroin/hunting_grounds/preds/hg4","west",
"/players/heroin/hunting_grounds/preds/hg5","south",
"/players/heroin/hunting_grounds/preds/hg6","up",
"/players/heroin/hunting_grounds/preds/hg7","down",
"players/heroin/hunting_grounds/preds/hg3","north",});
long_desc =
" You Leave the warm comfort of Angst's den and find yourself\n"+
"in what appears to be another planet.  The skys burn bright with\n"+
"fire and smoke and the vegetation is as thick as Earth's densest \n"+
"jungles....Angst's voice rings clear: Welcome to the Battle Grounds\n"+
"the Predator race will be happy to rid you of only valuable asset..\n"+
"............YOUR LIFE!!!!!! MUHAHAMUHAHAHAHA\n";
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
                                                
