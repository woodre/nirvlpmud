inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("bob");
set_alias("barker");
set_short("Bob Barker");
set_race("bob");
set_long(
"Bob Barker is the host of the gameshow; The Price is Right.  \n"+
"Bob stands at about 6 ft tall and 160 lbs...But dont let his \n"+
"size fool you; he is 100% lovemachine.  Bob is ok for two reasons:\n"+
"first, Bob doesnt dye his hair evn though he's kinda old, and finally,\n"+
"Bob is the national spokesman for getting your pets fixed..\n"+
"Oh well, It is shame but you know the rules- everyone dies.\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+100);
set_level(6);
call_other(this_object(),"set_heal",0,0);
set_ac(5);
set_wc(10);
set_hp(120);
set_al(10);
set_chance(10);
set_spell_dam(10);
set_spell_mess2("I'll strike you for every cat testicle in America.");
set_spell_mess1("Bob helps control the population: You have been fixed.");
set_aggressive(0);
set_a_chat_chance(10);
set_chat_chance(10);
load_chat("Help control the pet population, get yourself fixed. \n");
load_a_chat("Ok Ok Ok Ill let you kiss me on the cheek. \n");
}
}

