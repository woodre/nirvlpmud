inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("eddie");
set_alias("haskle");
set_short("Eddie Haskle");
set_race("eddie");
set_long(
"Eddie Haskle is the notorious bad kid on Leave it to Beaver.\n"+
"Eddie is always trying to get Wally and Beav into hot water, and\n"+
"then when Mr and Mrs Cleaver come around, Eddie acts inncoent.\n"+
"Come to think of it, Eddie isn't all that bad.  If he wasn't a\n"+
"pervert, you could probably let him live.\n");
gold = clone_object("obj/money");
gold -> set_money (random(200)+220);
set_level(7);
call_other(this_object(),"set_heal",0,0);
set_ac(6);
set_wc(11);
set_hp(110);
set_al(0);
set_chance(15);
set_spell_dam(10);
set_spell_mess2("Eddie gives you a snuggy.");
set_spell_mess1("Eddie steals your milk money.");
set_aggressive(0);
set_a_chat_chance(15);
set_chat_chance(15);
load_chat("Don't you think Mrs. C is keen? \n");
load_a_chat("All right already, Don't pull a Wally. \n");
}
}

