/*
  eliminate the use of game spells for Vampires
*/

#include "/players/eurale/defs.h"

no_game_spls() {
  write(HIR+
    "As a Vampire, you cannot use that ability.\n"+NORM);
return 1;
}
