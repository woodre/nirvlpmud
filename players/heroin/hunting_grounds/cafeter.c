inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("medalien")) move_object(clone_object("/players/heroin/hunting_grounds/medalien.c"), this_object());
if (!present("medalien")) move_object(clone_object("/players/heroin/hunting_grounds/medalien.c"), this_object());
if (!present("medalien")) move_object(clone_object("/players/heroin/hunting_grounds/medalien.c"), this_object());
short_desc="Recreation room";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/robotqtrs.c","west",
"players/heroin/hunting_grounds/corr2.c","north"});
long_desc=
"You squeeze past the reenforcements on the door and end up in\n"+
"a recreation room of some sort.  This room appears to have been used\n"+
"for a variety of purposes including eating, meetings, and cards.\n"+
"Now the good old days are gone for this room- it has new purposes:\n"+
"it is an incubation room.  Actually, it is a good thing your here\n"+
"since you can provide what these new aliens need most: Food!\n"+
"The aliens seem to appreciate your generousity. If there were only\n"+
"more good-hearted people like you- noone would go hungry.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("search","search");
}
kill(str){
object test;
test =(present("counter",this_player()));
if (test) { test->inc_count();}
}
search(){
write("You reach down thinking you found something, but alas, you were mistaken\n");
say(tp + "says: shucks!\n");
return 1;
}
listen(){
write("There is a suction sound comin from somewhere close by, perhaps a hull breach\n");
say(tp + "appears to be deep in thought.\n");
return 1;
}
