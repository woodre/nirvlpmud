inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="The NEWBIES' TV Room";
items=({
"tv","In the middle of the room sits a large tv set.  It is on and\n appears to stay that way.  The only thing really strange about the tv, is that \n the screen is covered in blood.  In fact, the blood seems to\n be on the inside of the tvalso???"});
dest_dir=({
"/players/heroin/hunting_grounds/hunt1.c","up",
"players/heroin/hunt_newbies/POR.c","two",
"players/heroin/hunt_newbies/beaver.c","three",
"players/heroin/hunt_newbies/LIVE.c","one"});
long_desc=
"You descend down the stairs to find yourself in a small, comfortable\n"+
"living_room.  You think to yourself: this must be where Angst comes\n"+
"to kick-back when he's not feeling like the major hunt.  In the room\n"+
"you notice a few things: first is a large tv set; in front of the tv\n"+
"is a recliner with a remote control sitting on the arm. Finally, up on\n"+
"the wall is a small embroidered sign.  The sign reads:\n"+
"*****************************************************************\n"+
"*              GOD BLESS ALL NEWBIES                            *\n"+
"*           WATCH SOME TV and LEARN HOW TO KILL                 *\n"+
"* ***************************************************************\n"+
" You understand now: pick a channel and learn the desire to kill\n"+
"through watching annoying tv programs..GOOD LUCK\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You find last weeks' TV guide..nothing important.\n");
say(tp + "searches the lazy-boy.\n");
return 1;
}
listen(){
write("Surprising, but this room is quite quiet compared to upstairs.\n");
say(tp + "tells you: I could hear a pin drop....\n");
return 1;
}
