inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("urchen")) move_object(clone_object("players/heroin/hunting_grounds/urchen.c"), this_object());
if (!present("urchen2")) move_object(clone_object("players/heroin/hunting_grounds/urchen2.c"), this_object());
if(!present("urchen3")) move_object(clone_object("/players/heroin/hunting_grounds/urchen3.c"), this_object());
short_desc="London";
items=({
"woman","This is a recently deceased woman.  Man what a mess, \n there lacerations all over her head, neck and torso.\n All her possessions are still laying next\n to her on the ground.  The killer must not\n have been interested in her money.\n what could have possibly possessed a person to\n do such a haneous act.  We have\n a real sicko on our hands.",
"blood","You notice a trail of wet blood leading into the alley.\n You must have just missed the killer",
"walls","As you examine the murder scene, you notice deep, lashes\n in the wall.  No ordinary killer could have done this"});
dest_dir=({
"/players/heroin/hunting_grounds/hallway.c","leave",
"players/heroin/hunting_grounds/alley.c","south",
"players/heroin/hunting_grounds/scotyrd.c","southeast",});
long_desc =
" As Angst's cackle dissipates from your head, you find yourself\n"+
"lying in the gutter of long ago London.  You search you memory\n"+
"for any information on why you'ld be in London.  I mean London\n"+
"has seen rough times-but still why would have Angst sent you here\n"+
"NO..it cant be...But that was only a story..Could it be? Could\n"+
"Angst have sent me here to hunt one of the most notorious killers\n"+
"of all time..The man who preyed on the women of London..Nahh\n"+
"Well your thoughts turn to the immediate scene..The lady in the\n"+
"picture?!?  She's DEAD!!!  You look at the bloody heap of woman\n"+
"lying on the ground when you notice a couple of comman street\n"+
"kids rumaging through the woman's bag.  Little scum. You\n"+
"also notice that the walls of the buildings have interesting\n"+
"marks on them....What is this??? Behind me is Scotland Yard and\n"+
"all of this crime is still going on.  \n";
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
if (test) { test->inc_count();}
}
search(){
write("Leading away from the body is a trail of fresh blood.\n");
say(tp+" says my God don`t you see it.\n");
return 1;
}
smell(){
write("The sticky fog smell permeates your senses..\n Its going to hard to track in the fog\n");
say(tp+" waves there hand in front of their face.\n");
return 1;
}
listen(){
write("you hear that sound that a billy-club makes\n when it hits a rope-chain\n");
say(tp + " says I understand why the cops arent here\n They are off pracicing with their billy clubs\n");
return 1;
}

