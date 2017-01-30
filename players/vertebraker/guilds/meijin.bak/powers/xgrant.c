#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 1000
#define SKILL_NAME "xstat"

/* wizard command */

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xGrant \n");
  write("     Syntax : xgrant <player> <var> <#>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : wizard\n");
  write("     Description : \n");
  write("        This command allows a wizard to modify someones\n");
  write("        guild information.  The variables that can be\n");
  write("        modified with xgrant are:\n");
  write("               rank        exp          donation\n");
  write("               end         practice     newskill\n");
  write("               <stat>      <skill>\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str){
  object obj, gob;
  string who, what;
  int amt;

  if(TP->query_level() < 20) return 0;

  if(!sscanf(str, "%s %s %d", who, what, amt) == 3) {
	write("Use: xgrant <player> <var> <#>\n");
	return 1;
  }
  if(!(obj = find_player(who))) {
	write(capitalize(str)+" could not be found.\n");
	return 1;
  }
  if(!(gob = present(GUILDID, obj))) {
	write(capitalize(str)+" does not have a guild object.\n");
	return 1;
  }
  if(what == "rank") {
	write("You give "+capitalize(who)+" "+amt+" guild ranks.\n");
	tell_object(obj, ME+" gives you "+amt+" guild ranks.\n");
	obj->add_guild_rank(amt);
	return 1;
  }
  if(what == "exp") {
	write("You give "+capitalize(who)+" "+amt+" guild experience.\n");
	tell_object(obj, ME+" gives you "+amt+" guild experience.\n");
	obj->add_guild_exp(amt);
	return 1;
  }
  if(what == "don" || what == "donation") {
	write("You give "+capitalize(who)+" "+amt+" donation points.\n");
	tell_object(obj, ME+" gives you "+amt+" donation points.\n");
	gob->add_donations(amt);
	return 1;
  }
  if(what == "end") {
	write("You give "+capitalize(who)+" "+amt+" endurance points.\n");
	tell_object(obj, ME+" gives you "+amt+" endurance points.\n");
	gob->add_endurance(amt);
	return 1;
  }
  if(what == "prac" || what == "practice") {
	write("You give "+capitalize(who)+" "+amt+" practices.\n");
	tell_object(obj, ME+" gives you "+amt+" practices.\n");
	gob->add_practices(amt);
	return 1;
  }
  if(what == "new" || what == "newskill") {
	write("You give "+capitalize(who)+" "+amt+" new skill points.\n");
	tell_object(obj, ME+" gives you "+amt+" new skill points.\n");
	gob->add_new_skills(amt);
	return 1;
  }
  if(gob->query_stat(what)) {
	write("You give "+capitalize(who)+" "+amt+"% "+what+" points.\n");
	tell_object(obj, ME+" gives you "+amt+"% "+what+" points.\n");
	gob->add_guild_stat(what, amt);
	return 1;
  }
  if(gob->query_skill(what)) {
	write("You give "+capitalize(who)+" "+amt+"% "+what+" points.\n");
	tell_object(obj, ME+" gives you "+amt+"% "+what+" points.\n");
	gob->add_guild_skill(what, amt);
	return 1;
  }
  if((string)TP->query_real_name() == "pavlik") {
	write("You give "+capitalize(who)+" "+amt+"% "+what+" points.\n");
	tell_object(obj, ME+" gives you "+amt+"% "+what+" points.\n");
	gob->add_guild_skill(what, amt);
	return 1;
  }
  write(capitalize(what)+" is not a valid xgrant argument.\n");
  return 1;
}

