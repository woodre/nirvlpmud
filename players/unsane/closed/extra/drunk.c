inherit "obj/monster";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
set_name("patron");
set_alias("drunk");
set_short("A Drunken Patron");
    set_race("player");
    set_long(
"  This man is a player of games.  The game he is playing now is called \n"+
"chuck-a-luck or some such stuff.  Apparently you toss some dice and sometimes\n"+
"you can get free drinks.  You wonder how hard it can be, specially\n"+
"since this guy is so drunk.  If you need the rules to the game just type\n"+
"<crules>, or if you would like to play type <cplay>.\n");
gold = clone_object("obj/money");
gold -> set_money (random (100) + 4400);
move_object(gold, this_object());
   set_level(20);
   set_ac(17);
   set_wc(29);
   set_hp(600);
   set_al(-300);
set_chance(20);
set_spell_dam(30);
set_spell_mess2("The Drunken Patron smashes you with a beer glass.\n");
set_spell_mess1("The Patron smashes his foe and laughs.\n");
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Patron says: Hey bub, wanna play a game for beer?\n");
load_chat("Patron says: Boy, these dancers sure can go can't they.\n");
load_chat("Patron says: C'mon, odds are good for a free beer.\n");
load_chat("Patron begins singing out of tune.\n");
load_chat("Patron says: Chuck-a-Luck everyone, step right up!\n");
load_a_chat("Patron says: Sheesh man, it's only a game.\n");
load_a_chat("Patron looks about stupidly like a hurt puppy.\n");
load_a_chat("Patron says: I'm gonna pop you now.\n");
}
}
init(){
::init();
add_action("rules","crules");
add_action("play","cplay");
}
rules(){
write("Patron says:  This game is a doozy of a game based on an old english pub\n"+
"game.  You see, you roll three dice and if you get no sixes, then you must\n"+
"buy me a beer.  If you get one six then I buy you a beer.  If you get two sixes\n"+
"then I buy you two beers, and I buy you three beers if you get 3 sixes.\n"+
"So what do ya say?  Sounds fair don't it.  Just type <cplay>.\n");
return 1;}
play(){
int one,two,three;
string fo,fu,fe;
if (this_player()->query_money() < 500){write("Patron says: You don't have the money kid... \n");
return 1;}
one=random(6);
two=random(6);
three=random(6);
one++;
two++;
three++;
write("You rolled a "+one+" and a "+two+" and a "+three+".\n");
if (one != 6 && two != 6 && three != 6){
write("Patron says:  Allright, free beer!!!\n"+
"You pay 500 coins for a beer for your pal.\n");
this_player()->add_money(-500);
say(this_player()->query_name()+" buys a beer for the drunk.\n");
return 1;}
if (one==6 && two ==6 && three == 6){
write("Patron says: You're cheating!!  Three beers!!\n"+
"Patron buys you three beers.\n");
move_object(clone_object("/players/unsane/closed/extra/beer.c"),this_player());
move_object(clone_object("/players/unsane/closed/extra/beer.c"),this_player());
move_object(clone_object("/players/unsane/closed/extra/beer.c"),this_player());
say(this_player()->query_name()+" wins 3 beers!!\n");
return 1;}
if ((one==6&&two!=6&&three!=6)||(one!=6&&two==6&&three!=6)||(one!=6&&two!=6&&three==6)){
write("Patron says: You win one beer this time.\n"+
"Patron buys you a beer.\n");
move_object(clone_object("/players/unsane/closed/extra/beer.c"),this_player());
say(this_player()->query_name()+" wins a beer!\n");
return 1;}
write("Patron says: You win two beers, you lout...\n"+
"Patron buys you two beers.\n");
move_object(clone_object("/players/unsane/closed/extra/beer.c"),this_player());
move_object(clone_object("/players/unsane/closed/extra/beer.c"),this_player());
say(this_player()->query_name()+" wins two beers!!\n");
return 1;}
