inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("regis");
set_alias("regis");
set_short("Regis, extrordinary man.");
set_race("regis");
set_long(
"Regis is Kathy Lee's better half on LIVE.  Yes, he's also\n"+
"annoying, but at least he's not Kathy Lee.  Suddenly an image\n"+
"comes to mind, What if Regis and Kathy Lee were to have an affair\n"+
"and as a result of the affair: REPRODUCED....\n"+
"AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH\n"+
"You think to yourself: God Help Us.\n");
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
set_spell_mess2("Regis does his exercises on you.");
set_spell_mess1("Regis does the forbidden dance with you.");
set_aggressive(0);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("Regis asks: Can I help you kill Kathy Lee? \n");
load_a_chat("Regis yells: Help me... \n");
}
}

