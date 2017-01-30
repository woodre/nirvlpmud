#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xhelp"

/*****/
/* guild help files */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xhelp \n");
  write("     Syntax : xhelp <topic>\n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Displays the guild help information.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

void guild_info() {
  write("\n");
  write(HIW+"                         The Meijin                         \n"+NORM);
  write(HIB+"  [(>----------------------------------------------------<)]\n"+NORM);
  write(HIW+"      guild             commands            skills\n"+NORM);
  write(HIW+"      advancing         practice            stats\n"+NORM);
  write(HIW+"      combat            endurance           donations\n"+NORM);
  write(HIW+"      types             wimpy               credits\n"+NORM);
  write(HIW+"      theme             bugs\n"+NORM);
  if((int)TP->query_level() > 20) {
	write(HIW+"      wizcmds\n"+NORM);
  }
  write(HIB+"  [(>----------------------------------------------------<)]\n"+NORM);
}

int query_rank() { return RANK; }
string query_skill_name() { return "xhelp"; }

int main(string str) {
  string *cmds;
  string name;
  int i;

  if(!str) {
	guild_info();
	return 1;
  }
  if(file_size(POWERS+str+".c") > 0) {
	call_other(POWERS+str, "help");
	return 1;
  }
  cmds = get_dir(POWERS);
  for(i=0; i<sizeof(cmds); i++) {
	name = (string)call_other(POWERS+cmds[i], "query_skill_name");
	if(name == str) {
		call_other(POWERS+cmds[i], "help");
		return 1;
	}
  }
}

