inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("driver")) move_object(clone_object("/players/heroin/hunting_grounds/driver.c"), this_object());
short_desc="The Limo";
items=({
"magazine","This is a copy of this month's popular magazine: Rockers who Bowhunt"});
dest_dir=({
"/players/heroin/hunting_grounds/bckstage.c","thumb_it",
"players/heroin/hunting_grounds/frntgates.c","doorbell"});
long_desc=
"As you got caught in a rush of reporters, you find yourself shoved\n"+
"into the back of a really enormous limo.  This limo is soooo big\n"+
"that there could be fifty people in here and you would never see\n"+
"a one of them.  So lets recap the recent events: You now have seen\n"+
"someone's concert, snuck back stage, and managed to get a ride in \n"+
"their limo, and you still have no idea who your dealing with? How \n"+
"rude.  You notice some reading material laying on the seat. Might as\n"+
"check it out while your waiting for the car to stop.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("search","search");
}
kill(str){
object test;
test =(present("counter", this_player()));
if (test) { test->inc_count();}
}
search(){
write("You find a magazine.\n");
say(tp + "snoops around.\n");
return 1;
}
listen(){
write("You cant hear anything, the way riding in a luxary car should be!\n");
say(tp + "looks into the tinted window and checks for boogers\n");
return 1;
}
