object obj;
int i,v;
inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("demon")) {
obj = clone_object("players/unsane/closed/hell/furies.c");
move_object(obj, this_object());
}
short_desc="The Sixth Circle of Hell";
 long_desc=
"You are now at the Sixth Circle, and before you is a great tower.  You guess\n"+
"that the river styx must have served as the Fifth Circle.  Guarding this\n"+
"tower are the Three Furies.  The act together as one being and they are \n"+
"fearsome to behold.  It is rumored that they are related to the hideous\n"+
"being known as Medusa, and compared to her, they are nothing.  But you still\n"+
"have good reason to be frightened.  Another item that you take notice of here\n"+
"is how coherent and stable the landscape is.  There is no changing of \n"+
"colours or shifting in form whatsoever.  You are sure there is a reason for\n"+
"this, but you can't seem to recall.  Perhaps you better turn back before\n"+
"this get even worse for you?\n";
items=({
"river","You are glad those wrathful souls are behind you now",
"sky","The sky is black as pitch here",
"colors","The colors are hardly shifting at all now",
"colours","The colours are hardly shifting at all now",
"landscape","Everything is twisted and jagged in the landscape",
"tower","This tower looms high above you, you don't know who could possibly.\n"+
"be in residence here, but they must be fearsome",});
dest_dir=({
"/players/unsane/closed/hell/river.c","river",
"/players/unsane/closed/hell/tower.c","enter",});
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("There is nothing here.\n");
say(tp+" searches the ground in vain.\n");
return 1;
}
smell(){
write("The odors of the furies and the river combine in a terrible way.\n");
say(tp + " takes a deep breath of the air here.\n");
return 1;
}
listen(){
write("You can hear a screaming off in the distance.\n");
say(tp + " perks up their ears.\n");
return 1;
}
