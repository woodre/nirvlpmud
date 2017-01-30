inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Deep in X-men Mansion";
items=({
  "doors","There are doors to the east and west, they are both open",
  "glimmer","The glimmer that you noticed turned out to be a force field",
  "force field","This force field is impenetrable",
  "field","A force field!  Boy, they aren't taking any chances",
  "walls","Nope, no secret doors here",});
dest_dir=({
"players/unsane/xmen/magickbed.c","east",
"players/unsane/xmen/xbed.c","west",
"players/unsane/xmen/hall.c","south",});
long_desc =
"  You are now at the beginning of a long hallway of doors.  Right now,\n"+
"there are doors to the east and west of you and the hallway continues far ahead\n"+
"to the north.  You notice a faint glimmer in the air here though, and\n"+
"suddenly you realize why security was so lax up until this point.  You  are\n"+
"standing in front of a telepathic force field.  You will not be\n"+
"able to proceed further down the hall.  You wish you had more time to think \n"+
"this over.  However, the arguing coming from the west is making it hard\n"+
"to think.\n";
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
write("The force field gives off a whiff of Ozone.\n");
say(tp+" takes a deep breath of the air.\n");
return 1;
}
listen(){
write("The voices sound like two males.\n");
say(tp + " perks up their ears.\n");
return 1;
}

