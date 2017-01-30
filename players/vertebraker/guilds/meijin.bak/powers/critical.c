#include "/players/pavlik/guild/defs.h"
#define RANK 22
#define SKILL_NAME "critical"

/************************************************************/
/* critical multiplies the players damage bonus.  all the   */
/* code pertaining to this skill, including endurance point */
/* costs is located in: ~/guild/combat.h                    */
/************************************************************/

void help() {
  write("\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("     Skill  : Critical \n");
  write("     Syntax : n/a\n");
  write("     Cost   : n/a\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Critical is your inherient ability to strike your\n");
  write("         enemy in the most effect places.  Critical hits\n");
  write("         will signifigantly increase the damage you do.\n");
  write("         You cannot score critical hits when offwielding.\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

