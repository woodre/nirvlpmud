#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "commands"

/********************************/
/* display basic guild commands */
/********************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Commands are basic guild functions that do not have\n");
  write("     to be learned or trained.  To see a list of current\n");
  write("     guild commands simply type 'commands'.  To get more\n");
  write("     information on a specific command type 'xhelp <cmd>'.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

int main() {
  string skill;
  string *cmds;
  int i, rank, col;

  write(HIW+"                 Meijin Guild Commands                       \n"+NORM);
  write(HIB+" [(>------------------------------------------------------<)]\n"+NORM);

  cmds = get_dir(POWERS);
  for(i=0; i<sizeof(cmds); i++) {
        skill = (string)call_other(POWERS+cmds[i], "query_skill_name", 0);
        rank = (int)call_other(POWERS+cmds[i], "query_rank", 0);

        if(skill && !rank) {
		if(!col) write(HIW+"    ");
		write(pad(skill, 14));
		col++;
		if(col == 4) {
			write("\n"+NORM);
			col = 0;
		}
	}
  }

  if(col) write("\n");
  write(HIB+" [(>------------------------------------------------------<)]\n"+NORM);
  return 1;
}

