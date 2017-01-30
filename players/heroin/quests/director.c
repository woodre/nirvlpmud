inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("director");
set_alias("director");
set_short("Director of the CIA");
set_race("human");
set_long(
"This is the director of the CIA.  He seems busy, however, he\n"+
"seems strangely interested in your presence....\n"+
"He seems to be waiting for you to say something.\n");
gold = clone_object("obj/money");
gold -> set_money (random(5000)+5000);
set_level(100);
call_other(this_object(),"set_heal",20,20);
set_ac(50);
set_wc(50);
set_hp(99999);
set_al(-1000);
set_chance(20);
set_spell_dam(30);
set_spell_mess2("blah");
set_spell_mess1("blah");
set_aggressive(0);
set_a_chat_chance(40);
set_chat_chance(40);
load_chat("Have you solved your case yet? \n");
load_a_chat("Hey buddy. There is no I in TEAM!?!? \n");
}
}

