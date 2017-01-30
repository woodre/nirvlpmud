inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("babes");
set_alias("girls");
set_short("Bob's babes");
set_race("babes");
set_long(
"This is one of Bob Parker beauties.  On the Price is Right, they \n"+
"help Bob by modeling prizes.  Noone is really sure why they are\n"+
"called Bob's Beauties since they are all like 120 years old..\n"+
"However, they still are attractive for their ages.  Since you are\n"+
"the jealous type, you should kill them off.  Afterall, if you can't \n"+
"have them--then noone will!\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+100);
set_level(6);
call_other(this_object(),"set_heal",0,0);
set_ac(5);
set_wc(10);
set_hp(100);
set_al(-10);
set_chance(10);
set_spell_dam(5);
set_spell_mess2("Don't pick on Bob, you bastard.");
set_spell_mess1("You are scratched by a babe..how does that feel?");
set_aggressive(0);
set_a_chat_chance(10);
set_chat_chance(10);
load_chat("Do you still find me attractive?\n");
load_a_chat("Do you feel tough for beating up a girl? \n");
}
}

