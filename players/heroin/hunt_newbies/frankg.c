inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("frank");
set_alias("gifford");
set_short("Frank Gifford");
set_race("frank");
set_long(
"Frank is an ex-star football player and now is an announcer on\n"+
"Monday night football.  Angst personally likes Frank alright as\n"+
"as a football star, but Frank's crime is his marriage to Kathy Lee.\n"+
"For reproducing with Kathy, the only justifiable punishment is DEATH.\n"+
"Do it for your country, do it for your childrens future...do it for\n"+
"whatever reason you can find, but kill Frank before they reproduce\n"+
"anymore!!!!!\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+200);
set_level(6);
call_other(this_object(),"set_heal",0,0);
set_ac(5);
set_wc(10);
set_hp(100);
set_al(0);
set_chance(10);
set_spell_dam(7);
set_spell_mess2("TOUCHDOWN!!!!!!");
set_spell_mess1("You are spiked by Frank.");
set_aggressive(0);
set_a_chat_chance(15);
set_chat_chance(15);
load_chat("Hi my name is Frank, and my wife is annoying. \n");
load_a_chat("Now you die, just look at my pecks! \n");
}
}

