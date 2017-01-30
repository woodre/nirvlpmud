inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="The Cleavers' Hallway";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunt_newbies/closet.c","north",
"players/heroin/hunt_newbies/b-room.c","west",
"players/heroin/hunt_newbies/beaver.c","down"});
long_desc=
"This is a fairly short hallway with a variety of doors leading off\n"+
"of it.  There realy isn't anything special about the hallway other\n"+
"than it belongs to the Cleavers, making it special.  Two doors catch\n"+
"your attention, one at the end of the hallway; which looks like a \n"+
"linen closet: and a door to you west, which has a picture of a \n"+
"baseball player on it.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("Nothing, absolutely nothing here.\n");
say(tp + "searches around.\n");
return 1;
}
listen(){
write("You hear two boys talking to the west.\n");
say(tp + "listens at the door.\n");
return 1;
}
