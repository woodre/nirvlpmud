#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 0
#define RANK 10000
#define SKILL_NAME "tumble"

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Tumble \n");
  write("     Syntax : xtumble\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Tumbling can decrease the amount of damage you\n");
  write("         receive in combat, but it will also decrease\n");
  write("         the amount of damage you inflict.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main() {
  object obj;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_skill_variable("tumble")) {
	write(PRE+"You are no longer tumbling.\n");
	GOB->remove_skill_variable("tumble");
	return 1;
  }

  if(GOB->query_off_wield()) {
	write("You cannot tumble while offwielding.\n");
	return 1;
  }

  write(PRE+"You will now attempt to parry your enemy's attacks.\n");
  GOB->set_skill_variable("tumble", 2);
  return 1;
}

