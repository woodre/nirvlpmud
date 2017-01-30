inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("beaver");
set_alias("cleaver");
set_short("Beaver Cleaver");
set_race("cleaver");
set_long(
"This is the All Mighty Beaver.  He can do everything that a \n"+
"young lad is supposed to.  He likes bugs, reptiles and girls\n"+
"repulse him.  Being a bright, strappin' young lad; he is filled\n"+
"with questions about growing up.  This week he is curious about\n"+
"puberty, too bad you know nothing about the subject!\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+100);
set_level(6);
call_other(this_object(),"set_heal",0,0);
set_ac(5);
set_wc(10);
set_hp(100);
set_al(0);
set_chance(4);
set_spell_dam(4);
set_spell_mess2("The beaver throws a mudpie in your face.");
set_spell_mess1("Beaver pegs you with a rock.");
set_aggressive(0);
set_a_chat_chance(20);
set_chat_chance(30);
load_chat("Beaver asks: Hey Wally, what's masterbating? \n");
load_a_chat("Beaver crys: Mommy help me. \n");
}
}

