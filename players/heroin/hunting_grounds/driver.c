inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("driver");
set_alias("weeves");
set_short("The Limo driver");
set_race("driver");
set_long(
"You're looking at one pissed off limo driver.  He gets tipped for\n"+
"shit, he has to drive all day, and he has to wear a bowtie.  How\n"+
"would you act to strangers? Probably the same way he's reacting to \n"+
"you being in his car.  Well at least its a free ride, that is, if\n"+
"you survive the trip.\n");
gold = clone_object("obj/money");
gold -> set_money (random(300)+200);
move_object(clone_object("/players/heroin/hunting_grounds/keys.c"), this_object());
set_level(10);
call_other(this_object(),"set_heal",0,0);
set_ac(8);
set_wc(14);
set_hp(150);
set_al(0);
set_chance(5);
set_spell_dam(30);
set_spell_mess2("Weeves shoves the seat back on your feet.");
set_spell_mess1("Weeves pokes you in the eye with his keys.");
set_aggressive(1);
set_a_chat_chance(30);
set_chat_chance(30);
load_chat("Where to? How's about hell, freeloader. \n");
load_a_chat("Now, I definitely wont change the radio station. \n");
}
}

