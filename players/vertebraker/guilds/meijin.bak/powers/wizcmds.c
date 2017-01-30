#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 1000
#define SKILL_NAME "wizcmds"

/*****/
/* commands avaliable only to wizards */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Wizard Commands \n");
  write("     Syntax : wizcmds\n");
  write("     Description : \n");
  write("         'wizcmds' will list all commands that are\n");
  write("         avaliable to wizards.  These are informational\n");
  write("         or debug commands that wizards can use.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str){
  write("\n");
  write("                     Wizard Commands                      \n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     xstat               xgrant            debug            \n");
  write("     xlevelcost\n");
  write("  [(>----------------------------------------------------<)]\n");
  return 1;
}

