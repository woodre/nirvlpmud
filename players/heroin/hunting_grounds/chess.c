inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(!present("Chester")) move_object(clone_object("/players/heroin/hunting_grounds/chess_ter.c"), this_object());
short_desc="The frustrated Gameplayer";
items=({
"pieces","Scattered throughout the room are giant chess pieces."});
dest_dir=({
"/players/heroin/hunting_grounds/hunt1.c","whistle",
"players/heroin/hunting_grounds/hallway2.c","north"});
long_desc=
"	This is really one of the strangest rooms you have ever\n"+
"seen.  The room is filled with black and white tiles and huge\n"+
"chess pieces.  In the middle of the room, sits a man on a chair\n"+
"You really are not sure whether he is alive or dead.  There is \n"+
"about an inch of dust on him.  As you approach you are almost sure\n"+
"you say his eyes open...But then again maybe they were always open?\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("search","search");
}
search(){
write("You notice that the floor is scraped up around the white bishop.\n");
say(tp + "ponder the situation.\n");
return 1;
}
kill(str){
object test;
test =(present("counter", this_player()));
if (test) { test->inc_count();}
}
listen(){
write("Shhhhh..The game of chess requires deep concentration.\n");
say(tp + "tells you shhhhhh.\n");
return 1;
}
