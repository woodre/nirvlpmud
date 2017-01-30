inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="A 50's Household";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunt_newbies/den.c","west",
"players/heroin/hunt_newbies/kitchen.c","east",
"players/heroin/hunt_newbies/hallway.c","up",
"players/heroin/hunt_newbies/newb_ent.c","tv"});
long_desc=
"This is weird, you clicked the channel and now you are standing in\n"+
"the front entry way of someone's house.  From the decorations, you\n"+
"figure that you are approximately in the late 50's to early 60's.\n"+
"That would perhaps explain why you and everything else here is black and \n"+
"white, well one things for sure: this isn't the Love Boat.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("smell","smell");
add_action("search","search");
}
smell(){
write("You smell fresh baked cookies from the east and pipe smoke from\n the west.\n");
say (tp + "sniffs the air\n");
return 1;
}
search(){
write("You think you find something, but it was only a shadow.\n");
say(tp + "reaches for something.\n");
return 1;
}
listen(){
write("You hear singing and humming come from the east.\n");
say(tp + "hums along to a unknown tune.\n");
return 1;
}
