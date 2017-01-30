inherit "players/illarion/poke/mon/pokemon";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("vulpix");
  set_race("pokemon");
  set_alias("fox");
  set_short("A fox with five tails known as a Vulpix");
  set_long(
"Shiny red fur and soft, beautiful dark eyes would make this fox-like\n"+
"Pokemon soften almost anyone's heart, but its five long, luxuriant tails\n"+
"make it sought after for its beauty almost everywhere.  It seems gentle\n"+
"and shy, but somehow gives the impression its patience is not to be tried.\n");
  create(19);
  set_al(100+random(100));
  set_chat_chance(10);
  load_chat(
"The Vulpix rustles its five long tails, and in a high, clear voice, it\n"+
"says, \"Vulpix.\"\n");
  load_chat("The Vulpix carefully licks at one of its tails.\n");
  set_a_chat_chance(10);
  load_a_chat("The Vulpix seems angry...  is that smoke you smell?\n");
  set_spchance(15);
  add_spell("flamethrower",pwc*3/2,
"The angry Vuplix opens its mouth wide, and a gout of searing flame pours"+
"out and directly into you!",
"A blaze of searing flame pours out of the Vulpix's mouth at its enemy.",
"other|fire");
}
