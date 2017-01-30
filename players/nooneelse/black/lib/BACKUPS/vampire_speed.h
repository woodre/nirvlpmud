/*
  vampire_speed.h - speed up a specific action a bit (multiply the # of times)
*/


#include "defs.h"

string new_hasted_command;

/* -------- Vampire speed ---------- */
vampire_speed(str) {
  int i, haste_counter;
  string err_msg, s1;
  object speed_obj;
  err_msg = "Enter the name of the activity you want to haste.\n"+
            "Use: vampire speed <what>\n"+
            "(Ex: for 'fireball orc' or 'fireball troll'"+
            " you answer 'fireball'\n";
  if (!str || str=="speed") {
    speed_obj = MY_FANGS->query_vampire_speed();
    if (speed_obj) {
      write("You slow '"+speed_obj->query_vampire_speed()+
            "' down to normal speed.\n");
      destruct(speed_obj);
      MY_FANGS->set_vampire_speed(0);
      return 1;
    }
    else {
      write(err_msg);
      return 1;
    }
  }
  i = sscanf(str, "%s %s", s1, new_hasted_command);
  if (i!=2) {
    write(err_msg);
    return 1;
  }
  if (MY_FANGS->query_vampire_speed()) {
    write("You are already using your vampire speed to '"+
          MY_FANGS->query_vampire_speed()->query_vampire_speed()+"'.\n");
    return 1;
  }
  if (MY_FANGS->query_in_flight()) {
    write("You cannot do that while in flight.\n");
    return 1;
  }
  if (MY_LEVEL < 12 || MY_GUILD_EXP < 670) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 75) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_FANGS->tell_my_room(MY_NAME_CAP+" concentrates and focuses "+
                         MY_PLAYER->query_possessive()+" energies.");
  write("You concentrate for a moment to focus your energies to increase\n"+
        "your speed while using '"+new_hasted_command+"'.\n");
  MY_PLAYER->add_spell_point(- 75);
  speed_obj = clone_object(VAMPIRE_SPEED);
  move_object(speed_obj, MY_PLAYER);
  speed_obj->set_my_player(MY_PLAYER);
  speed_obj->set_vampire_speed(new_hasted_command);
  MY_FANGS->set_vampire_speed(speed_obj);
  return 1;
}
