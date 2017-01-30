#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "emote"

/*****/
/* ANSI emotes */
/*****/
/* Command to be removed at first sign of trouble. -Bp
 Jul 16 20:53 emote.c */

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : emote \n");
  write("     Syntax : emote <msg>\n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Emote a message to the room.  Guild emote are\n");
  write("         in ANSI color.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

int main(string str){
  write(HIW+"You Emote:\n"+NORM);
  tell_room(environment(TP), DAEMON->rancol(ME+" "+str)+NORM+"\n");
  return 1;
}

