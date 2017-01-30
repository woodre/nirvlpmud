/*
  spell_fire_ball.h
*/

#include "defs.h"

/* --------------- No fireball spells until 18th level -------------- */
/* ---------------   AND the possibility of failure    -------------- */
spell_fire_ball() {
  int test_level;
  if (MY_LEVEL < 18) {
    write("What?\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 20) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  test_level= 30 - MY_LEVEL;
  if (random(100) < test_level) {
    /* take the spell points anyhow */
    MY_PLAYER->add_spell_point(- 20);
    write("You fail to cast the spell correctly!  It fails!\n");
    return 1;
  }
}
