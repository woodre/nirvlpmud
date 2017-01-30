inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
 
reset (arg){
if (!arg){
set_light(2);
}
if(!present("predator")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx4.c"), this_object());
if(!present("predator2")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx3.c"), this_object());
if(!present("predator3")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx5.c"), this_object());
if(!present("predator4")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx.c"), this_object());  
if(!present("predator5")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx9.c"), this_object());
short_desc="The Battle Grounds   ";
dest_dir=({
"/players/heroin/hunting_grounds/preds/hg10","north",
"/players/heroin/hunting_grounds/preds/hg1","south",});
long_desc =
"As you wander north you notice more predators coming out of\n"+
"the woodwork..These Predators arent interested in you, however.\n"+
"They seem to be gathering around a small sign\n"+
"You take a closer look a the sign and it reads:\n"+
"Get Your drinks at Heroin's House of Ill Repute\n"+
"Head up into the trees to avoid traffic!\n"+
"the drinks arent cheap but not like you have any choice\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
add_action("path","path");
add_action("kill","kill");
   add_action("read","read");
   add_action("search","search");
}
path() {
if(present("badge",this_player())) {
write("You follow the path around...and look who's here.\n");
move_object(this_player(), "/players/heroin/quests/room/khan4.c");
command("look",this_player());
return 1;}
else {
write("You can't go there yet.\n");
return 1;}
}
kill(str){
object test;
test=(present("counter", this_player()));
if (test) {test->inc_count();}
}
search(){
write("The PATH, the PATH.\n");
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
                    
