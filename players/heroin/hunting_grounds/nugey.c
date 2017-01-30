inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(!present("Nugent")) move_object(clone_object("/players/heroin/hunting_grounds/Nugent.c"), this_object());
short_desc="Target Practice";
items=({
"target","This is a target made out of straw. As you look closer\n you realze that he is a good shot"});
dest_dir=({
"/players/heroin/hunting_grounds/limo.c","driver",
"players/heroin/hunting_grounds/corr2.c","cry"});
long_desc=
"As you enter, a arrow barely misses your head. You have jumped into\n"+
"someone's target practicing area.  You notice a man drawing up his\n"+
"bow and preparing another shot.  Maybe he hasn't seen you yet or\n"+
"maybe he just doesn't care.  Anothe arrow wizzes by, this one \n"+
"nicking you above your right ear.  You dive and roll only to see\n"+
"yourself in front of a target.  So he isn't shooting at you.\n"+
"You think to yourself: What a dumb ass, let him shoot at his target\n"+
"I'll take this opportunity to kill..hehehhehehe\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("search","search");
}
kill(str){
object test;
test = (present("counter",this_player()));
if (test) {test->inc_count();}
}
search(){
write("You find nothing of significance\n");
say(tp + "shrugs\n");
return 1;
}
listen(){
write("You hear Angst's voice in the back of you mind chanting: Kill Kill Kill Kill Kill Kill\n");
say(tp + "begins daydreaming\n");
return 1;
}
