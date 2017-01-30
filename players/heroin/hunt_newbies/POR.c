inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(!present("contestant")) move_object(clone_object("/players/heroin/hunt_newbies/contests.c"), this_object());
if(!present("contests2")) move_object(clone_object("/players/heroin/hunt_newbies/contests2.c"), this_object());
if(!present("contests3")) move_object(clone_object("/players/heroin/hunt_newbies/contests3.c"), this_object());
if(!present("contests4")) move_object(clone_object("/players/heroin/hunt_newbies/contests4.c"), this_object());
short_desc="The Price is Right";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunt_newbies/newb_ent.c","tv",
"players/heroin/hunt_newbies/stage.c","up"});
long_desc=
"You drop from out of the air into a swarm of overexcited people\n"+
"The people are yelling out numbers and jumping up and down.  What\n"+
"in the hell is going on?  As you get to your feet, you look around\n"+
"and see that you have dropped into a filming of the Price is Right.\n"+
"Right on: you think to yourself, I get to hang with Bob.  \n"+
"all of a sudden you hear the words you have dreamed of...Hey You.\n"+
"Come On Down, You are the Next Contestant on the Price is Right\n"+
"However, the only problem is the contestants between you and the \n"+
"stage, guess you better kill them!\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You find a love letter to Bob Barker: MAn these people are sick.\n");
say(tp + "shakes their head in disbelief\n");
return 1;
}
listen(){
write("You hear nothing over the roar of the crowd.\n");
say(tp + "covers their ears.\n");
return 1;
}
