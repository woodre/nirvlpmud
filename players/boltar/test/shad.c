#include "/players/eurale/defs.h"
#define NO_SHORT 17
object player,shgob;

Stest() {
  return "Shadow Shadow working..."; }

start_shadow(who) {
  player = environment(find_player("illarion"));;
  shadow(player, 1);
  return 1; }

exit() { return 1; }

id() {
return "setter";
}

