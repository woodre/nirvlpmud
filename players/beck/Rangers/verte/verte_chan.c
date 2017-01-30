/*
 * DO NOT REMOVE THIS FILE IT IS NEEDED FOR
 * USING MUD EMOTES OVER GUILD CHANNELS.
 *
 * BEFORE ALTERING IT, YOU MUST CONTACT VERTEBRAKER.
 */
#include "/players/beck/Defs.h"

object * query_rangers() {
  int s;
  object *us, gob, *peeps;
  peeps = ({ });
  s = sizeof(us = users());
  while(s --) {
    if(us[s] && (gob=present("ranger_object", us[s])) &&
       !gob->QMuffles())
    {
      peeps += ({ us[s] });
    }
  }
  return peeps;
}


void add_history(string str) {
  /* no history for Rangers :^( */
}

string query_tag() {
  return BOLD+BLUE+"["+OFF+GREEN+"Power Ranger"+OFF+BOLD+BLUE+"]"+OFF;
}
