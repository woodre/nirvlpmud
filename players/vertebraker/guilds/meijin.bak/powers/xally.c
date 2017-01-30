#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xally"

/*
 * Ally idea from Beck@Nirvana (Power Rangers Guild).
 * Leeched Shamlessly by Pavlik.
 */

void help() {
  write("\n");
  write("  [(>-------------------------------------------------------------<)]\n");
  write("     Skill  : Ally \n");
  write("     Syntax : xally <player>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : 30\n");
  write("     Description : \n");
  write("         If you are high enough guild rank and you determine\n");
  write("         that another player is worthy to be an ally to the\n");
  write("         Meijin you can grant 'Ally Status' upon that person.\n");
  write("         Allies will be able to communicate with members of\n");
  write("         the guild and also use some of the most basic guild\n");
  write("         functions.\n");
  write("\n");
  write("         A player can have Ally Status revoked at any time by\n");
  write("         any member of the guild.  Use 'xally <name> REVOKE'\n");
  write("         to remove a players ally status.\n");
  write("  [(>-------------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  string who, tmp;
  object ob, obj;
  int flag;

  if(!str) {
	write("Make an ally of who?\n");
	return 1;
  }

  if(sscanf(str, "%s %s", who, tmp) == 2) {
	if(tmp != "REVOKE") {
		write("You must use 'xally <name> REVOKE' to revoke an Ally.\n");
		return 1;
	}
	flag = 1;
  }
  else {
	who = str;
  }

  if(TP->query_guild_rank() < 30 && !flag) return 0;

  obj = find_player(who);

  if(!obj || !present(obj, environment(TP))) {
	write(capitalize(who)+" must be present for this.\n");
	return 1;
  }

  if(obj->query_level() >= 20 && TP->query_level() < 20) {
	write("Only wizards can make ally wizards.\n");
	return 1;
  }

  if((string)obj->query_guild_name() == "meijin") {
	write(capitalize(who)+" is a Meijin.  This does not apply.\n");
	return 1;
  }

  if(present(ALLYID, obj)) {
	if(flag) {
		write("You "+HIB+"revoke"+NORM+" "+capitalize(who)+"'s allied status.\n");
		tell_object(obj, ME+" has "+HIB+"revoked"+NORM+" you allied status with the Meijin.\n");
		DAEMON->guild_broadcast(HIB+"<"+HIW+"()"+HIB+">"+NORM+" "+ME+" has revoked "+
		capitalize(who)+"'s allied status!\n");
		destruct(present(ALLYID, obj));
		return 1;
	}
	write(capitalize(who)+" is already an ally.\n");
	return 1;
  }

  write("You make "+capitalize(who)+" an ally of the Meijin.\n");
  tell_object(obj, ME+" has made you an "+HIM+"ally"+NORM+" of the Meijin.\n");
  ob = clone_object("players/pavlik/guild/ally_gob");
  move_object(ob, obj);
  DAEMON->guild_broadcast(HIB+"<"+HIW+"()"+HIB+">"+NORM+" "+ME+" has made "+
  capitalize(who)+" an ally of the guild!\n");
  ob->guild_init(1);
  return 1;
}

