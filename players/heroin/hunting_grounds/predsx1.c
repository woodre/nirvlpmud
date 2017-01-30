inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="The Predator's lair";
items=({
"change", "change"});
dest_dir=({
"players/heroin/hunting_grounds/predsx2.c","hunt",
"players/heroin/hunting_grounds/hunt1.c","whine",});
long_desc=
"You are now in the lair of the Predator.  Everything here is\n"+
"in a constant state of fluctuation, so it is hard to get your bearings.\n"+
"You have the distinct impression that all of Nirvana is aware of you.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("read","read");
add_action("search","search");
}
query_realm() {return "NT";}
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
