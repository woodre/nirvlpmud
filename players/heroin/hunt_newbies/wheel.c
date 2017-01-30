inherit "room/room";

#define tp this_player()->query_name()
int i;
object obj;
inherit "room/room";

reset (int arg){
if (!arg){
set_light(1);
}
short_desc="Spin the Wheel";
items=({
"wheel", " Spin the wheel"});
dest_dir=({
"players/heroin/hunt_newbies/stage.c","south"});
long_desc=
"After you finished off Bob and his beauties, you wandered backstage.\n"+
"You move a curtain out of the way and find yourself standing in front\n"+
"of a large wheel with numerical values all over it.  This is the \n"+
"wheel that determines who gets into the final showcase, however\n"+
"since you killed the host; it is very unlikely they will have any\n"+
"use for it.  you start to turn around and leave when you hear\n"+
"someone whispering to you.  Pssst Psst Hey you......you turn around.\n"+
"Hey for the right price Ill let ya spin the wheel.....Hmm maybe you should\n"+
"look at wheel and figure out what to do.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("spin","spin");
add_action("search","search");
}
spin(){
object ob;
if (i==0) {
write("There ya go.\n");
ob = clone_object("/players/heroin/hunt_newbies/rod_jack");
move_object(ob, this_player());
i++;
return 1;}
write("You broke the wheel.\n");
return 1;
}
search(){
write("You just forgot what you were doing.\n");
say(tp + "looks around with a lost look in their eyes.\n");
return 1;
}
listen(){
write("There is nothing to listen to.\n");
say(tp + "shrugs.\n");
return 1;
}
