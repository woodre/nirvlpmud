/*
  spell_shock.h
*/

#include "defs.h"

/* ---------------- No shock spells until later levels ---------------- */
/* ----------------   AND the possibility of failure   ---------------- */
spell_shock() {
  int test_level;
  if (MY_LEVEL < 13) {
    write("What?\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 15) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  test_level= 27 - MY_LEVEL;
  if (random(100) < test_level) {
    /* take the spell points anyhow */
    MY_PLAYER->add_spell_point(- 15);
    write("You fail to cast the spell correctly!  It fails!\n");
    return 1;
  }
}
