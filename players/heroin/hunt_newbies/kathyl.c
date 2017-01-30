inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("kathy");
set_alias("lee");
set_short("Kathy Lee");
set_race("lee");
set_long(
"Kathy Lee Gifford, one of the most annoying women in television.\n"+
"As you can guess she is doing exactly what she's always doing- telling\n"+
"annoying stories about why her kids and husband are HomoSapian \n"+
"Superior.  You would examine her closer, but frankly, you cant stand\n"+
"the sight of her.  Just kill her and help us all out.\n");
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
set_spell_mess2("Kathy Lee opens her mouth and you fall to the ground in pain.");
set_spell_mess1("Kathy Lee tells a story and takes you within an inch of your life");
set_aggressive(0);
set_a_chat_chance(25);
set_chat_chance(25);
load_chat("Kathy Lee sings: If they could see me now.... \n");
load_a_chat("I'm telling Frank...Oh Frank.. \n");
}
}

