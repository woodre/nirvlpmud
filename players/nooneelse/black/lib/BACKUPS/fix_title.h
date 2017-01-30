/*
  fix_title.h - fix the player's title
              - restart this player's heartbeat & their fang's heartbeat
*/

#include "defs.h"

/* -------- Fix this player's title or their heart beat ---------- */
fix_title(str) {
  object vampire_training_obj;
  string new_title, my_gender;
  int player_level;
  if (str && (str=="heartbeat" || str=="heart beat")) {
    MY_PLAYER->heart_beat();
    MY_PLAYER->set_heart_beat(1);
    MY_FANGS->heart_beat();
    MY_FANGS->set_heart_beat(1);
  write("Your "+BOLD+"HEARTBEAT"+NORM+" returns to a normal rhythm.\n");
  return 1; }
  }

/*
  if (MY_LEVEL > 20 || !str || str!="title") return 0;
  call_other(GUILD_TRAINING, "???");
  vampire_training_obj = find_object(GUILD_TRAINING);
  player_level = MY_LEVEL;
  my_gender = MY_PLAYER->query_gender();
  new_title = vampire_training_obj->remote_get_title(player_level, my_gender);
  if (!new_title) {
    write("There's something wrong with the title command.\n"+
          "Leave mail for Nooneelse.\n");
    return 1;
  }
  MY_PLAYER->set_title(new_title);
  return 1;
}
*/
