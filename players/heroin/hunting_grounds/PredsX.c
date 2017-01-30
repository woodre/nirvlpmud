inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
/* omission by mizan, this causes the room to go fucko 
if(!present("predator")) move_object(clone_object("/players/heroin/hunting_grounds/predatorX.c"), this_object());
 */
short_desc="The Predator's lair.";
items=({
"change", "change"});
dest_dir=({
"/room/church","cower",});
long_desc=
"You are now in the lair of the Predator.  Everything here is\n"+
"in a constant state of fluctuation, so it is hard to get your bearings.\n"+
"All you really need to be concerned with is standing in front of you.\n"+
"As you take a closer look, you seem to be surrounded by screens of\n"+
"of some sort.  On the screen, you see what appears to be the village\n"+
"church.  You see players you recognize and feel a deep urge to be \n"+
"with them.  This must have been how the Predator kept track of you.\n"+
"Now, if only you could find a way out..The Predator simulates your \n"+
"speech, and as if was reading your thoughts, says: Human, you have\n"+
"to choices: either COWER and bow before me, or, try and KILL me.\n"+
"Either way, you will never be anything more than a trophy to me...\n";
}
init(){
::init();
add_action ("drop","drop");
add_action("listen","listen");
add_action("search","search");
}
realm () {return "NT";}
drop(str) {
string all;
command ("drop all", this_player());
move_object (this_player(), "/room/church");
return 0;
}
search(){
write("You find nothing that can help you.\n");
say(tp + "is desperate.\n");
return 1;
}
listen(){
write("You hear your heart thumping.\n");
say(tp + "begins to shake.\n");
return 1;
}
