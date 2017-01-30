#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "setexit"

/*****/
/* custom message when exiting the game */
/*****/

void help() {
  write("\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("     Skill  : Set Exit Msg \n");
  write("     Syntax : setexit <msg> \n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Set the message to be displayed when you logout.\n");
  write("         Use '$$' to signify where your name should appear\n");
  write("         in the message.\n");
  write("         Command options include:\n");
  write("            /?     - display current exit msg.\n");
  write("            /clear - clear exit msg.\n");
  write("\n");
  write("         Example:\n");
  write("            'setenter Goodbye! $$ waves cheerfully.'\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  string msg;

  if(!str) return 0;
  if(lower_case(str) == "/?") {
	msg = (string)GOB->query_exit_msg();
	if(!msg) write("You do not have an exit message.\n");
	else write("Current exit message is: "+HIW+msg+NORM+"\n");
	return 1;
  }
  if(lower_case(str) == "/clear") {
	write("Your exit message is now blank.\n");
	GOB->set_exit_msg(0);
	return 1;
  }
  if(strlen(str) > 90) {
	write("Your exit message is too long.  Max is 90.\n");
	write("Please choose something shorter.\n");
	return 1;
  }
  write("Your exit message is now set to: "+HIW+str+NORM+"\n");
  GOB->set_exit_msg(str);
  return 1;
}

