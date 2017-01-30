#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xdonators"

/*****/
/* display to donation point standings */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xdonators\n");
  write("     Syntax : xdonators\n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         This command lists all members on-line ranked\n");
  write("         by donation points.  Remember that the top [2]\n");
  write("         donation leaders earn special bonuses.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main() {
  object *meijin;
  int *leaders;
  string name;
  int i, x;

  DAEMON->calc_donation_leaders();
  leaders = (mixed)DAEMON->query_donation_leaders();
  meijin = (mixed)DAEMON->query_Meijin();

  write(HIW+"              Meijin Donation Leaders                  \n"+NORM);
  write(HIB+"[(>-------------------------------------------------<)]\n"+NORM);

  for(i=0; i<sizeof(leaders); i++) {
	for(x=0; x<sizeof(meijin); x++) {
		name = capitalize((string)environment(meijin[x])->query_real_name());
		if((int)meijin[x]->query_donations() == leaders[i]) {
			if((int)environment(meijin[x])->query_invis()) {
				continue;
			}
			write("    "+pad(name, 16)+leaders[i]+"\n");
		}
	}
  }

  write(HIB+"[(>-------------------------------------------------<)]\n"+NORM);
  return 1;
}

