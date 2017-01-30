inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("teen");
set_alias("teen");
set_short("A rockin' teen");
set_race("teen");
set_long(
"Looking at this girl makes you wish you were 18 again.  She\n"+
"is young, energetic, and yes, sexy.  She was sitting on someone's shoulders\n"+
"but now, she is standing in front of you.  She gives you the once\n"+
"over and you return the favor.  You notice that she is wearing \n"+
"short cut-offs and nothing else.  She was wearing a bikini top, but\n"+
"she thought it was too restrictive.  She notices you looking at her\n"+
"and she responds by kicking you in the shin.  Watch out for that \n"+
"bikini it's elastic.\n");
gold = clone_object("obj/money");
gold -> set_money (random(400)+100);
move_object(clone_object("/players/heroin/hunting_grounds/bikini.c"), this_object());
set_level(11);
call_other(this_object(),"set_heal",0,0);
set_ac(9);
set_wc(15);
set_hp(165);
set_al(0);
set_chance(10);
set_spell_dam(5);
set_spell_mess2("She snaps you between the eyes.");
set_spell_mess1("You are kicked square in the crotch");
set_aggressive(1);
set_a_chat_chance(15);
set_chat_chance(15);
load_chat("Can I borrow your lighter, mine is out of fluid? \n");
load_a_chat("The girl screams: Perverted poseur!!!! \n");
}
}

