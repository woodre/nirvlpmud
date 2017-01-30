inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("Luther");
set_alias("Lex");
set_short("Lex Luther");
set_race("lex");
set_long(
"Lex Luther the mastermind who has been trying forever and a day to\n"+
"kill Superman, stands in front of you.  He is dressed in a business\n"+
"suit, howver it appears to be a bit wrinkled.  Lex has definitely seen\n"+
"better days.  As you approach, his face turns to a smile.  He begins\n"+
"to speak: Superman is that really you, Thanks for coming. I missed\n"+
"you so!..You think to yourself, this guy is wacked.  He appears to\n"+
"think you are Superman.  Maybe you should just pretend for him and\n"+
"provide ole Lex with one last bit of worth and purpose.\n");
gold = clone_object("obj/money");
gold -> set_money (random(200)+600);
set_level(16);
call_other(this_object(),"set_heal",0,0);
set_ac(13);
set_wc(22);
set_hp(400);
set_al(-100);
set_chance(10);
set_spell_dam(10);
set_spell_mess2("Lex throws a gren rock at you.");
set_spell_mess1("Lex presses a green rock against your forehead.");
set_aggressive(0);
set_a_chat_chance(30);
set_chat_chance(30);
load_chat("I am so happy you are here. \n");
load_a_chat("Ouch! Just like old times. \n");
}
}

