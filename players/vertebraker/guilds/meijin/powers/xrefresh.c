#include "/players/vertebraker/guilds/meijin/defs.h"
#define RANK 10
#define SKILL_NAME "refresh"

/*****/
/* Allow the player to recover endurance points by using spell points. */
/* The ratio for sp to ep exchange improves as the player increases    */
/* his refresh skill.  the ratio is calculated as:                     */
/*    ratio = 8 - (refresh_stat/15)                                    */
/* the best possible ration is 2:1 (2 sp = 1 ep)                       */
/*****/

void help() {
  write("\n");
  write("  [(>-----------------------------------------------------<)]\n");
  write("     Skill  : Refresh \n");
  write("     Syntax : xrefresh <#>\n");
  write("     Cost   : # sp\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Refresh uses mind over matter to allow you to\n");
  write("         recover some of your endurance.  The more\n");
  write("         disciplined you become in Refresh, the more\n");
  write("         endurance points you will recover per spell point.\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main(string str) {
  int amt, ratio;

  if(!GOB->query_skill(SKILL_NAME)) return 0;
  if(!str) return 0;
  sscanf(str, "%d", amt);
  if(amt <= 0) return 0;

  if(amt > TP->query_sp()) {
	write("You do not have that many spell points.\n");
	return 1;
  }

  write(PRE+"With extraordinary concentration and purpose, you reach deep down\n");
  write(PRE+"within yourself and find "+HIB+"refreshing"+NORM+" energy!\n");
  say(ME+" suddenly looks more refreshed.\n");

  ratio = 8 - ((int)GOB->query_guild_skill(SKILL_NAME) / 15);

  TP->add_spell_point(-amt);
  amt = (amt / ratio) * 7;
  GOB->add_endurance(amt);
  write(PRE+"You recover "+amt+" endurance points from the effort.\n");

  return 1;
}
 
