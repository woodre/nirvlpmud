inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("robin")) move_object(clone_object("/players/heroin/hunting_grounds/robin.c"), this_object());
short_desc="The Bat Cave";
items=({
"scribblings","The scribblings read: Things to do today- \n 1. buy toilet paper 2. go see Comm. Gordon",
"tracks","The tire tracks you have been following disappear into the wall",
"wall","Noticing the tracks, you decide to examine the walls of the\n batcave.  At first, the texture and heaviness of the stone seems\n genuine, however, something is still not quite right\n Batman is near."});
dest_dir=({
"/players/heroin/hunting_grounds/gotham.c","north"});
long_desc=
"The darkness of the cave engulfs you as you step in.  As you begin\n"+
"to get your bearings, you have see that you have come to a deadend.\n"+
"The cave is damp and musty, and you begin to sneeze violently.  From\n"+
"behind, you hear a faint whisper: Bless You.  You turn around a draw \n"+
"dead-aim at the forehead of a young boy in bright leotards.\n"+
"Coming to your senses and realizing that it is only the boy-wonder\n"+
"you relax and begin to look around.  The tire tracks you have been\n"+
"following are here, however something is weird about them..hmmm, \n"+
"and the walls seem really strange also.\n";
}
init(){
::init();
add_action("smell","smell");
add_action("kill","kill");
add_action("listen","listen");
add_action("search","search");
}
kill(str){
object test;
test =(present("counter",this_player()));
if (test) {test->inc_count();}
}
search(){
write("You see some scribbling on the walls\n");
say(tp + "looks toward the east wall\n");
return 1;
}
smell(){
write("Ha Ha Choooo.\n");
say(tp + "sneezes violently\n");
return 1;
}
listen(){
write("Squeek Squeek \n");
say(tp + "removes the bats from their hair\n");
return 1;
}
