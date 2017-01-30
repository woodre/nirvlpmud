/*
 * DO NOT REMOVE THIS FILE IT IS NEEDED FOR
 * USING MUD EMOTES OVER GUILD CHANNELS.
 *
 * BEFORE ALTERING IT, YOU MUST CONTACT VERTEBRAKER.
 */
#include <ansi.h>

object * query_vampires() {
  int s;
  object *us, gob, *peeps;
  peeps = ({ });
  s = sizeof(us = users());
  while(s --) {
    if(us[s] && (gob=present("vampire fangs", us[s])) &&
       gob->query_telepathy())
    {
      peeps += ({ us[s] });
    }
  }
  return peeps;
}


void add_history(string str) {
  "/obj/user/chistory"->add_history("Vamps", str);
}

string query_tag() {
  return HIR+":["+NORM;
}
