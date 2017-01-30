inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("Bouncer");
set_alias("toughguy");
set_short("Bouncer, a toughguy");
set_race("toughguy");
set_long(
"	Before you stands one of the scariest sights to the\n"+
"rock-stricken teen.  He has a crewcut, extremely large limbs, and\n"+
"more stretch-marks than brain cells.  He hails from everybody's\n"+
"college town, and he is more than any local could hope to become.\n"+
"He once played for the 'team' ,that is 10 years ago.  He lost his\n"+
"eligability, and therefore couldn't finish school.  He is always more\n"+
"than happy to tell you about the fly-honeys he bagged.  He is also\n"+
"never ashamed to beat up an occasional smart-ass kid.  If you can't \n"+
"guess, this man is the....BOUNCER.\n");
gold = clone_object("obj/money");
gold -> set_money (random(300)+200);
set_level(9);
call_other(this_object(),"set_heal",0,0);
set_ac(7);
set_wc(13);
set_hp(135);
set_al(-10);
set_chance(10);
set_spell_dam(5);
set_spell_mess2("I'll pop your head like a zit!");
set_spell_mess1("Saves you from yourself by kicking you in the head!");
set_aggressive(1);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("Man O Man..was she fly..Hey punk: what are you snickering about? \n");
load_a_chat("The bouncer goes for the extra point, and then spikes you! \n");
}
}

