inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("june");
set_alias("cleaver");
set_short("June Cleaver");
set_race("june");
set_long(
"You are looking at woman that God itself must have created. \n"+
"This is June Cleaver; wife to Ward and mother to the Beaver and\n"+
"Wally.  She is known far and wide for her cookies.  It looks as\n"+
"though your timing was perfect.\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+50);
move_object(clone_object("/players/heroin/hunt_newbies/cookies.c"), this_object());
set_level(7);
call_other(this_object(),"set_heal",0,0);
set_ac(6);
set_wc(11);
set_hp(110);
set_al(0);
set_chance(5);
set_spell_dam(5);
set_spell_mess2("Mrs. C hits you in the face with a cookie sheet.");
set_spell_mess1("Mrs. C throws crisco in your eyes.");
set_aggressive(0);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("If you are going outside, don't forget your sweater. \n");
load_a_chat("Ouch, You must have eaten all of your oatmeal this morning. \n");
}
}

