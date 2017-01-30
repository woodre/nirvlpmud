inherit "room/room";

#define tp this_player()->query_name()
int book, desk;

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Magick's Bedroom";
items=({
  "bed","This bed is filthy, the sheets and blankets are all askew",
  "pentagram","This is the sort of pentagram used in making gates",
  "bones","There are bones of every size here",
  "herbs","Some nightshade, and mandrake root and other such herbs",
  "components","You know, eye of newt.  Wing of bat",
  "debri","You fear some of the junk in this room",});
dest_dir=({
"players/unsane/xmen/inter.c","west",});
long_desc =
"  This bedroom is almost an exact opposite to the stark orderliness of \n"+
"Professor X's bedroom.  The room is painted every inch in flat black\n"+
"paint.  Animal bones, herbs and other spell components hang from the ceiling.\n"+
"A large pentagram is drawn on one of the walls and it appears to be drawn in\n"+
"blood!  There is all sorts of scattered debri littering the floor here, and\n"+
"the bed is unmade.  This room is chaos.\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("You are smart enough to know not to mess around in a mage's room.\n");
say(tp+" thinks about searching but then gets a grip on themself.\n");
return 1;}
smell(){
write("This room smells of spice and decay.\n");
say(tp+" takes a deep breath of the air.\n");
return 1;
}
listen(){
write("You hear an odd humming sound here.\n");
say(tp + " perks up their ears.\n");
return 1;
}

