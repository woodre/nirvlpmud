inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("Joker");
set_alias("smiley");
set_short("The Joker");
set_race("joker");
set_long(
"You are now in the presence of the Batman's greatest foe.  He\n"+
"has dedicated his entire life to hunting Batman.  The Joker is\n"+
"one of Angst's favorite vile creatures.  There are variety of \n"+
"reasons for this: first, Joker is a hunter, that when he catches\n"+
"his prey, just starts the game over.  Second, The joker is one hell \n"+
"of a nice dresser.\n");
gold = clone_object("obj/money");
gold -> set_money (random(1000)+3000);
move_object(clone_object("/players/heroin/hunting_grounds/killjk.c"), this_object());
set_level(20);
call_other(this_object(),"set_heal",0,0);
set_ac(15);
set_wc(20);
set_hp(500);
set_al(-100);
set_chance(40);
set_spell_dam(15);
set_spell_mess2("Like a dumbass, you smell the Joker's flower.");
set_spell_mess1("The joker tells you a KILLER joke.");
set_aggressive(0);
set_a_chat_chance(25);
set_chat_chance(25);
load_chat("Why did the Chicken cross the road? \n");
load_a_chat("HEHHEHEHEHE The chicken crossed the road because he was dumb. HEHAHE \n");
}
}

