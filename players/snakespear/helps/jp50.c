/*  Jurassic Park  */

#include "defs.h"
inherit "room/room";
object player;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("jurassic ranger")) {
  move_object(clone_object("players/eurale/Park/NPC/ranger"),TO); }

short_desc = "Jurassic Park";
long_desc =
	"  You have entered a land covered with a dense growth of trees \n"+
	"that blocks out most of the sun.  The vegetation is very tall \n"+
	"and consists of huge ferns and very thick vines which fall from \n"+
	"high up in the trees.  The air is hot and humid and you can hear \n"+
	"the sound of huge animals all around you.\n"+
	"There is a painted arrow stuck in the ground beside the path.\n";

items = ({
	"arrow","An 'Exit' arrow pointing south",
	"trees","The trees are very tall with thick growth at the top. \n"+
		"They provide protection and shelter",
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
		"fronds that reproduce by spores instead of seeds",
	"vines","Large, thick, rope-like stems of plants that climb the \n"+
		"trees and run along the ground",
});

dest_dir = ({
	"players/eurale/Park/jp40.c","north",
	"players/eurale/Park/jp60.c","south",
	"players/eurale/Park/jp49.c","west",
});

}

init() {
  ::init();
  add_action("problem","problem");
  add_action("completed","completed");
}

problem() {
if(!present("ranger")) {
  write("I don't see any ranger to help you, sorry!\n"); return 1; }
write("\nThe ranger looks at you and smiles....\n\n");
player = this_player();
call_out("rex",7);
return 1; }

rex() {
tell_object(player,
  "He says, 'When we started this project we had ideas about the way\n"+
  "things would turn out.  Boy, were we wrong!\n\n");
say("The ranger mumbles something....\n\n");
call_out("rex1",8);
return 1; }

rex1() {
say("The ranger grins but it is a forced grin at best...\n\n");
call_out("rex2",6);
return 1; }

rex2() {
tell_object(player,
  "We thought the tyrannosaurus would be a plodding, slow-thinking\n"+
  "dinosaur like it has been portrayed in all the movies.  We were\n"+
  "very, very wrong....\n\n");
call_out("rex3",9);
return 1; }

rex3() {
say("The ranger begins to sweat and look uncomfortable....\n\n");
call_out("rex4",6);
return 1; }

rex4() {
tell_object(player,
  "They actually turned out to be speedy and intelligent predators.\n"+
  "And because of that, we need to rid the park of them.\n\n");
call_out("rex5",5);
return 1; }

rex5() {
tell_object(player,
  "We know there are AT LEAST 3 tyrannosaurs roaming the park.  Your\n"+
  "task is to personally kill them all.  When you have done so, just\n"+
  "return to me and type 'completed'.  Good luck, my friend!'\n\n");
call_out("rex6",10);
return 1; }

rex6() {
say("The ranger takes a handkerchief out of his back pocket and wipes\n"+
    "the sweat off his forehead and then goes back to his work.\n\n");
return 1; }

completed() {
object ob1,ob2,ob3,ob4,ob5;
if( present("rexy1",this_player()) && present("rexy2",this_player())
  && present("rexy3",this_player()) && present("rexy4",this_player())
  && present("rexy5",this_player()) ) {

ob1 = present("rexy1",this_player());
ob2 = present("rexy2",this_player());
ob3 = present("rexy3",this_player());
ob4 = present("rexy4",this_player());
ob5 = present("rexy5",this_player());

TP->set_quest("t_rexs");
write_file("/players/eurale/Park/LOG/rexquest",
ctime(time())+"     "+TP->query_real_name()+" has completed the "+
	"Rex Quest\n");

write("The ranger looks up, somewhat surprised to see you again.\n"+
	"He breaks into a huge, toothy smile and stands.  With his\n"+
	"strong arms, he encircles you and gives you a GREAT BIG hug!\n\n");
say("The ranger stands and hugs "+capitalize(TPRN)+".\n\n");

destruct(ob1);
destruct(ob2);
destruct(ob3);
destruct(ob4);
destruct(ob5);

player = this_player();
call_out("com",8);
  return 1; }

else {
  write("The ranger turns his head to see who you are....\n\n");
  say("The ranger looks at "+capitalize(TPRN)+" and smiles...\n\n");
  player = this_player();
  call_out("noncom",5);
  return 1; }

}

com() {
tell_object(player,
  "The ranger chuckles and says, 'Man, are you a sight for sore eyes!\n"+
  "When you left I surely thought that would be the LAST time anyone\n"+
  "would ever see you again.  But I can see you have had a good day\n"+
  "of hunting'...\n\n");
call_out("com1",10);
return 1; }

com1() {
tell_object(player,
  "The ranger pats you on the back and continues...\n\n"+
  "'I'm sure everyone will appreciate the service you've provided and\n"+
  "because of your skill and bravery I have a little something for \n"+
  "you myself.'\n\n");
call_out("com2",10);
return 1; }

com2() {
tell_object(player,
  "He leans in real close and whispers... 'Because I'm a personal\n"+
  "friend of Eurale's, I'm going to tell him you killed all his\n"+
  "pet dinosaurs.  He should be very happy.... hehe!!   Have a nice\n"+
  "day now, ya hear!'  [Quest completed:  10 qps]\n\n");
return 1; }

noncom() {
tell_object(player,
  "The ranger wipes the sweat off his face and says, 'I never thought\n"+
  "I'd see the likes of you again.  You must have found some of those\n"+
  "nasty tyrannosaurs we talked about and killed them.  Unfortunately,\n"+
  "you either didn't find them all or else you didn't kill them all\n"+
  "yourself like I told you earlier.  In either case, I can't help you\n"+
  "much.  Better luck next time....sorry.'\n\n");
call_out("noncom1",10);
return 1; }

noncom1() {
tell_object(player,
  "The ranger turns and goes back to what he was doing but you could\n"+
  "swear you heard him chuckle as he did...\n\n");
return 1; }
