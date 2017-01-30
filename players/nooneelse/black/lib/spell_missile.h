/*
  spell_missile.h
*/

#include "defs.h"

/* --------------- No missile spells until later levels --------------- */
/* ---------------   AND the possibility of failure     --------------- */
spell_missile() {
  int test_level;
  if (MY_LEVEL < 8) {
    write("What?\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 10) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  test_level= 24 - MY_LEVEL;
  if (random(100) < test_level) {
    /* take the spell points anyhow */
    MY_PLAYER->add_spell_point(- 10);
    write("You fail to cast the spell correctly!  It fails!\n");
    return 1;
  }
}
