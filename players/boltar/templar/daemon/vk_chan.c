/*
 * DO NOT REMOVE THIS FILE IT IS NEEDED FOR
 * USING MUD EMOTES OVER GUILD CHANNELS.
 *
 * BEFORE ALTERING IT, YOU MUST CONTACT VERTEBRAKER.
 */
#include <ansi.h>

object * query_knights() {
  int s;
  object *us, gob, *peeps;
  peeps = ({ });
  s = sizeof(us = users());
  while(s --) {
    if(us[s] && (gob=present("KnightTemplar", us[s])) &&
       !gob->query_block())
    {
      peeps += ({ us[s] });
    }
  }
  return peeps;
}


void add_history(string str) {
  "/obj/user/chistory"->add_history("Knights Templar", str);
}

string query_tag() {
  return GRN+"("+HIW+"Templar"+NORM+GRN+")"+NORM;
}
