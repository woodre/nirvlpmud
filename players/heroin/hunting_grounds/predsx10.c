inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(present("predator")){
destruct("predator",this_object());
}
short_desc="YOU BETTER STOP AND LOOK BEFORE ENTERING.";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/preds/hg1.c","war",
"players/heroin/hunting_grounds/hunt1.c","whine",});
long_desc=
"Tis is the entrance to the Battle Grounds.\n"+
"The Predators in this area WILL hunt if attacked\n"+
"set your wimpy high and figure out a plan\n"+
"of escape before killing.....have fun.\n"+
"One last thing, the only way out is get a predator gem\n"+
"But dontfret there is a bar located within...Thanks, Heroin.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("south","south");
add_action("read","read");
add_action("search","search");
}
query_realm() {return "NT";}
south(){
object predator;
if(present("predator", this_object())){
predator = present("predator", this_object());
destruct (predator);
move_object(this_player(),"/players/heroin/hunting_grounds/hunt1.c");
return 1;}}
/*
read(str){
write("Due to unseen problems with the Predator, he is temparily\n");
write("relieved of duty.  He  will once again be released in the next\n");
write("day or so.  I am fixing him so you'll only be able to fight \n");
write("him if you have a good kill ratio, and then he will come to \n");
write("you.  Sorry for inconvience this may have caused.  Also if\n");
write("you have any suggestions or comments..please write me.\n");
write("XOXOXOXOXOXOXOX,   Heroin\n");
say (tp +" reads Heroin's note and begins to weep, well sob really.\n");
say (tp + "tells you:  I will miss him, I hope Heroin hurries.\n");
return 1;
}
*/
search(){
write("You find nothing that can help you.\n");
say(tp + "is desperate.\n");
return 1;
}
listen(){
write("You hear your heart thumping.\n");
say(tp + "begins to shake.\n");
return 1;
}
