inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(!present("guardalien2")) move_object(clone_object("/players/heroin/hunting_grounds/guardalien2.c"), this_object());
if(!present("guardalien")) move_object (clone_object("/players/heroin/hunting_grounds/guardalien.c"), this_object());
short_desc="Deep within the Ship";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/corr1.c","swing",
"players/heroin/hunting_grounds/hives.c","east"});
long_desc=
"As you land on the other side of the hole..you find yourself in \n"+
"quite a little pickle.  When you jumped you landed on some kind\n"+
"pod of some sort and your friends here dont seem happy about it!\n"+
"You dive out of the way as to give yourself a chance to regroup\n"+
"and look around.  The silcone like substance you saw in the last\n"+
"corridor seems to completely encase this room.  However here the\n"+
"substance seems hard.  The room is dark and with that crap everywhere\n"+
"it is hard to get your bearings...Your friends seem particularly\n"+
"interested in blocking the path directly in front of you..hmm\n"+
"wonder whats is so important.. You obviously dont feel your life is\n"+
"or you wouldn't be here!\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("smell","smell");
add_action("search","search");
}
kill(str){
object test;
test = (present("counter", this_player()));
if (test) {test->inc_count();}
}
search(){
write("You find nothing- that is, nothing you would want to touch\n");
say(tp + "fails to find anything\n");
return 1;
}
smell(){
write("You smell food, but from where, must be close by!\n");
say(tp + "drools. uhh hungry or lust? You decide.\n");
return 1;
}
listen(){
write("HSSSS HSSSS..a selection from the Sounds of Death\n");
say(tp + "taps their feet and whistles along\n");
return 1;
}
