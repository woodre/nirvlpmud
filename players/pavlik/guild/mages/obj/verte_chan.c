/*
 * DO NOT REMOVE THIS FILE IT IS NEEDED FOR
 * USING MUD EMOTES OVER GUILD CHANNELS.
 *
 * BEFORE ALTERING IT, YOU MUST CONTACT VERTEBRAKER.
 */
#include <ansi.h>


object * query_mages() {
  int s;
  object *us, *peeps;
  peeps = ({ });
  s = sizeof(us = users());
  while(s --) {
    if(us[s] && present("mageobj", us[s])) peeps += ({ us[s] });
  }
  return peeps;
}

void add_history(string str) {
  "/obj/user/chistory"->add_history("MAGES", str);
}

string query_tag() {
  return HIC+"["+HIR+"*"+HIC+"]"+NORM;
}
