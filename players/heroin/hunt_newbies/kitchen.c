inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(!present("june")) move_object(clone_object("/players/heroin/hunt_newbies/june.c"), this_object());
short_desc="June's Kitchen";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunt_newbies/beaver.c","west",
"players/heroin/hunt_newbies/den.c","east"});
long_desc=
"You have found the source of that delicious smell: June Cleaver's\n"+
"kitchen.  Even though it appears that June has been cooking for \n"+
"about 10 hours straight, the kitchen is emmacuately clean.  Just \n"+
"the sight of June makes you smile, however, you somehow realize\n"+
"beneath that motherly exterior lies a cold, hardened creature of\n"+
"the night, who will spread chaos throughout the universe if given\n"+
"half a chance.  Well, ok maybe not, but you need some excuse to kill\n"+
"her, afterall how else will you get those cookies?\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You find a recipe for a pot roast, but June grabs it from your hand\n");
say(tp + "smacks their lips\n");
return 1;
}
listen(){
write("You hear a buzzer going off.\n");
say(tp + "tells you: would ya like to see me in an appron?\n");
return 1;
}
