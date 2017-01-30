#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xcmds"

/*****/
/* these are commands that are executed automatically upon login. */
/* the player can have up to 5 commands in the string.  commands  */
/* are not limited to directions only.  these commands are only   */
/* executed once upon logging into the game.                      */
/*****/

/* Provisional ok, -Bp Jul 16 21:32 xcmds.c */
void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Login Commands \n");
  write("     Syntax : xcmds <cmd1, cmd2, ...>\n");
  write("     Cost   : n/a\n");
  write("     Rank   : n/a\n");
  write("     Description : \n");
  write("         A list of commands that are executed upon login.\n");
  write("         Xcmds can include up to 5 commands in the list.\n");
  write("         Command options include:\n");
  write("              /?     - display current xcmds.\n");
  write("              /clear - reset xcmds.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  string login_cmds;
  login_cmds = (string)GOB->query_login_cmds();

  if(!str || str == "?" || str == "/?") {
        if(!login_cmds) {
                write("You have no login commands.\n");
                return 1;
        }
        write(HIW+"Current login commands: "+HIB+login_cmds+NORM+"\n");
        return 1;
  }
  if(lower_case(str) == "clear" || lower_case(str) == "/clear") {
        write("You clear all login commands.\n");
        GOB->set_login_cmds(0);
        return 1;
  }
  GOB->set_login_cmds(str);
  write(HIW+"Setting login commands ...\n"+NORM);
  write(HIW+"Login commands are now: "+HIB+str+NORM+"\n");
  return 1;
}

