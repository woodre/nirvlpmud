/*
  shadow.h
*/

#include "defs.h"

/* --------------- Follow someone from room to room --------------- */
shadow(str) {
  if (MY_LEVEL < 1 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if(!str && !MY_FANGS->query_following_name()) {
    write("Use: shadow <who> to follow <who>\n"+
          "     shadow       to stop following\n");
    return 1;
  }
  if (!str && MY_FANGS->query_following_name()) {
    tell_object(MY_PLAYER,
      "Stopped shadowing "+capitalize(MY_FANGS->query_following_name())+".\n");
    MY_FANGS->set_following_name(0);
    MY_FANGS->set_following_obj(0);
    return 1;
  }
  MY_FANGS->set_following_name(str);
  MY_FANGS->set_following_obj(present(str, MY_ROOM));
  if (MY_FANGS->query_following_obj() &&
      !living(MY_FANGS->query_following_obj())) {
    write("What?  You cannot shadow a nonliving thing.\n");
    MY_FANGS->set_following_name(0);
    MY_FANGS->set_following_obj(0);
    return 1;
  }
  if (!MY_FANGS->query_following_obj()) {
    write(capitalize(MY_FANGS->query_following_name())+" isn't here.\n");
    MY_FANGS->set_following_name(0);
    MY_FANGS->set_following_obj(0);
    return 1;
  }
  if (!MY_FANGS->query_following_obj()->query_npc() &&
      MY_FANGS->query_following_obj()->query_level() > 19 &&
      MY_LEVEL < 20) {
    write("You can't shadow a wizard!\n");
    MY_FANGS->set_following_name(0);
    MY_FANGS->set_following_obj(0);
    return 1;
  }
  if (MY_SPELL_POINTS < 5) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 5);
  write("Now shadowing: "+capitalize(MY_FANGS->query_following_name())+"\n");
  return 1;
}
