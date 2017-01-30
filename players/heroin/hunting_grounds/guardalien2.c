inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("Guard");
set_alias("Guard");
set_short("Alien guard");
set_race("guard");
set_long(
"These aliens are fully sized creatures.  They serve two purposes: \n"+
"first they scout out hosts for the newborns, and second they kill\n"+
"all intruders.  By the way, you qualify as the second.  These aliens\n"+
"have nearly inpenetrable skin and razor sharp claws and teeth.  They\n"+
"also have acid for blood- which they can use almost like a snake uses\n"+
"venom.  They stand at about 8 feet tall and are the quickest of all\n"+
"the aliens.  In fact, these aliens could kill you before you could even wield \n"+
"a weapon. Goodbye.\n");
gold = clone_object("obj/money");
gold -> set_money (random(400)+400);
move_object(clone_object("/players/heroin/hunting_grounds/venom.c"), this_object());
set_level(13);
call_other(this_object(),"set_heal",0,0);
set_ac(8);
set_wc(17);
set_hp(190);
set_al(-10);
set_chance(20);
set_spell_dam(5);
set_spell_mess2("The alien bites a hole through your chest.");
set_spell_mess1("The alien bites a hole through your chest.");
set_aggressive(1);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("SCREEEEEEEEEEEEEEECHHHHHHHH... \n");
load_a_chat("HHHHHHHHIIIIIIIIIISSSSSSSSSSSS.. \n");
}
}

