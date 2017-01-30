#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xt"

/**************************************/
/* basic guild communication commands */
/**************************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xt \n");
  write("     Syntax : xt <msg> \n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Communicate with all guild members.  Command \n");
  write("         options include: \n");
  write("              /off - muffle the channel.\n");
  write("              /on  - unmuffle the channel.\n");
  write("              :    - emote a message.\n");
  write("              ;    - xemote a message.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return "xt"; }

int main(string str) {
  if(!str) {
	write("Tell guild members what?\n");
	return 1;
  }
  if(lower_case(str) == "/on") {
	write("You are now listening to the guild channel.\n");
	GOB->set_guild_channel(1);
	return 1;
  }
  if(lower_case(str) == "/off") {
	write("You are no longer listening to the guild channel.\n");
	GOB->set_guild_channel(0);
	return 1;
  }
  if(!GOB->query_guild_channel()) {
	write("You are not listening to the guild channel.\n");
	return 1;
  }
  switch (extract(str, 0, 0)) {
	case ":" :
	   DAEMON->guild_broadcast(HIB+"<()> "+NORM+HIW+capitalize((string)TP->query_name())+
	   " "+extract(str, 1, strlen(str))+NORM+"\n");
	   break;
	case ";" :
	   DAEMON->guild_broadcast(HIB+"<()> "+HIW+extract(str, 1, strlen(str))+
	   HIB+" ("+capitalize((string)TP->query_name())+")\n"+NORM);
	   break;
	case "!" :
	   DAEMON->guild_broadcast(HIW+"<("+HIB+capitalize((string)TP->query_name())+
	   NORM+HIW+")>:"+NORM+" "+extract(str, 1, strlen(str))+"\n", 1);
	   break;
	default :
	   DAEMON->guild_broadcast(HIB+"<("+HIW+capitalize((string)TP->query_name())+
	   NORM+HIB+")>:"+NORM+" "+str+"\n");
	   break;
  }
  return 1;
}

