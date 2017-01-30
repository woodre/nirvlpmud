inherit "players/illarion/poke/mon/pokemon";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("psiduck");
  set_race("pokemon");
  set_alias("duck");
  set_short("A vacant-eyed bird called Psiduck");
  set_long(
"Except for the fact that its eyes both face front, this creature looks "+
"like nothing more than a fat, yellow duck.  It also seems to be either "+
"stupid or dazed, wandering around aimlessly with an unchanging, blank "+
"expression on its face.");
  create(19);
  set_al(-50+random(100));
  set_chat_chance(10);
  load_chat("The psiduck looks around in utter non-comprehension, and says, \"Psi.\"\n");
  load_chat("The psiduck waddles around in shaky circles.\n");
  set_a_chat_chance(15);
  load_a_chat("An incongruous expression of determination appears on the psiduck's face.\n");
  load_a_chat("The psiduck covers its head and complains, \"Psi-ai-ai!\"\n");
  set_spchance(10);
  add_spell("confusion",pwc*3/2,
"The Psiduck looks directly at you, its blank expression replaced by one of\n"+
"concentration.  An invisible force lifts you into the air, tosses you back\n"+
"and forth a few times, then drops you onto the ground.\n",
"Suddenly, #TN# rises into the air, flies around a little, then "+
"drops unceremoniously in a heap on the ground.\n","physical");
  add_spell("watergun",pwc*3/2,
"The Psiduck opens its mouth, and shoots a stream of water directly into\n"+
"your face, making you cough and splutter.\n",
"The Psiduck shoots a stream of water from its mouth into its #TN#'s face!\n",
"other|water");
}
