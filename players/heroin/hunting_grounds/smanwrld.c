inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("lex")) move_object(clone_object("/players/heroin/hunting_grounds/lex.c"), this_object());
short_desc="DC Comic's extras";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/sewerent.c","west",
"players/heroin/hunting_grounds/jokes.c","snicker"});
long_desc=
"	This is a room reserved for DC Comics extra personalities\n"+
"-all the characters which have little worth in DC's world.  Angst\n"+
"in all his infinite goodness, just couldn't let this villians & \n"+
"superheros go to waste.  So now- this room will forever be a \n"+
"storeroom of sorts for comicbook extras.  Be gentle with them, they\n"+
"have all been rejected once afterall.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("search","search");
}
kill(str){
object test;
test = (present("counter", this_player()));
if (test) { test->inc_count();}
}
search(){
write("You find a pile of used kleenex.\n");
say(tp + "blows his honker\n");
return 1;
}
listen(){
write("All you hear is laughing and crying.\n");
say(tp + "begins to snicker like a madman\n");
return 1;
}
