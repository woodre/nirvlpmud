/*
  etheral_door.h
*/

#include "defs.h"

/* -------- etheral door (teleport to the guild hall) ---------- */
go_home(str) {
  int success_percent;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str || str!="door") {
    write(NORM+CYN+"use: etheral door\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 20) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("arrow") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (arrow).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("bell") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (bell).\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("arrow", 1);
  MY_POUCH->subtract_quantity("bell", 1);
  if (MY_ROOM->has_drink(MY_PLAYER)) {
    write(NORM+CYN+"You are not allowed to leave with drinks!\n");
    return 1;
  }
  if (MY_ROOM->has_food(MY_PLAYER)) {
    write(NORM+CYN+"You are not allowed to leave with food!\n"+NORM);
    return 1;
  }
  if (MY_ROOM->realm()=="NT") {
    tell_object(MY_PLAYER, NORM+CYN+"You can't do that in this area.\n"+NORM);
    return 1;
  }
  success_percent = MY_LEVEL * 2 + 70;

  /* now do it */
  if (MY_SPELL_POINTS < 40) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_PLAYER->add_spell_point(- 40);
  if (success_percent >= random(100)) {
    MY_FANGS->tell_my_room(NORM+CYN+MY_NAME_CAP+
                           " rings a bell with an arrow. You see "+MY_OBJECTIVE+"\n"+
                           " vibrate, then vanish."+NORM);
    call_other(ALCHEMIST_CENTRAL, "???", 0);
    move_object(MY_PLAYER, ALCHEMIST_CENTRAL);
    write(NORM+CYN+"You ring a bell with an arrow and begin to vibrate.\n"+
          "When it stops, you are in the guild's central hall.\n\n"+NORM);
    command("look", MY_PLAYER);
    return 1;
  }
  write("Ok.\n");
  return 1;
}
