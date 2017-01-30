/*
  go_home.h
*/

#include "defs.h"

/* -------- gohome (teleport to the vampire guild hall) ---------- */
go_home(str) {
  int success_percent;
  string wheree;
  if (MY_LEVEL < 5 || MY_GUILD_EXP < 668) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_ROOM->has_drink(MY_PLAYER)) {
    write("You are not allowed to leave with drinks!\n");
    return 1;
  }
  if (MY_ROOM->has_food(MY_PLAYER)) {
    write("You are not allowed to leave with food!\n");
    return 1;
  }
  if (MY_ROOM->realm()=="NT") {
    tell_object(MY_PLAYER, "You can't do that in this area.\n");
    return 1;
  }
  success_percent = MY_LEVEL * 2 + 70;

  /* now do it */
  if (MY_SPELL_POINTS < 55+random(5)) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(-55-random(5));
  if (success_percent >= random(100)) {
    MY_FANGS->tell_my_room(
                "A mist envelops "+MY_NAME_CAP+
                ".  When it clears, you see a small\n"+
                "bat flying away.");
  write("You fly to the vampire guild hall.\n\n");
  this_player()->move_player("flying#players/eurale/VAMPIRES/RMS/vguild_hall.c");
    return 1;
  } else if(wheree = call_other("obj/base_tele","teleport")) {
      MY_PLAYER->move_player("with an astonished look#"+wheree); }
  write("Ok.\n");
  return 1;
}
