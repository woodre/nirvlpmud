inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Estate grounds";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/frntgates.c","scurry",
"players/heroin/hunting_grounds/nugey.c","stalk"});
long_desc=
"Heading off into the back part of the grounds, you find yourself\n"+
"in the perfect position for some good old fashion hunting.  It\n"+
"really has been along time, and after how today has gone- you \n"+
"could really use some R&R.  You see faint motion ahead of you.\n"+
"You Need this hunt...You need to stalk.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("smell","smell");
add_action("search","search");
}
smell(){
write("Like the wild animal you have become-You sniff out your prey\n");
say(tp + "bears his teeth to the sky above\n");
return 1;
}
search(){
write("Nothing here but a trail leading to prey\n");
say(tp + "wastes precious killing time\n");
return 1;
}
listen(){
write("You hear the creaking of trees\n");
say(tp + "looks around carefully\n");
return 1;
}
