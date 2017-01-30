#include "/players/pavlik/guild/defs.h"
#define COST 0
#define SKILL_NAME "xtithe"

/******************************************/
/* determines amount of earned xp that is */
/* converted to guild xp                  */
/******************************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Tithe \n");
  write("     Syntax : xtithe <#>\n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Sets what % of your earned expierience will be\n");
  write("         converted to guild experience.  The number must\n");
  write("         be between 10 and 90.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  int amt;

  if(!str) return 0;
  sscanf(str, "%d", amt);

  if((amt < 10) || (amt > 90)) {
	write("Tithe must be between 10 and 90.\n");
	return 1;
  }
  write(PRE+"Tithe is now set to "+HIW+amt+"%"+NORM+"\n");
  write(PRE+"["+amt+"%] of all earned XP will go to the guild.\n");
  GOB->set_tithe(amt);
  return 1;
}

