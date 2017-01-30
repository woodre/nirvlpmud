inherit "players/illarion/poke/mon/pokemon";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("oddish");
  set_alias("plant");
  set_race("pokemon");
  set_short("A moving plant called an Oddish");
  set_long(
"Although at first glance the Oddish would look like any other plant in the\n"+
"field, one look at the front of it's radish-shaped head would dispel any\n"+
"doubts.  Instead of hair, it has broad, grass-like leaves, and when it\n"+
"wishes, it can pop out of the ground and move about on two small feet.\n");
  create(19);
  set_al(100-random(200));
  set_chat_chance(12);
  load_chat("The Oddish runs around your feet, saying \"Ish, ish, Oddish!\"\n");
  load_chat("The Oddish pokes at something on the ground, and asks, \"Oddish?\"\n");
  load_chat(
"Popping its little feet under the surface of the ground, the Oddish seems\n"+
"to draw a bit of refreshment from the soil.\n");
  load_chat("The Oddish ruffles it's leaf-hair, saying \"Oddish\" as if to make sure no\none has forgotten.\n");
  set_a_chat_chance(15);
  load_a_chat("The Oddish tries to run away, yelling \"Oddish!\" at the top\n"+
              "of its odd voice.\n");
  load_a_chat("The Oddish tries to kick some dirt into your eyes.\n");
  set_spchance(20);
  add_spell("oddish spear",pwc*3/2,
      "The Oddish suddenly launches itself at you, striking you with the top\n"+
      "of its pointy head!\n",
      "The Oddish suddenly launches itself at #TN#, striking #TO# with the\n"+
      "top of its pointy head!\n","physical");
}
