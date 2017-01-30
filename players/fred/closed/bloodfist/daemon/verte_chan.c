/*
 * DO NOT REMOVE THIS FILE IT IS NEEDED FOR
 * USING MUD EMOTES OVER GUILD CHANNELS.
 *
 * BEFORE ALTERING IT, YOU MUST CONTACT VERTEBRAKER.
 */
#include <ansi.h>

object * query_bfs() {
  int s;
  object *us, *peeps, gob;
  peeps = ({ });
  s = sizeof(us = users());
  while(s --)
  {
    if(us[s] && (
     ((gob=present("bloodfist_gob", us[s])) && !gob->query_bf_chan_muffle()) ||
     ((gob=present("bloodfist_gob_chan", us[s])) && gob->qk())))
    {
      peeps += ({ us[s] });
    }
  }
  return peeps;
}

object * query_bfms() {
  int s;
  object *us, *peeps, gob;
  peeps = ({ });
  s = sizeof(us = users());
  while(s --)
  {
    if(us[s] &&
     ((gob=present("bloodfist_gob", us[s])) && !gob->query_bf_chan_muffle()))
    {
      peeps += ({ us[s] });
    }
  }
  return peeps;
}

void add_bf_history(string str) {
  "/players/fred/closed/bloodfist/daemon/channel"->add_history(str, 1);
}

void add_bfm_history(string str) {
  "/players/fred/closed/bloodfist/daemon/channel"->add_history(str, 2);
}

string query_bf_tag() {
  return HIR+"bf"+BOLD+BLK+">>"+NORM;
}

string query_bfm_tag() {
  return HIR+"bfM"+BOLD+BLK+">>"+NORM;
}