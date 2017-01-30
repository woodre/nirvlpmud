#include "/players/guilds/bards/def.h"

status main() {
  write("You absently tune your " + INST + ".\n");
  say(tp + " tunes " + POSS(TP) + " " + INST + ".\n");
  return 1;
}
