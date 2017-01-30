inherit "obj/monster";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(arg) return;
  ::reset(arg);

  set_name("pikachu");
  set_race("pokemon");
  set_alias("mouse");
  set_short("A cute yellow mouse-like creature called Pikachu");
  set_long(
"Although this creature looks like a mouse, it is actually about the size\n"+
"of a small dog, and almost unbearably cute.  When still, it stands up\n"+
"easily on its hind legs, and looks around with an uncanny intelligence on\n"+
"it's red-cheeked and almost human face.  Seeing you looking at it, it\n"+
"looks up, and actually speaks, \"Pika-chu?\"\n");
  GUIDE->make_monster(20,TO,20);
/*  
  set_level(20);
  set_wc(GUIDE->wc_guide(level));
  set_ac(GUIDE->ac_guide(level));
  */
  set_armor_params("other|electric",0,50,"none");
  set_armor_params("other|earth",0,-50,"none");
  /*
  set_hp(GUIDE->hp_guide(level));
  add_money(GUIDE->gold_guide(level));
  */
  set_al(300);
  add_spell("thundershock",
"The angry Pikachu's cheeks suddenly start to spark with electricity.  After "+
"a moment, it screams \"PIKACHU\", and a bolt of electricity leaps "+
"from his mouth and into you.",
"The Pikachu's anger suddenly erupts into a bolt of electicity, discharged "+
"straight at its #TN#",30,pwc*3/2,"other|electric");
  set_chat_chance(15);
  load_chat("The Pikachu looks up at you and asks, \"Pika pika?\"\n");
  load_chat("The Pikachu does something, and says, \"Chu,\" in a satisfied tone.\n");
  set_a_chat_chance(15);
  load_a_chat("In an angry tone, the Pikachu says, \"Pika pika!\"\n");
  load_a_chat("Little sparks of electricity appear around the Pikachu's cheeks.\n");
}
