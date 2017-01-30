inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("crawler");
set_alias("biter");
set_short("alien crawler");
set_race("crawler");
set_long(
"This is a young alien.  He is not yet developed enough to walk\n"+
"he can only crawl.  Howver, the alien is faster on all fours then\n"+
"on two.  This alien being young also means something else; it is\n"+
"hungry for human!\n");
gold = clone_object("obj/money");
gold -> set_money (random(500)+500);
set_level(17);
call_other(this_object(),"set_heal",0,0);
set_ac(14);
set_wc(24);
set_hp(425);
set_al(-100);
set_chance(25);
set_spell_dam(10);
set_spell_mess2("The Alien bites you deep in the shoulder");
set_spell_mess1("The alien claws at your face");
set_aggressive(1);
set_a_chat_chance(5);
set_chat_chance(5);
load_chat("The alien hisses at you \n");
load_a_chat("The alien is on you in no time. \n");
}
}

