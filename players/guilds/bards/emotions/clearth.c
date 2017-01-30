#include "/players/guilds/bards/def.h"

status main(){
  write("You clear your throat loudly.\n");
  say(tp + " clears " + POSS(TP) +
    " throat with a loud sound.\n" + "  You think " +
  PRON(TP) + " must have something important to say.\n");
  return 1;
}
