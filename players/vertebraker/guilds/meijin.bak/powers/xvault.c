#include "/players/pavlik/guild/defs.h"
#define COST 100
#define RANK 1000
#define SKILL_NAME "vault"

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Vault \n");
  write("     Syntax : xvault <list> <get> <put>\n");
  write("     Cost   : special\n");
  write("     Rank   : special\n");
  write("     Description : \n");
  write("         Once a Meijin has gained this ability he or she\n");
  write("         can access the Guild Vault over great distances.\n");
  write("         Certain areas may inhibit this special power.\n");
  write("\n");
  write("         Rank  1: xvault list     (10 Ep)\n");
  write("         Rank 10: xvault put     (100 Ep)\n");
  write("         rank 21: xvault get     (100 Ep)\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  string cmd, what;
  object vault, here;
  object ob;
  int rank;

  if(!str) return 0;

  if(sscanf(str, "%s %s", cmd, what) != 2) {
	cmd = str;
  }

  if((string)environment(TP)->realm() == "NT" || (string)environment(TP)->realm() == "NM") {
	write("For some reason you cannot do that here.\n");
	return 1;
  }

  rank = (int)TP->query_guild_rank();

  if(cmd != "list" && cmd != "get" && cmd != "put") return 0;
  if((cmd == "list" && rank < 1) || (cmd == "put" && rank < 10) || (cmd == "get" && rank < 21)) return 0;

  if((cmd != "list" && (int)GOB->query_endurance() < 100) || (cmd == "list" && (int)GOB->query_endurance() < 10)) {
	write("You are too tired.\n");
	return 1;
  }

  here = environment(TP);
  move_object(TP, "players/pavlik/guild/room/vault");
  vault = present("vault", environment(TP));
  move_object(TP, here);

  if(!vault) {
	write("Error.  The Guild Vault cannot be located.\n");
	return 1;
  }
  if(cmd == "list") {
	call_other(vault, "list", what);
	GOB->add_endurance(-10);
	return 1;
  }
  if(cmd == "get") {
	call_other(vault, "withdraw", what);
	GOB->add_endurance(-100);
	return 1;
  }
  if(cmd == "put") {
	call_other(vault, "deposit", what);
	GOB->add_endurance(-100);
	return 1;
  }
}

