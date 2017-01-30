inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="A Long Winding Staircase";
items=({});
dest_dir=({
"players/unsane/xmen/control.c","down",
"players/unsane/xmen/upstairs.c","up",});
long_desc =
"  This is a long and windy staircase that spirals up to the main floor of\n"+
"the mansion.  It would have been much easier to have entered through the\n"+
"front door, but you know how these super heroes are.  You wonder what is \n"+
"upstairs anyhow?\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("You notice a tuft of fur on the ground here.  Wonder what that means?\n");
say(tp+" searches and finds something.\n");
return 1;
}
smell(){
write("You think you smell an animal.\n");
say(tp+" takes a deep breath of the air.\n");
return 1;
}
listen(){
write("All is quiet right now.\n");
say(tp + " perks up their ears.\n");
return 1;
}

