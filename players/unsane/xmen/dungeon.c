object obj;
int i,v;
inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="The mansion's dungeon";
 long_desc=
items=({
 "cobwebs","This place needs a good cleaning",
  "dust","The floor is very dusty here",});
dest_dir=({
"/players/unsane/xmen/hallway.c","north",});
long_desc =
"  You have found yourself in a dark dungeon.  You wonder at first why a\n"+
"school for the gifted would even have a dungeon in the first place.  But there,\n"+
"is something nagging at the back of your mind about this place still.  There\n"+
"is dust and cobwebs all about this dungeon.  And you surmise that it must not\n"+
"get much use.  Not only that, but they left the jail door open?  Maybe\n"+
"this is just a reception room?\n";
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
write("This place smells like cobwebs and dust.\n");
say(tp+" takes a deep breath of the dusty air.\n");
return 1;
}
listen(){
write("You can hear the sounds of people arguing in the other room.\n");
say(tp + " perks up their ears.\n");
return 1;
}

