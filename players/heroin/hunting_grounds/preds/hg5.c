inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
 
reset (arg){
if (!arg){
set_light(2);
}
if(!present("predator")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx2.c"), this_object());
if(!present("predator2")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx7.c"), this_object()); 
if(!present("predator3")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx3.c"), this_object()); 
if(!present("predator4")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx9.c"), this_object()); 
if(!present("predator5")) move_object(clone_object("/players/heroin/hunting_grounds/preds/predatorx8.c"), this_object()); 
short_desc="DOMINOS!!!!   ";
dest_dir=({
"/players/heroin/hunting_grounds/preds/hg1","north",});
long_desc =
"Nothing really to describe...Predator Champions\n"+
"tossin bones...join in, looks like fun.\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
/*
add_action("path","path");
*/
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
write("You start yelling: My name is Tommy and I have a nickle.\n");
say(tp + "ponders the situation \n");
return 1;
}
/*
path() {
if(present("badge",this_player())) {
write("You follow the path around...and look who's here.\n");
move_object(this_player(), "/players/heroin/quests/room/khan2.c");
command("look",this_player());
return 1;}
else {
write("You can't go there yet.\n");
return 1;}
}    
*/
smell(){
write("Something's burning-SNIFF SNIFF..Shit its you..KILL THE CORD\n");
say (tp + "turns and sniffs his burning ass.\n");
say (tp + "says: can u sniff your own butt?\n");
return 1;
}
listen(){
write("You hear Heroin Laughing at you.\n");
say(tp + "begins to drool and rub his tummy\n");
return 1;
}
   
