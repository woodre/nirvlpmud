#include "/players/pavlik/guild/defs.h"
#define COST 100
#define RANK 60
#define SKILL_NAME "rage"

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Rage \n");
  write("     Syntax : xrage\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("        Go into a blood thirsty rage!  This increases\n");
  write("        your attack incredibly, however you often lose\n");
  write("        control of your actions during a blood rage.\n");
  write("        If you are raging and want to stop, type 'xrage'.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main() {
  object obj;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(GOB->query_skill_variable("xrage_delay")) {
	write("You cannot rage again yet.\n");
	return 1;
  }
  if(GOB->query_skill_variable("xrage")) {
	write("You are already raging!\n");
	return 1;
  }
  if(!TP->query_attack()) {
	write("You must be fighting first.\n");
	return 1;
  }
  if(!TP->query_weapon()) {
	write("You must be wielding a weapon to do this.\n");
	return 1;
  }

  obj = (object)TP->query_attack();

  if(!obj->query_npc()) {
	write("You cannot do this to players.\n");
	return 1;
  }

  write(PRE+"The warrior's spirit inside you hungers for battle!\n");
  write(PRE+"Your work yourself into a "+HIR+"killing "+HIB+"rage"+NORM+"!\n");
  say(ME+" works "+POS+"self into a killing rage!\n");
  GOB->set_skill_variable("xrage", 1);
  GOB->add_endurance(-COST);

  return 1;
}

