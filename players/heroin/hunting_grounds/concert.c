inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("groupie")) move_object(clone_object("/players/heroin/hunting_grounds/groupie.c"), this_object());
if (!present("teen")) move_object(clone_object("/players/heroin/hunting_grounds/teen.c"), this_object());
short_desc="A Rock Concert";
items=({
"stub","A ticket stub. On the stub you make out the words: \n motor and madman..32 dollars..jesus, Fey productions suck."});
dest_dir=({
"/players/heroin/hunting_grounds/hallway2.c","leave",
"players/heroin/hunting_grounds/bckstage.c","east"});
long_desc=
"You come to your senses only to find yourself in the middle\n"+
"20-30 thousand screaming rockers.  You are behind a couple of\n"+
"guys who being at a concert -of course- have a screaming topless\n"+
"girls on their shoulders.  Shit- if you could only get a better \n"+
"look you might be able to figure out what was going on.  Maybe, \n"+
"you could find out some other way?\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("smell","smell");
add_action("search","search");
}
kill(str){
object test;
test = (present("counter", this_player()));
if (test) { test->inc_count();}
}
smell(){
write("What is that. OH MAN, dont ya hate when your stuck in a crowd\n and someone stinkers\n");
say(tp + "looks at you with disgust in their eyes\n");
return 1;
}
search(){
write("you find a ticket stub stuck to the ground\n");
say(tp + "stares at the ground, maybe they lost a contact\n");
return 1;
}
listen(){
write("There is too much noise to make out anything\n");
say(tp + "puts their fingers in their ears\n");
return 1;
}
