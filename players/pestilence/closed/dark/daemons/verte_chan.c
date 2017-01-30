/*
 * DO NOT REMOVE THIS FILE IT IS NEEDED FOR
 * USING MUD EMOTES OVER GUILD CHANNELS.
 *
 * BEFORE ALTERING IT, YOU MUST CONTACT VERTEBRAKER.
 */
#include <ansi.h>


object * query_dos() {
  int s;
  object *us, gob, *peeps;
  peeps = ({ });
  s = sizeof(us = users());
  while(s --) {
    if(us[s] && (gob=present("dknight_ob", us[s])) &&
       !gob->query_muff())
    {
      peeps += ({ us[s] });
    }
  }
  return peeps;
}

void add_history(string str) {
  write_file("/players/pestilence/closed/dark/log/darktell", str);
}

string query_tag() {
  return HIK+"<"+HIR+"DARK"+HIK+">"+NORM;
}
