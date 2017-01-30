inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="A Hallway";
dest_dir=({
"/players/unsane/xmen/dungeon.c","south",
"players/unsane/xmen/control.c","north",});
long_desc =
"  This is a fairly long hallway leading out of the dungeon.  It seems like\n"+
"the dungeon was nothing more than an entrace to this secret area.  The\n"+
"voices you heard earlier are a little further up.  It sounds like there is a \n"+
"battle going on up there as well.  You better hurry.\n";
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
write("You think you are getting a faint whiff of ozone.\n");
say(tp+" takes a deep breath of the dusty air.\n");
return 1;
}
listen(){
write("The arguing is getting louder and louder.  You can also hear guns?\n");
say(tp + " perks up their ears.\n");
return 1;
}

