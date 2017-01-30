/*
  wriath_form.h
*/

#include "defs.h"

/* --------------- Sneak into a room --------------- */
wraith_form(str) {
  int success_percent;
  if (!str || str != "form") return 0;
  if (MY_LEVEL < 10 || MY_GUILD_EXP < 669) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  /* already sneaking? */
  if (MY_FANGS->query_sneak_seconds() > 0) {
    MY_FANGS->set_sneak_seconds(0);
    if (MY_PLAYER->query_invis() > 0) MY_PLAYER->visible();
    write("You've changed back from wraith form to normal form.\n");
    MY_FANGS->tell_my_room(MY_NAME_CAP+" slowly fades into view...");
    return 1;
  }
  /* base time */
  MY_FANGS->set_sneak_seconds(5 + MY_LEVEL);
  /* base chance */
  success_percent = 25 + (MY_LEVEL * 2);
  /* dex & int adjustments */
  if (MY_INT > MY_LEVEL && MY_STE > MY_LEVEL)
    success_percent += 10;
  else
  if (MY_INT < MY_LEVEL || MY_STE < MY_LEVEL)
    success_percent -= 5;
  else
  if (MY_INT >= MY_LEVEL || MY_STE >= MY_LEVEL)
    success_percent += 5;
  /* ac - clank, clank? */
  if (MY_AC==8) success_percent -=4;
  else
  if (MY_AC==9) success_percent -=6;
  else
  if (MY_AC==10) success_percent -=10;

  /* now do it */
  if (MY_SPELL_POINTS < 25) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  write("Ok.\n");
  MY_PLAYER->add_spell_point(- 25);
  if (success_percent >= random(100)) {
    MY_PLAYER->set_invs_sp();
    write("You've changed from normal form to wraith form.\n");
    MY_FANGS->tell_my_room(MY_NAME_CAP+" fades into the surrounding terrain.");
  }
  else {
    MY_FANGS->set_sneak_seconds(0);
  }
  MY_FANGS->start_wraith_form();
  return 1;
}
