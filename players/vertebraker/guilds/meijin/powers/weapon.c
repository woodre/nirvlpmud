#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 0
#define RANK 1000
#define SKILL_NAME "weapon"

/* help file only */

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : n/a \n");
  write("     Syntax : n/a\n");
  write("     Cost   : n/a\n");
  write("     Rank   : n/a\n");
  write("     Description : \n");
  write("         After a Meijin has mastered a specific weapon\n");
  write("         type he or she may gain a new weapon type and\n");
  write("         begin to practice it as well.\n");
  write("         If a Meijin earns enough skills and practices\n");
  write("         he could potentially master every weapon type.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

