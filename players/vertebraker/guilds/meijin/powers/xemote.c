#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xemote"

/* May be removed if problems occur. Ok Bp Jul 21 20:51 xemote.c */
/*****/
/* display an ANSI emote with the players name at the end */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xemote \n");
  write("     Syntax : xemote <msg>\n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Xemote a message to the room.  Guild xemotes\n");
  write("         are in ANSI color.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  write(HIW+"You Xemote:\n"+NORM);
  tell_room(environment(TP), DAEMON->rancol(str)+" <"+ME+">\n");
  return 1;
}

