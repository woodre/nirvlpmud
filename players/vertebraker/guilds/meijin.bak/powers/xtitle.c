#include "/players/pavlik/guild/defs.h"
#define COST 100
#define RANK 0
#define SKILL_NAME "xtitle"

/*************************************/
/* allow the player to set his title */
/*************************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xtitle \n");
  write("     Syntax : xtitle <string> \n");
  write("     Cost   : "+COST+" ep \n");
  write("     Rank   : 35 \n");
  write("     Description : \n");
  write("         Xtitle allows you to customize your title.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  object obj;

  if(TP->query_guild_rank() < 35) {
	write("You must be guild rank 35 to use Xtitle.\n");
	return 1;
  }
  if(!str) {
	write("Set your title to what?\n");
	return 1;
  }
  write("Your title is now: "+str+"\n");
  TP->set_title(str);
  GOB->add_endurance(-COST);
  return 1;
}

