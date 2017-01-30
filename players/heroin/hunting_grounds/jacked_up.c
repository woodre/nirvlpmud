inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("jack")) move_object(clone_object("players/heroin/hunting_grounds/jack.c"), this_object());
short_desc="Dead, deader, deadest end   ";
dest_dir=({
"/players/heroin/hunting_grounds/alley2.c","leave",
"players/heroin/hunting_grounds/corr1.c","whimper",});
long_desc =
"Welcome to the home of the RIPPER..Your search for the man behind\n"+
"the ghastley murders is over!  However, by the appearance of the \n"+
"room and by Jack himself- You get the distinct impression that you\n"+
"were expected.  Generally, Jack only preys on unsuspecting women\n"+
"However, today he looks quite willing to make an exception. It is\n"+
"strange but you appear to be surrounded by hundreds of dead,\n"+
"slashed-up women, all chanting KILL KILL KILL.  You think to \n"+
"yourself: It all is just a game to Angst isn't it????\n";
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
write("You search your mind for a happy thought\n Your thoughts turn towards Henry the dog...You wonder if she could save you if you were in a bind\n");
say(tp + "says: Do you have a dog? \n");
return 1;
}
smell(){
write("YES-You still have the ability to smell, now fight!\n");
say (tp + "says: can u sniff your own butt?\n");
return 1;
}
listen(){
write("In the distance, you could swear you hear someone selling\n popcorn and beer.  Sounds like its coming from the north.\n");
say(tp + "begins to drool and rub his tummy\n");
return 1;
}

