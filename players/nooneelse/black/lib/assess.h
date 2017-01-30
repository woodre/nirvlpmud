/*
  assess.h
*/

#include "defs.h"

/* -------- Compare player's strength vs monster's ---------- */
assess(str) {
  int level_diff, wc_diff, ac_diff;
  object target_obj;
  if (!str) return 0;
  if (MY_LEVEL < 1 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 10) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  target_obj=present(str, MY_ROOM);
  if (!target_obj) target_obj=find_living(str);
  if (!target_obj || !living(target_obj)) {
    write(str+" cannot be found!\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 10);

  if (target_obj->query_alignment() >= 200)
    write("This creature's alignment is on the 'good' side.\n");
  else
  if (target_obj->query_alignment() <= 200)
    write("This creature's alignment is on the 'evil' side.\n");
  else
    write("This creature's alignment is neutral.\n");

  level_diff = MY_LEVEL - target_obj->query_level();
  if (level_diff > 0)
    write("You're higher in level.\n");
  else
  if (level_diff < 0)
    write("You're lower in level.\n");
  else
    write("You're about the same level.\n");

  wc_diff = MY_WC - target_obj->query_wc();
  if (wc_diff > 0)
    write("You're higher in weapon class.\n");
  else
  if (wc_diff < 0)
    write("You're lower in weapon class.\n");
  else
    write("You're about the same weapon class.\n");

  ac_diff = MY_AC - target_obj->query_ac();
  if (ac_diff > 0)
    write("You're higher in armor class.\n");
  else
  if (ac_diff < 0)
    write("You're lower in armor class.\n");
  else
    write("You're about the same armor class.\n");
  return 1;
}
