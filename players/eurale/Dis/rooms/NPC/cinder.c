
inherit "obj/monster";
object player;

reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("cinderella");
set_race("human");
set_short("Cinderella");
set_alias("stepdaughter");
set_long(
	"  Cinderella is a petite thing when compared to her stepsisters.\n"+
	"Her light brown hair and blue eyes compliment her charming \n"+
	"smile.  Her hands are rough from all the work she's asked to do \n"+
	"around the cottage.\n");
set_hp(400);
set_level(16);
set_al(500);
set_aggressive(0);

set_ac(13);
set_wc(22);

set_chat_chance(10);
  load_chat("Cinderella smiles sweetly...\n");
  load_chat("Cinderella asks: What can I do for you? \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+900);
move_object(gold,this_object());
}

init() {
  ::init();
  add_action("inquire","inquire");
  add_action("speak1","speak1");
  add_action("speak2","speak2");
  add_action("speak3","speak3");
  add_action("speak4","speak4");
  add_action("speak5","speak5");
}

inquire(str) {
string s1,s2;
  if(!str) {
  write("You inquire.  Perhaps you should inquire of someone?\n");
  return 1; }

sscanf(str,"%s %s",s1,s2);
  if(s1 != "of") {
  write("The proper format is <inquire of whomever>.\n"); return 1; }
  if(!s2) { write("Of whom would you inquire?\n"); return 1; }
  if(s1 == "of" && s2 != "cinderella") {
  write("That person is not here.\n"); return 1; }
  if(!present("cinderella")) {
   write("Cinderella isn't here at the present time.  You'll have to\n"+
	 "come back later when she's home.\n"); return 1; }

  say("\nCinderella thinks a moment and then begins...\n\n");

player = this_player();
call_out("speak1",6);
return 1;
}


speak1() {
  tell_object(player,
	"I have been told of a Wizard that used to inhabit the realm of\n"+
      "Phantasm a long, long time ago.  He was banished from the realm\n"+
      "when the wicked Queen came to power...\n\n");
call_out("speak2",12);
return 1; }

speak2() {
  tell_object(player,
	"In order to insure that his treasure would not be seized by the\n"+
      "Queen or her minions, he devised a puzzle that would prohibit\n"+
      "access to everyone except those able to solve the puzzle.\n\n");
call_out("speak3",12);
return 1; }

speak3() {
  tell_object(player,
	"The Wizard then traveled the realm hiding 4 pieces of the puzzle.\n"+
      "It is said that if one can search out all the pieces, they can\n"+
      "solve the puzzle, set the Wizard free and retrieve the riches.\n\n");
call_out("speak4",12);
return 1; }

speak4() {
  tell_object(player,
	"I have heard that many have tried but none have been successful\n"+
      "at setting the Wizard free.  If you have chosen to undertake\n"+
      "this task, I wish you luck and God's speed....\n\n");
call_out("speak5",12);
return 1; }

speak5() {
  tell_object(player,
	"And with that, Cinderella falls quiet and continues her chores...\n\n");

return 1;
}
