/*
  assess.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Compare player's strength vs monster's ---------- */
assess(str) {
  int level_diff, wc_diff, ac_diff;
  object target_obj;

  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you assess anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) return 0;
  if (MY_GUILD_RANK < 10) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("crystal bead") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (crystal beads).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 10) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("crystal bead", 1);

  target_obj=present(str, MY_ROOM);
  if (!target_obj) target_obj=find_living(str);
  if (!target_obj || !living(target_obj)) {
    write(NORM+CYN+capitalize(str)+" cannot be found!\n"+NORM);
    return 1;
  }
  MY_PLAYER->add_spell_point(- 10);

  if (target_obj->query_alignment() >= 200)
    write(NORM+CYN+"This creature's alignment is on the 'good' side.\n"+NORM);
  else
  if (target_obj->query_alignment() <= 200)
    write(NORM+CYN+"This creature's alignment is on the 'evil' side.\n"+NORM);
  else
    write(NORM+CYN+"This creature's alignment is neutral.\n"+NORM);

  level_diff = MY_LEVEL - target_obj->query_level();
  if (level_diff > 0)
    write(NORM+CYN+"You're higher in level.\n"+NORM);
  else
  if (level_diff < 0)
    write(NORM+CYN+"You're lower in level.\n"+NORM);
  else
    write(NORM+CYN+"You're about the same level.\n"+NORM);

  wc_diff = MY_WC - target_obj->query_wc();
  if (wc_diff > 0)
    write(NORM+CYN+"You're higher in weapon class.\n"+NORM);
  else
  if (wc_diff < 0)
    write(NORM+CYN+"You're lower in weapon class.\n"+NORM);
  else
    write(NORM+CYN+"You're about the same weapon class.\n"+NORM);

  ac_diff = MY_AC - target_obj->query_ac();
  if (ac_diff > 0)
    write(NORM+CYN+"You're higher in armor class.\n"+NORM);
  else
  if (ac_diff < 0)
    write(NORM+CYN+"You're lower in armor class.\n"+NORM);
  else
    write(NORM+CYN+"You're about the same armor class.\n"+NORM);
  return 1;
}
