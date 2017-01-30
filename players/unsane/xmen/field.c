object obj;
int i,v;
inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="A grassy field";
 long_desc=
"  You have been transported to a large grassy field somewhere in the Northeast\n"+
"perhaps Connecticut?  The time period appears to be in the 20th century.\n"+
"It is very still here, and you guess it to be some sort of rural area.  Perhaps\n"+
"it is even too still here, but you're not sure.  To the north of here looms an\n"+
"ominous mansion.  It seems to be built in the style of the early 1900's\n"+
"and it is very grand.  There are no cars out in front, that you can see\n"+
"but still it doesn't seem to be abandoned.  There is also a black \n"+
"portal here to the gates of hell.  How pleasant.\n";
items=({
  "sky","The sky here is clear and beautiful",
 "mansion","This beautiful mansion looms ahead of you ominously",});
dest_dir=({
"/players/unsane/closed/hell/circle1.c","portal",
"/players/unsane/xmen/mansion.c","north",});
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("You search and find nothing.\n");
say(tp+" searches around and finds nothing.\n");
return 1;
}
smell(){
write("The air here smells sweetly of grass and flowers.\n");
say(tp+" takes a deep breath of the fragrant air.\n");
return 1;
}
listen(){
write("You can hear the birds chirping and other sounds of spring.\n");
say(tp + " perks up their ears.\n");
return 1;
}

