/*
  regenerate.h - let vampire bury self & heal a little quicker
*/

#include "defs.h"

regenerate(str) {
  object regenerate_room_obj, regenerate_silence_obj;
  if (!str || str != "me") return 0;
  if (MY_PLAYER->query_attack() &&
      environment(MY_PLAYER->query_attack())==MY_ROOM) {
    write("You can't use regenerate while in combat.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if (MY_LEVEL < 10 || MY_GUILD_EXP < 669) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }

  /* return them to normal form, if they're in one */
  if (MY_FANGS->query_in_a_form() && MY_ROOM!=VAMPIRE_FORM) {
    command("normal form", MY_PLAYER);
    MY_FANGS->set_in_a_form(0);
  }
  /* dismiss wolf, if there is one */
  if (MY_FANGS->query_wolf_obj()) destruct(MY_FANGS->query_wolf_obj());
  /* dismiss servant, if there is one */
  if (MY_FANGS->query_servant_obj()) destruct(MY_FANGS->query_servant_obj());
  /* move em to the regenerate area */
  regenerate_room_obj=clone_object(REGENERATE_ROOM);
  move_object(regenerate_room_obj, MY_ROOM);
  move_object(MY_PLAYER, regenerate_room_obj);
  /* set em up so they can't do anything while regenerateing */
  regenerate_silence_obj=clone_object(REGENERATE_SILENCE_OBJ);
  move_object(regenerate_silence_obj, MY_PLAYER);
  MY_PLAYER->add_spell_point(- 50);
  write("You concentrate for a moment, then all goes dark as you turn\n"+
        "into a mist and sink into the ground to regenerate yourself.  This\n"+
        "is a most disconcerting thing to do since you can't do anything\n"+
        "while regenerateing.\n"+
        "To leave this state, type 'end regenerate'\n"+
        "To check your health, type 'check health'\n");
  MY_FANGS->tell_my_room(
              MY_NAME_CAP+
              " closes "+MY_PLAYER->query_possessive()+ "eyes and seems to\n"+
              "concentrate for a moment, then disolves into a mist, which\n"+
              "then sinks into the ground.");
  return 1;
}
