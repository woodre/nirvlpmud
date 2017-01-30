inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("batman")) move_object(clone_object("/players/heroin/hunting_grounds/batman.c"), this_object());
short_desc="Batman's cave";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/batcve.c","north",
"players/heroin/hunting_grounds/hallway.c","leave"});
long_desc=
"You thought it was funny that the batcave was so tiny. Now you\n"+
"have found the real headquarters of batman.  You really thought it\n"+
"would be more spectacular than it is.  There are no fancy computers,\n"+
"no butler running around kissing butt, and no BATCAR?? huh, wait a\n"+
"minute thats strange- the tracks from before lead into this room\n"+
"but no batcar.  You wonder where it could have possibly gone. You\n"+
"do notice a few things. In the middle of the room there is huge hole\n"+
"with a fireman's pole in the middle of it.  The pole appears to lead\n"+
"down into nothing. Nonetheless, before you can worry about that, you\n"+
"have an obligation to take care of: The death of Batman!\n";
}
init(){
::init();
add_action("listen","listen");
add_action ("move_down","down") ;
add_action("kill","kill");
add_action("search","search");
}
kill(str){
object test;
test = (present("counter", this_player()));
if (test) { test->inc_count();}
}
move_down(){
say (tp + "disappears down the hole\n");
write("weeee ....You slide down the pole\n");
move_object(this_player(),"players/heroin/hunting_grounds/gordqrtrsd.c");
return 1;
}
search(){
write("You find nothing of interest.\n");
say(tp +"shrugs.\n");
return 1;
}
listen(){
write("You hear the sounds of traffic.\n");
say(tp + "listens attentively\n");
return 1;
}
