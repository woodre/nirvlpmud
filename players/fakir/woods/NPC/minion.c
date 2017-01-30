inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
add_money(100);
set_name("minion");
set_race("fairy");
set_short("A nasty Minion");
set_long(
  "Oddly dirty for one born of the fairy folk, this creature appears to\n"+
  "have just come from a hole in the ground.  His hair is full of dirt\n"+
  "and the few articles of clothing he wears are tattered and torn.\n");

set_level(3);
set_hp(45);
set_al(-150);
set_wc(6);
set_ac(4);
set_aggressive(0);
set_chat_chance(10);
  load_chat("Minion says: Ummm...you look nice and plump for a warrior.\n");
  load_chat("Minion says: I will have you for my dinner, humankind.\n");
  load_chat("Minion says: You have broken up our game.\n");
  load_chat("Minion says: Now you must die like all the rest.\n");
  load_chat("Minion says: You will be lost in these woods...no way out humans!\n");
  load_chat("Minion says: Humans make good stew, if you can get them in the pot!\n");
set_a_chat_chance(15);
  load_a_chat("Eeeekkkk!  You nasty humans always stabbing us with pointy things!\n");
  load_a_chat("Yikes, its got a sharp thingy. We must run very fast now.\n");

}

