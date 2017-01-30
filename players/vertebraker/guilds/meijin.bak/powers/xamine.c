#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 1000
#define SKILL_NAME "xamine"

void help() {
  write("\n");
  write("  [(>-------------------------------------------------------------<)]\n");
  write("     Skill  : Examine \n");
  write("     Syntax : xamine <object>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : 0\n");
  write("     Description : \n");
  write("         This command allows a Meijin to determine what weapon\n");
  write("         type a specific weapon is (ie: sword, dagger, mace, etc).\n");
  write("         You can xamine an object that something else is holding\n");
  write("         by doing 'xamine <object> on <who>'.\n");
  write("  [(>-------------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  string who, what, type;
  object ob;

  if(!str) return 0;

  if(sscanf(str, "%s on %s", what, who) == 2) {
	ob = present(who, environment(TP));
	if(!ob) return 0;
	if(ob->is_player()) {
		write("You cannot xamine objects on another player.\n");
		return 1;
	}
	ob = present(what, ob);
	if(!ob) return 0;
  }
  else {
	what = str;
	ob = present(what, TP);
	if(!ob) ob = present(what, environment(TP));
	if(!ob) return 0;
  }
  if(!ob->weapon_class()) {
	write((string)ob->short()+" is not a weapon.\n");
	return 1;
  }
  type = (string)ob->query_type();
  if(!type) {
	write(HIR+"Uh ho."+NORM+"  "+(string)ob->short()+" does not have type set.\n");
	return 1;
  }
  write((string)ob->short()+" is type "+HIC+type+NORM+".\n");
  return 1;
}

