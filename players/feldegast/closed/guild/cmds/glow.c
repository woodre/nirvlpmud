#include "/players/feldegast/closed/guild/defines.h"

do_command() {
  if(TP->query_sp()<40) {
    write("You do not have enough sps for that.\n");
    return 1;
  }
  write("You surround yourself in a "+HIY+"healing glow"+NORM+".\n");
  say(TPN+" is bathed in a "+HIY+"healing glow"+NORM+".\n");
  TP->heal_self(20+random(20));
  TP->add_spell_point(-40);
  return 1;
}
