inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(!present("eddie")) move_object(clone_object("/players/heroin/hunt_newbies/eddie.c"), this_object());
short_desc="The Cleavers' Linen";
items=({
"change", "change"});
dest_dir=({
"players/heroin/hunt_newbies/hallway.c","south"});
long_desc=
"This is an ordinary closet filled with bedsheets, towels and stuff.\n"+
"You shrug and begin to leave when you notice something or someone\n"+
"moving around in the corner.  You pull back some coats to reveal\n"+
"Eddie Haskle just sitting there.  You ask eddie: what are you doing?\n"+
"Eddie responds: I am waiting for Mrs. C to go to the bathroom, then\n"+
"I'll get to see why they call this show, Leave It To Beaver..\n"+
"This pisses you off, I mean, June is like your mother or something.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You find nothing.\n");
say(tp + "fumbles around in the dark.\n");
return 1;
}
listen(){
write("You hear a toliet flush and eddie moans.\n");
say(tp + "shakes their head in disgust.\n");
return 1;
}
