inherit "room/room";

#define tp this_player()->query_name()
object dog;

reset (arg){
if (!arg){
set_light(1);
}
if (!present("demon")) {
dog = clone_object("players/unsane/closed/hell/dog.c");
move_object(dog, this_object());
}
short_desc="The Third Circle of Hell";
 long_desc=
"    This is the circle that holds the gluttons.  Thank god it is empty.\n"+
"This place is really dismal.  You stand here at the side of an enormous mountain\n"+
"but you can hardly see it for all the rain pouring around you.  It would\n"+
"be an injustice to call this rain however.  It is as if water is pouring out\n"+
"of the sky in sheets.  You are immediately drenched.  You are immediately\n"+
"chilled to the bone.  This place is terrible.  You can sense an evil aura\n"+
"here.  Suddenly you can see an outline of a creature hidden by the rain\n"+
"All you can see of it right now is a giant shadow.  But it is coming closer.\n"+
"Wait!  The Beast emerges!  It is Cerberus!\n";
items=({
 "rain","The torrential rain is falling down in sheets",
 "water","The water pools up all across the ground",
  "shadow","It has emerged as the dog, Cerberus",
  "sky","The sky is dark and clouded here",
"mountain","You can hardly see this immense formation for the rain",});
dest_dir=({
"/players/unsane/closed/hell/circle1.c","flee",});
}
init(){
::init();
add_action("listen","listen");
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
write("You can hear the slow rhythmic breathing of Cerberus.\n");
}
say(tp + " perks up their ears.\n");
return 1;
}
