#include "/players/guilds/bards/def.h"

status main(){
  write("You conjure four balls of pastel colored light and deftly\n" +
  "juggle them between your hands.\n");
  say(format(tp +
    " conjures four balls of pastel colored light and proceeds" +
    "to deftly juggle them between " + POSS(TP) +  " hands."));
  return 1;
}
