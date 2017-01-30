#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 50 + ((int)GOB->query_guild_skill(SKILL_NAME) / 4) * 7
#define RANK 30
#define SKILL_NAME "bind"

/************************************************************/
/* Bind is a basic heal spell.  It allows the player to     */
/* recover a modest amount of HPs.  This skill can only be  */
/* used once every 2 minutes.                               */
/* heal amount: 5 + random(bind_stat/5)                     */
/* heal cost  : 50 + (bind_stat/4) * 7                      */
/************************************************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Bind \n");
  write("     Syntax : xbind\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Meijin have some basic knowledge of healing.\n");
  write("         You can bind your wounds to recover some hp.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main() {
  int amt;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(GOB->query_skill_variable("bind")) {
	write("You cannot bind your wounds again yet.\n");
	return 1;
  }
  if(TP->query_hp() >= TP->query_mhp()) {
	write("You do not have any wounds to bind.\n");
	return 1;
  }
  write(PRE+"You "+HIB+"bind"+NORM+" your wounds with expert care.\n");
  say(ME+" binds "+POS+" wounds with expert care.\n");

  amt = 5 + random((int)GOB->query_guild_skill(SKILL_NAME) / 5);
  TP->add_hit_point(amt);
  GOB->add_endurance(-COST);
  GOB->bind_delay_start();

  return 1;
}

