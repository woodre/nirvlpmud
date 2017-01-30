/*
  show_player.h
*/

#include "defs.h"

/* --------- look at a player -------- */
show_player(str) {
  string what, who;
  object target_obj;
  what=query_verb();
  if (!str) {
    MY_PLAYER->look();
    return 1;
  }
  if (what=="examine" || what=="exa" || what=="ex") {
    MY_PLAYER->look("at " + str);
    target_obj=present(str, MY_ROOM);
    if (target_obj) {
      if (present("nooneelse@vampire@fangs", target_obj))
        write("~o~  This player is a fellow vampire!\n");
      if (present("nooneelse vampire bite", target_obj))
        write("~:~  This player has been bitten by a vampire!\n");
    }
    return 1;
  }
  if (what=="look" || what=="l") {
    if (str=="at") return 0;
    sscanf(str, "at %s", who);
    /* look at someone or something */
    if (who) {
      target_obj=present(who, MY_ROOM);
      if (!target_obj) target_obj=present(who, MY_PLAYER);
      if (!target_obj) return 0;
      MY_PLAYER->look("at " + who);
      if (target_obj) {
        if (present("nooneelse@vampire@fangs", target_obj))
          write("~o~  This player is a fellow vampire!\n");
        if (present("nooneelse vampire bite", target_obj))
          write("~:~  This player has been bitten by a vampire!\n");
        return 1;
      }
    }
    /* just 'look' */
    else {
      if (MY_PLAYER->query_brief())
        tell_object(MY_PLAYER, MY_ROOM->short()+"\n");
      else
        command("look", MY_PLAYER);
    }
  }
  return 0;
}
