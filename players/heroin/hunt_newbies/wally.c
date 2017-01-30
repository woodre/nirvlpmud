inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("wally");
set_alias("cleaver");
set_short("Wally Cleaver");
set_race("cleaver");
set_long(
"This is the oldest Cleaver child: Wally. What can really be said\n"+
"about Wally.  He is a good son, a decent athlete, a lady swooner,\n"+
"and a swell brother to the Beaver.  Kill him anyways.\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+100);
set_level(6);
call_other(this_object(),"set_heal",0,0);
set_ac(5);
set_wc(10);
set_hp(100);
set_al(0);
set_chance(5);
set_spell_dam(5);
set_spell_mess2("Wally wrestles you to the ground.");
set_spell_mess1("Wally punches you square in the nose.");
set_aggressive(0);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("Gee Beav. I dont know why dogs rub on your leg. \n");
load_a_chat("Ouch, not now, I am helping the Beaver. \n");
}
}

