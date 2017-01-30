inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(!present("bob")) move_object(clone_object("/players/heroin/hunt_newbies/barker.c"), this_object());
if(!present("babe")) move_object(clone_object("/players/heroin/hunt_newbies/bobs_beauts.c"), this_object());
if(!present("babe")) move_object(clone_object("/players/heroin/hunt_newbies/bobs_beauts.c"), this_object());
if(!present("babe")) move_object(clone_object("/players/heroin/hunt_newbies/bobs_beauts.c"), this_object());
short_desc="Price is Right's stage";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunt_newbies/wheel.c","showdown",
"players/heroin/hunt_newbies/POR.c","down"});
long_desc=
"You must have successfully guessed the right number because you\n"+
"are now on Bob's stage.  Also joining you, that is, besides Bob, \n"+
"are Bob's beauties.  Uh oh, they are pulling out PLinko .  Not\n"+
"being able to stand the excitement, you get the deep urge to kill\n"+
"the whole lot of them.  One thing is for sure, that heavy-set, \n"+
"announcer fella is still to be seen, you know- the one who wears\n"+
"sequines.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("There is nothing here of significance.\n");
say(tp + "grubs around\n");
return 1;
}
listen(){
write("You hear a roar of various numbers being yelled at you.\n");
say(tp + "mouths to the crowd: One?? One??\n");
return 1;
}
