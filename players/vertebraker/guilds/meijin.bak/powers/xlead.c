#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xlead"

/* Ok -Bp  1062 Jul 21 21:16 xlead.c */
/****/
/* sets the targets attacker to this player */
/****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xlead \n");
  write("     Syntax : xlead \n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         This command moves you to the front of the\n");
  write("         fighting.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main() {
  object obj;

  if(!(obj=((object)TP->query_attack()))) {
	write("What?\n");
	return 1;
  }

  if(!obj->query_attack()) {
	write("What?\n");
	return 1;
  }

  write(HIB+">> "+HIW+"You step to the front of the battle. "+HIB+"<<\n"+NORM);
  say(ME+" steps to the front of the battle.\n");
  obj->attack_object(TP);
  return 1;
}

