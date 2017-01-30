#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "setenter"

/*****/
/* custom message when entering the game */
/*****/

/* Decorative command, Bp Jul 16 21:00 setenter.c */
void help() {
  write("\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("     Skill  : Set Enter Msg \n");
  write("     Syntax : setenter <msg> \n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Set the message to be displayed when you login.\n");
  write("         Use '$$' to signify where your name should appear\n");
  write("         in the message.\n");
  write("         Command options include:\n");
  write("            /?     - display current enter msg.\n");
  write("            /clear - clear enter msg.\n");
  write("\n");
  write("         Example:\n");
  write("            'setenter Hello Everyone! $$ smiles cheerfully.'\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  string msg;

  if(!str) return 0;
  if(lower_case(str) == "/?") {
	msg = (string)GOB->query_enter_msg();
	if(!msg) write("You do not have an enter message.\n");
	else write("Current enter message is: "+HIW+msg+NORM+"\n");
	return 1;
  }
  if(lower_case(str) == "/clear") {
	write("Your enter message is now blank.\n");
	GOB->set_enter_msg(0);
	return 1;
  }
  if(strlen(str) > 90) {
	write("You enter message is too long.  Max is 90.\n");
	write("Please choose something shorter.\n");
	return 1;
  }
  write("Your enter message is now set to: "+HIW+str+NORM+"\n");
  GOB->set_enter_msg(str);
  return 1;
}

