inherit "room/room";

#define tp this_player()->query_name()
int i;
object obj;
inherit "room/room";

reset (int arg){

if (!arg){
set_light(1);
}
short_desc="The Meat lockers";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/hunt1.c","enter",
"room/plane5","whine"});
long_desc=
"As your head quits spinning, you pull yourself off the ground to\n"+
"find yourself in a new area.  You are in large cold room. The walls\n"+
"are covered in stainless steel and the floor is concrete.  You think\n"+
"to yourself: This must be Heroin's domain.  How strange, I appear to\n"+
"be in a meat locker.  A image appears in front of you and begins to \n"+
"speak:  I am Heroin, and you are now where I reign supreme.  In my\n"+
"world there are only two types of creatures: the hunter and the hunted.\n"+
"Here you are both.  The stakes are high but so are the rewards.  \n"+
"There are a few things I must tell you before you enter the hunt.\n"+
"First, the creatures I have gathered here are attracted by spilt\n"+
"blood, meaning the more you kill , the more likely you are to attract\n"+
"other hunters.  Second, since we are playing for keeps, at this time\n"+
"I discourage players under level 12 from entering the main areas.  \n"+
"There is a newbie area, just type <enter>, then <newbie>.\n"+
"Finally as a hunter you\n"+
"you need to be aware of your enviroment, so use your senses at all\n"+
"times.  Good Luck!\n"+
"The image of Heroin disppears and you are left with a choice.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("enter","enter");
add_action("search","search");
}
enter(){
object ob;
if (!present("counter",this_player())){
ob = clone_object("players/heroin/count");
move_object(ob, this_player());
}
}
search(){
write("Already looking? You are not even playing yet.\n");
say(tp + "say: I am a scavenger.\n");
return 1;
}
listen(){
write("You hear the applauds of all Nirvana; They think you're brave!\n");
say(tp + "thanks his audience.\n");
return 1;
}
