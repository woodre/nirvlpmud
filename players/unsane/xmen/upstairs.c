inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("sabertooth")) move_object(clone_object("/players/unsane/xmen/sabertooth"), this_object());
short_desc="The Control Room";
items=({
  "door","This is the front door, and the only exit",
  "stairs","These stairs go down to the basement",});
dest_dir=({
"/players/unsane/xmen/hall.c","north",
"players/unsane/xmen/stairs.c","down",
"players/unsane/xmen/mansion.c","south",});
long_desc =
"  This is the ground floor of the X-men mansion.  To the south of you is the\n"+
"front door to the mansion.  It is also the way out if you are interested.\n"+
"This hallway continues to the north where there are some rooms and such\n"+
"It appears that this is the floor where the X-men live on.  The staircase\n"+
"spirals down to the depths below.  You think you hear some shouting up\n"+
"ahead of here?\n";
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
if (present("sabertooth")) write("The smell of animal is strong here.\n");
else write("The smell of Sabretooth still lingers.\n");
say(tp+" takes a deep breath of the air.\n");
return 1;
}
listen(){
if (present("sabertooth")) write("You hear sabertooth breathing.\n");
else write("It is now silent here.\n");
say(tp + " perks up their ears.\n");
return 1;
}

