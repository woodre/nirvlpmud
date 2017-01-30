inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("ward");
set_alias("cleaver");
set_short("Ward Cleaver");
set_race("cleaver");
set_long(
"Ward Cleaver is the typical father.  He can work 120 hours a week\n"+
"and still find time to play with his boys and romance his wife.\n"+
"He works at a moderate job, but yet still finds the cash to own\n"+
"a nice house in the burbs.  Ward smokes a pipe, plays golf, and \n"+
"never raises his voice.  As a man : He commands respect..\n"+
"HUH, What??? Kill this joker.\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+100);
set_level(6);
call_other(this_object(),"set_heal",0,0);
set_ac(5);
set_wc(10);
set_hp(100);
set_al(0);
set_chance(2);
set_spell_dam(10);
set_spell_mess2("Ward blows smoke in your face.");
set_spell_mess1("Ward puts you over his knee and spanks you.");
set_aggressive(0);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("Remember kids, Don't put till tomorrow-what you can do today. \n");
load_a_chat("Ward says: Damn it! I command respect. \n");
}
}

