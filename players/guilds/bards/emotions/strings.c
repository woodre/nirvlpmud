#include "/players/guilds/bards/def.h"

status main() {
  write("You lightly strum the strings of your "+INST+".\n");
  say(tp + " lightly strums the strings of " + POSS(TP) +
    " " + INST + ".\n");
  tell_room(ENV,"  The image of a melody dances through your mind.\n");
  return 1;
}
