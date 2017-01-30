inherit "players/illarion/poke/mon/pokemon";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_race("pokemon");
  set_name("koffing");
  set_alias("balloon");
  set_short("A foul-smelling balloon appropriately named Koffing");
  set_long(
"Shaped like a sphere with vents all over its body, Koffing is more of a\n"+
"floating pollutant than a creature.  It moves over the ground by spewing\n"+
"a foul-smelling gas to propel itself.  On its forehead is a skull-and\n"+
"crossbones symbol.\n");
  create(19);
  set_al(-100-random(100));
  set_chat_chance(13);
  load_chat("A particularly vile cloud of smoke drifts your way, making you\n"+
            "choke and wheeze.\n");
  load_chat("The Koffing jets around on plumes of its vile smoke, saying\n"+
            "\"Koff, koff, koff, koff\".\n");
  set_a_chat_chance(15);
  load_a_chat("Knocking the Koffing around is making it release even more\n"+
              "of its vile smoke.  Maybe this wasn't such a great idea.\n");
  set_spchance(20);
  add_spell("smokescreen",pwc*3/2,"The Koffing suddenly puffs up to twice "+
    "its normal size, and shouts \"Koffing\" as it spews a cloud of vile, "+
    "choking smoke directly on you.\n",
    "The Koffing spews a cloud of concentrated pollutants onto its "+
    "opponent, who coughs and wheezes in pain.\n",
    "other|poison");
  set_dead_ob(TO);
  set_wc_bonus(3);  /* for the explosion at the end */
}
second_life() {
  if(attacker_ob) {
    tell_object(attacker_ob,"As you strike the final blow, the Koffing suddenly explodes!\n");
    say(attacker_ob->query_name()+"'s final blow makes the Koffing explode.\n");
    attacker_ob->hit_player(5+random(11));
  }
  destruct(present("corpse"),environment());
  return 0;
}
