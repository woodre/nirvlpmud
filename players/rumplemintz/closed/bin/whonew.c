#pragma strong_types

#include <ansi.h>

inherit "/players/rumplemintz/closed/ansi_pad";

object *sort_by_level(object *who, int wizzies) {
  int i, j, sorted;
  object tmp;

  j = sizeof(who);
  sorted = 0;
  while (!sorted) {
    sorted = 1;
    j --;
    if (!wizzies) {
      for (i=0; i<j; i++) {
        if (who[i]->query_level()+who[i]->query_extra_level() <
            who[i+1]->query_level()+who[i+1]->query_extra_level() ) {
          tmp = who[i];
          who[i] = who[i+1];
          who[i+1] = tmp;
          sorted = 0;
        }
      }
    } else {
      for (i=0; i<j; i++) {
        if (who[i]->query_level() < who[i+1]->query_level()) {
          tmp = who[i];
          who[i] = who[i+1];
          who[i+1] = tmp;
          sorted = 0;
        }
      }
    }
  }
  return who;
}

string add_zero(mixed str) {
  str = "" + str;
  if (strlen(str) == 1)
    str = "0" + str;
  return str;
}

int player_check(object who) {
  return who->query_level() <= 19;
}
int wizard_check(object who) {
  return who->query_level() > 19;
}

int get_players(object user, string type) {
  if (type == "play")
    return user->query_level() <= 19;
  else if (type == "wiz")
    return user->query_level() > 19;
  else
    return 0;
}

int whonew() {
  int lev, xlev, invis, plyr_count, wiz_count, x, y;
  object *all_users, *players, *wizards;
  string shrt, levstring;
  string *shrt2;

  all_users = users();
/*
  players = sort_by_level(filter_array(all_users, "get_players", "play"), 0);
*/
  players = filter_array(all_users, "player_check");
/*
  wizards = sort_by_level(filter_array(all_users, "get_players", "wiz"), 1);
*/
  wizards = filter_array(all_users, "wizard_check");

  write("\n");
  write("-=-=-=-=-=\n");
  for (x=0; x<sizeof(wizards); x++) {
    wiz_count++;
    write(wizards[x]->short() + "\n");
  }
  for (x=0; x<sizeof(players); x++) {
    plyr_count++;
    write(players[x]->short() + "\n");
  }
  write(wiz_count + " wizards and " + plyr_count + " players.\n");
  return 1;
}
