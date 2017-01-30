inherit "players/illarion/poke/mon/pokemon";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("clefairy");
  set_alt_name("balloon");
  set_race("pokemon");
  set_short("A balloon-like creature known as a Clefairy");
  set_long(
"This cheerful but slightly shy creature looks like nothing so much as a\n"+
"pink balloon with soft fur, stubby legs, and a smiling face.  Given the\n"+
"way it bounces around by flapping its small, almost vestigal wings, it must\n"+
"be about as light as a baloon, too.\n");
  create(19);
  set_chat_chance(10);
  set_spchance(25);
  add_spell("bonk",pwc*3/2,
      "The Clefairy bounces onto your head, and for some reason it really hurts!\n",
      "The Clefairy bounces onto #TN#'s head.\n","physical");
  load_chat("The Clefairy bounces around, its high-pitched voice chiming, \"Clefairy\"\neach time it lands.\n");
  set_whimpy(1);
}
