/*
  alarm_bat.h
*/

#include "defs.h"

/* -------- Alarm bat ---------- */
alarm_bat(str) {
  object bat_obj;
  string str2;
  if (!str || sscanf(str, "bat %s", str2)!=1) {
    write("You must include a message for the bat to say.\n"+
          "Use: msg bat <msg>\n");
    return 1;
  }
  if (MY_LEVEL < 1 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_FANGS->query_alarm_bat_obj()) {
    write("You already have an active bat.\n");
    write("Use: 'dismiss bat' to get rid of it.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 5) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 5);
  bat_obj=clone_object(ALARM_BAT);
  MY_FANGS->set_alarm_bat_obj(bat_obj);
  bat_obj->set_message(str2);
  bat_obj->set_bat_owner(MY_NAME);
  move_object(bat_obj, MY_ROOM);
  write("Ok.\n");
  return 1;
}
