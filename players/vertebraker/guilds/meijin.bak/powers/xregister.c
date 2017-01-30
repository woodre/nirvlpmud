#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xregister"

/* refresh the guild object */

void help() {
  write("\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("     Skill  : xregister \n");
  write("     Syntax : xregister \n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Refresh your guild soul.  This may fix any guild\n");
  write("         related errors that are occuring.\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

