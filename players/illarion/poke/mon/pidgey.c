inherit "players/illarion/poke/mon/pokemon";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("pidgey");
  set_alt_name("bird");
  set_race("pokemon");
  set_short("A small grey bird called Pidgey");
  set_long(
"Small grey wing and back feathers and a fluffy breast are the main features\n"+
"of this small, docile-seeming bird.  It hops around, pecking at the ground\n"+
"for food, apparently not minding your presence at all.\n");
  create(19);  /*sets level,wc,ac,hp,coins*/
  set_al(100-random(200));
  set_spchance(15);
  add_spell("gust",pwc*3/2,"The Pidgey flaps its wings with great ferocity, "+
    "actually stirring up a minature whirlwind that sails into you.",
    "The Pidgey's flapping wings stir up a small whirlwind that flies "+
    "into its enemy.","other|wind");
}
