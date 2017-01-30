/*
  magic_dart.h
*/

#include "defs.h"

/* -------- Get some darts to throw at enemies ---------- */
magic_dart(str) {
  object obj, next_obj;
  int nbr_darts, max_darts, i;

  if(!str || str != "dart") return 0;
  if (MY_LEVEL < 7 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  nbr_darts = 0;
  obj = first_inventory(MY_PLAYER);
  while(obj) {
    next_obj = next_inventory(obj);
    if (obj->id("vampire dart")) nbr_darts++;
    obj = next_obj;
  }
  max_darts = MY_GUILD_EXP - 666;
  nbr_darts = max_darts - nbr_darts;
  if (nbr_darts <= 0) {
    write("You already have the maximum number of darts.\n");
    return 1;
  }
  i = nbr_darts * 15;
  if (MY_SPELL_POINTS < i) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  for (i=0; i<nbr_darts; i++) {
    move_object(clone_object(VAMPIRE_DART), MY_PLAYER);
    this_player()->add_weight(1);
    MY_PLAYER->add_spell_point(- 15);
  }
  if (nbr_darts > 1) {
    write("In a flash of red smoke, "+nbr_darts+
          " darts appear in your hands.\n");
    MY_FANGS->tell_my_room(MY_NAME_CAP+
                           " makes a gesture and some darts appear in "+
                           MY_PLAYER->query_possessive()+" hand.\n");
  }
  else {
    write("In a flash of red smoke, a dart appears in your hand.\n");
    MY_FANGS->tell_my_room(MY_NAME_CAP+
                           " makes a gesture and a dart appears in "+
                           MY_PLAYER->query_possessive()+" hand.\n");
  }
  return 1;
}
