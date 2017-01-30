inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("roach")) move_object(clone_object("/players/unsane/chaos/roach.c"), this_object());
if (!present("wolverine")) move_object(clone_object("/players/unsane/xmen/wolverine"), this_object());
if (!present("nightcrawler")) move_object(clone_object("/players/unsane/xmen/nightcrawler"), this_object());
short_desc="The Danger Room";
items=({});
dest_dir=({
"players/unsane/xmen/control.c","up",});
long_desc =
"  You have entered the fabled danger room of the X-men.  It is the ultimate\n"+
"in state-of-the-art virtual reality.  Here the X-men practice as a team\n"+
"agains whatever illusions the danger room can through at them.  Be careful\n"+
"because it is hard to tell illusion from reality here.  Right now, the danger\n"+
"room is completely blank and empty.  They must be between sessions\n"+
"right now.  There are usually a few X-men practicing here as well.\n";
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
write("There is no odor to be detected here.\n");
say(tp+" takes a deep breath of the air.\n");
return 1;
}
listen(){
write("There is no noise here.  Perhaps because of the insulated walls?\n");
say(tp + " perks up their ears.\n");
return 1;
}

