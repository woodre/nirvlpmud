inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Nowhere";
 long_desc=
items=({
 "rain","The torrential rain is falling down in sheets",
 "water","The water pools up all across the ground",
  "shadow","It has imerged as the dog, Cerebus",
  "sky","The sky is dark and clouded here",
"mountain","You can hardly see this immense formation for the rain",});
dest_dir=({
"/players/unsane/closed/hell/circle1.c","flee",});
}
init(){
::init();
add_action("listen","listen");
add_action("smell","sniff");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("You search the muddy earth, but to no avail.\n");
say(tp +" searches the muddy earth in vain.\n");
return 1;
}
smell(){
write("This place smells like mud and wet dog.\n");
say(tp + " takes a deep breath of the air here.\n");
return 1;
}
listen(){
if (!present("demon")) {
write("All you can hear now is the rain falling in sheets.\n");
}
if (present("demon")) {
write("You can hear the slow rhythmic breathing of Cerebus.\n");
}
say(tp + " perks up their ears.\n");
return 1;
}

