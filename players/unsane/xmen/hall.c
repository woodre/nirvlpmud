inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="X-men Mansion Ground Floor";
items=({
  "doors","There are two doors up ahead, bedrooms most likely",
  "carpet","This is some ugly ass carpet.  But it is shag",
  "walls","Nope, no secret doors here",});
dest_dir=({
"/players/unsane/xmen/inter.c","north",
"players/unsane/xmen/upstairs.c","south",});
long_desc =
"  This is the ground floor hallway of the X-men's mansion.  Up ahead you,\n"+
"spot some doors on both sides of the hallway.  The walls here are bare, and the\n"+
"carpet is a plain greyish colour.  You don't really notice anything out of the\n"+
"ordinary.  Except for the heated argument you hear coming from one of the rooms\n"+
"up ahead.  Funny, you expected more security on this floor.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("smell","sniff");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("You search and find nothing.\n");
say(tp+" searches around and finds nothing.\n");
return 1;
}
smell(){
write("It smells like musty carpet here.\n");
say(tp+" takes a deep breath of the air.\n");
return 1;
}
listen(){
write("The arguing is getting much louder up ahead.\n");
say(tp + " perks up their ears.\n");
return 1;
}

