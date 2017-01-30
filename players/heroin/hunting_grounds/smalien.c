inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("hatchling");
set_alias("alien");
set_short("A alien hatchling");
set_race("alien");
set_long(
"This is an alien hatchling.  The hatchlings only purpose is to \n"+
"plant the seeds in hosts.  He does this by attaching to the face\n"+
"and implanting a organism down the throut.  These aliens act\n"+
"instinctually, so watch out.\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+10);
set_level(11);
call_other(this_object(),"set_heal",0,0);
set_ac(9);
set_wc(15);
set_hp(165);
set_al(-100);
set_chance(20);
set_spell_dam(10);
set_spell_mess2("The hatchling attaches just below your face!");
set_spell_mess1("The hatchling catches you with its tail.");
set_aggressive(1);
set_a_chat_chance(10);
set_chat_chance(10);
load_chat("SHHLURRRPPPP \n");
load_a_chat("The Alien Screams and flys at your face \n");
}
}

