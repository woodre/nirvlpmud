/*
 * Absorb object - actually just heals the damage done up to the
 * set amount.
 * Rumplemintz
 */

#include <ansi.h>

int starthp, ABSORB_DAMAGE;

short() { return 0; }

id(str) { return str == "dopple_spirits_ob"; }

void reset(status arg) {
  if (arg) return;
}

int start_me(int amount) {
  ABSORB_DAMAGE = amount;
  starthp = (int)environment(this_object())->query_hp();
  set_heart_beat(1);
}

int stop_me() {
  set_heart_beat(0);
  destruct(this_object());
}

int query_absorb() { return ABSORB_DAMAGE; }

void heart_beat() {
  int currhps, heal;

  currhps = (int)environment(this_object())->query_hp();
  if (currhps < starthp) {
    if (ABSORB_DAMAGE > (starthp - currhps)) {
      ABSORB_DAMAGE -= (starthp - currhps);
      heal = (starthp - currhps);
      say(HIG + "The spirits absorb " + heal + " points. (" +
          ABSORB_DAMAGE + " left)" + NORM + "\n");
    }
    else {
      heal = ABSORB_DAMAGE;
      say(HIG + "The spirits absorb " + heal +
          " points, and disipate." + NORM + "\n");
      stop_me();
    }
    environment(this_object())->heal_self(heal);
    return;
  }
  if (random(100) > 75) {
    say("The faction spirits hover around you.\n");
    return;
  }
}

