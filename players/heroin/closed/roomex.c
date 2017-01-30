inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("cyclops")) move_object(clone_object("/players/unsane/xmen/cyclops"), this_object());
if (!present("storm")) move_object(clone_object("/players/unsane/xmen/storm"), this_object());
short_desc="The Control Room";
items=({
  "window","You notice the glass on this window is at least 3 inches thick",
  "equipment","There are all sorts of computer goodies here",
  "computers","These computers are amazingly advanced",
  "consoles","The consoles give readouts on the current danger room session",
  "stuff","You know.....just stuff.",
  "terminals","These terminals are alien in design",});
dest_dir=({
"/players/unsane/xmen/danger.c","down",
"players/unsane/xmen/stairs.c","up",
"players/unsane/xmen/hallway.c","south",});
long_desc =
"  This room is filled with computer consoles, terminals and all sorts of\n"+
"stuff.  Some of this equipment looks too advanced to even be found in the\n"+
"20th century.  The room is in a somewhat circular shape, and it all faces \n"+
"forward to a huge plate glass window.  Glancing out the window you notice that\n"+
"this booth is about 3 stories off the ground, and the room that it is facing\n"+
"is the size of a very large warehouse.  This is the control room to the x-men's\n"+
"danger room!  Usually you will find a few of the x-men controlling the danger\n"+
"room session from this booth.\n";
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
write("The smell of ozone is really strong now.\nYou wonder if the computers are ok?\n");
say(tp+" takes a deep breath of the air.\n");
return 1;
}
listen(){
if (present("cyclops") && present("storm")) write("Storm and Cyclops are in a heated argument.\n");
else if (present("cyclops") || present("storm")) write("The lone X-man is mumbling to themself.\n");
else write("It is now silent here.\n");
say(tp + " perks up their ears.\n");
return 1;
}

