inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("contestant");
set_alias("contestant");
set_short("Price is Right contestant");
set_race("contestant");
set_long(
"You look at the contestant, and the  contestant turn around and\n"+
"begins talking to you:\n"+
"Hello I am a generic contestant, I live for people like Bob Barker\n"+
"to make fun of me.  In my spare time, I ironon slogans onto shirts\n"+
"like : Nirvana Loves Bob -or- I Spayed For Bob.  Would ya like me\n"+
"to make you a shirt sometime..Oh excuse me here comes the next bid.\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+100);
set_level(6);
call_other(this_object(),"set_heal",0,0);
set_ac(5);
set_wc(10);
set_hp(100);
set_al(0);
set_chance(10);
set_spell_dam(5);
set_spell_mess2("Ouch, the contestant gave you a bearhug");
set_spell_mess1("The contestant bids $1 higher than you.");
set_aggressive(0);
set_a_chat_chance(10);
set_chat_chance(10);
load_chat("I bid ONE DOLLAR, Bob...One dollar. \n");
load_a_chat("Doesn't matter if you kill me, I know Bob loves me. \n");
}
}

