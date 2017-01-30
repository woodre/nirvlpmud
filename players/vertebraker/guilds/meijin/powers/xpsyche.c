#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 320
#define RANK 30
#define SKILL_NAME "psyche"

/* if amt is amt skill is raised, and max 5 ok, Bp 
  1783 Jul 21 21:31 xpsyche.c */
void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Psyche \n");
  write("     Syntax : xpsyche\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Call upon your mental discipline to get 'psyched'.\n");
  write("         Pysche naturally increases all your guild stats\n");
  write("         for a short period a time.  It takes awhile to\n");
  write("         recover from the effort of a pysche.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main() {
  string *stats;
  int i, amt;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(GOB->query_skill_variable("pysche") != 0) {
	write("You cannot get pysched again yet.\n");
	return 1;
  }

  write(PRE+"You "+HIB+"psyche"+NORM+" yourself up!!!\n");
  write(PRE+"You begin breathing hard and your pulse "+HIW+"beats"+NORM+" within your\n");
  write(PRE+"body like large drums sounding the call to battle.\n");

  amt = random((int)GOB->query_guild_skill(SKILL_NAME) / 14);
  if(amt > 5) amt = 5;
  if(amt < 1) amt = 1;

  stats = m_indices((mixed)GOB->query_guild_stats());
  for(i=0; i<sizeof(stats); i++) {
	GOB->add_guild_bonus(stats[i], amt);
  }

  GOB->xpsyche_start(amt);
  GOB->add_endurance(-COST);
  return 1;
}

