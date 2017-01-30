inherit "obj/monster";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("gordon");
set_alias("gordo");
set_short("Comm. Gordon");
set_race("gordon");
set_long(
"This is Comm. Gordon.  He is responsible for the law in Gotham. \n"+
"However, as long as his best-buddy Batman is around, he can just\n"+
"sit around and replace the batteries in his batlight.  With so\n"+
"much time on his hands, Gordon has been putting down ALOT of beer,\n"+
"so now he has a pretty fair size belly.  This could make him one\n"+
"tough cookie. Also Gordon has shown a special fondness for the \n"+
"masked man, so I would watch my step.\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+900);
set_level(14);
call_other(this_object(),"set_heal",0,0);
set_ac(11);
set_wc(17);
set_hp(220);
set_al(0);
set_chance(40);
set_spell_dam(20);
set_spell_mess2("Gordon puts his cigar out on your forehead.");
set_spell_mess1("Gordon throws a police medal at you..OUCH!");
set_aggressive(0);
set_a_chat_chance(25);
set_chat_chance(25);
load_chat("Don't call me the Commish! \n");
load_a_chat("Pension or not..you are going to die! \n");
}
}

