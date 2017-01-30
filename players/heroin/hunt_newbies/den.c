inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(!present("ward")) move_object(clone_object("/players/heroin/hunt_newbies/ward.c"), this_object());
short_desc="The Cleaver Den";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunt_newbies/beaver.c","east",
"players/heroin/hunt_newbies/kitchen.c","west"});
long_desc=
"You push open a wood door, and walk into what appears to be someone's/n"+
"den or library.  The furnishings are fairly nice and the walls are\n"+
"filled with books and trophies.  In the middle of the room, you \n"+
"notice man sitting with his back to you. The man appears to be \n"+
"reading a book and smoking a pipe.  You walk around to get a better\n"+
"look at him discover who the man is: It is Ward Cleaver..You are\n"+
"in an episode of Leave it to Beaver.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You find many books all interesting, but none that you can take.\n");
say(tp + "skims through the book shelves\n");
return 1;
}
listen(){
write("You hear whistling coming from the west.\n");
say(tp + "looks puzzled.\n");
return 1;
}
