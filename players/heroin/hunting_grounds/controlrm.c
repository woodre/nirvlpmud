inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("smalien")) move_object(clone_object("/players/heroin/hunting_grounds/smalien.c"), this_object());
if (!present("smalien")) move_object(clone_object("/players/heroin/hunting_grounds/smalien.c"), this_object());
if (!present("smalien")) move_object(clone_object("/players/heroin/hunting_grounds/smalien.c"), this_object());
if (!present("smalien")) move_object(clone_object("/players/heroin/hunting_grounds/smalien.c"), this_object());
short_desc="The Control Room";
items=({
"mother","This is Mother- the ship's onboard computer. If you were\n to need information, she would be the one to give it. However, \n Mother appears to be turned off right now."});
dest_dir=({
"/players/heroin/hunting_grounds/crewqtrs.c","west",
"players/heroin/hunting_grounds/corr2.c","south"});
long_desc=
"Damn- this is creepy.  You are surrounded by nothing but alien goop\n"+
" and control panels.  This appears to have been the main control\n"+
"room, now it serves as a reminder of what technology can provide\n"+
"for us, DEATH.  The aliens don't seem to have much use for technology\n"+
"So some of this stuff might still be operational, if one was to clean\n"+
"it all up.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("turn","insert");

add_action("kill","kill");
add_action("search","search");
}
kill(str){
object test;
test = (present("counter", this_player()));
if (test) { test-> inc_count();}
}
search(){
write("As you scrape away some of the alien goop, you uncover a hatch\n of some sort. It appears to have contained computer \n information. However, now it is empty.\n");
say(tp + "scrapes away alien goop\n");
return 1;
}
listen(){
write(" BEEP BEEP ENTE,,,,PERFEC...ORGANI..BEEP\n");
say(tp + "ponders existance: Heavy shit, man.\n");
return 1;
}
