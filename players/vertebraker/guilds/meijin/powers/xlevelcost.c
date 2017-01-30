#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 0
#define RANK 1000
#define SKILL_NAME "xstat"

/* wizard command */

void help() {
  write("\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("     Skill  : xlevelcost \n");
  write("     Syntax : xlevelcost <rank> <rank>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : wizard\n");
  write("     Description : \n");
  write("        This command shows how much experience is required\n");
  write("        for a given guild rank.  If two ranks are specified\n");
  write("        then experience cost for each rank within that range\n");
  write("        will be displayed.\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str){
  int x, y;
  int i, amt;

  if(TP->query_level() < 20) return 0;

  if(sscanf(str, "%d %d", x, y) == 2) {
	if(x >= y) {
		write("Please specify a valid range.\n");
		return 1;
	}
	for(i=x; i<=y; i++) {
		amt = (int)DAEMON->query_rank_cost(i);
		write("Guild XP cost for Rank "+i+" is: "+amt+".\n");
	}
	return 1;
  }
  if(sscanf(str, "%d", x) == 1) {
	amt = (int)DAEMON->query_rank_cost(x);
	write("Guild XP cost for Rank "+x+" is: "+amt+".\n");
	return 1;
  }
}

