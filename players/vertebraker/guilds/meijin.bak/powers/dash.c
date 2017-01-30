#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "dash"

/*****/
/* guild speedster command.  allows up to 5 directional commands */
/*****/
/* approved, Bp Jul 16 20:48 dash.c */

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : dash \n");
  write("     Syntax : dash <dir1, dir2, ...>\n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         The guild speedster.  This command will allow\n");
  write("         you to move up to 5 times instantly.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

int cmd_check(string str, string secret_code){
  string cmd;
  /*
   * using the "secret code" will bypass the command check.  the code
   * should only be used by internal functions, never where a player
   * can see it (ie: dont use 'command').
   */
  if(sscanf(str, "dash%s", cmd) == 1) {
	write(PRE+"recursive dash - command ignored.\n");
	return 1;
  }
  if((int)TP->query_level() > 19 || secret_code == "aBcD") command(str, TP);
  else if(str == "n")  call_other(TP, "go_north");
  else if(str == "s")  call_other(TP, "go_south");
  else if(str == "e")  call_other(TP, "go_east");
  else if(str == "w")  call_other(TP, "go_west");
  else if(str == "u")  call_other(TP, "go_up");
  else if(str == "d")  call_other(TP, "go_down");
  else if(str == "ne")  call_other(TP, "go_northeast");
  else if(str == "nw")  call_other(TP, "go_northwest");
  else if(str == "se")  call_other(TP, "go_southeast");
  else if(str == "sw")  call_other(TP, "go_southwest");
  else write("Invalid Command.\n");
  return 1;
}

int main(string str, string secret_code) {
  string path, rest;
  int cont;
  rest = str;

  if(!str){
	write("Please use 'dash <dir1,dir2,etc.>'.\n");
	return 1;
  }

  write(HIW+"Dashing: "+str+"."+NORM+"\n");

  for(cont=0; cont<5; cont++){
	if(sscanf(rest, "%s,%s", path, rest)==2){
		cmd_check(path, secret_code);
	}
	else {
		cmd_check(rest, secret_code);
		write(HIW+"Done."+NORM+"\n");
		return 1;
	}
  }
  return 1;
}

