inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="The Predator's lair.";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/predsplace.c", "run",
"players/heroin/hunting_grounds/predsplace3.c","whine",});
long_desc=
"You are now in the lair of the Predator.  Everything here is\n"+
"in a constant state of fluctuation, so it is hard to get your bearings.\n"+
"All you really need to be concerned with is standing in front of you.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
query_realm() {return "NT";}
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
