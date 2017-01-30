inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("urchen");
set_alias("urchen");
set_short("kid");
    set_race("kid");
    set_long(
"    You are staring at a child of the street: a street urchen.\n"+
"He-she (cant tell thru the filth) survives as a scavenger.\n"+
"The urchen is not really bad or good by nature, however the\n"+
"hardness of the streets have helped to mold this small child\n"+
"into something not quite human. Nonetheless, you at the sight\n"+
"of the mangled heap of flesh in front of yo, feel a deep\n"+
"disgust for their actions.  They now possess the young lady's\n"+
"gold.  What should you do?  Are they a product of their \n"+
"enviroment-or inherently bad?  Even so, is this a justifiable\n"+
"explanation for their actions?  As you struggle with your moral\n"+
"dilema, the urchens finish looting the corpse.  As they turn\n"+
"towards you..they appear shocked at your presence.  Their\n"+
"tiny faces turn to innocent grins and for the first time you\n"+
"see a glint of youth left in their eyes.  They giggle and begin\n"+
"to play a game of kick the can.  What should you do???\n"+
"Angst's voice emerges in your head..HA What do you do morally\n"+
"superior human..HA HA HA HA.\n");
gold = clone_object("obj/money");
gold->set_money(random(100)+500);
move_object(gold, this_object());
move_object(clone_object ("players/heroin/hunting_grounds/can.c"), this_object());
   set_level(15);
   set_ac(10);
   set_wc(20);
   set_hp(200);
   set_al(-300);
set_chance(20);
set_spell_dam(30);
set_spell_mess1("He sure can play kick-the can..A can hits you in th face.");
set_spell_mess2("The street urchen grips you-please kind sir..damn those nails ripped you open");
  set_aggressive(0);
set_chat_chance(10);
    set_a_chat_chance(10);
load_chat("Urchen says: Can you spare a penny for some food?\n");
load_chat("Urchen begins to play kick the can\n");
load_chat("Are you one of us..you are welcome to bunk in our gutter if ya like\n");
load_a_chat("Urchen begins sobbing--Kill a kid would ya?\n");
load_a_chat("Look guy-I haven't even reached puberty yet.\n");
}
}
