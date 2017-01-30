#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 20
#define RANK 1000
#define SKILL_NAME "meditate"

/****************************************************/
/* allows players to see in the dark.  this uses    */
/* set_light, which is unfortunate because it       */
/* allows everyone else in the room to see as well. */
/****************************************************/

void help() {
  write("\n");
  write("  [(>---------------------------------------------------------<)]\n");
  write("     Skill  : Meditation \n");
  write("     Syntax : xmeditate\n");
  write("     Cost   : special\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("	Meditation allows you to recover Endurane at twice\n");
  write("	the normal rate.  When meditating you cannot recover\n");
  write("	any hit points or spell points, and your hit points\n");
  write("	will suffer if move around (leave the room).\n");
  write("\n");
  write("	It costs 20 spell points to start AND stop meditating.\n");
  write("  [(>---------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main() {
  int med;

  if(!GOB->query_guild_skill(SKILL_NAME)) return 0;

  med = (int)GOB->query_skill_variable("meditate");

  if(med) {
	write(PRE+"You are no longer "+HIW+"meditating"+NORM+".\n");
	say(ME+" blinks and appears to wake as if from a dream.\n");
	GOB->remove_skill_variable("meditate");
	TP->add_spell_point(-20);
	return 1;
  }

  write("\n"+PRE+"You relax your mind and body and begin to "+HIY+"meditate"+NORM+".\n\n");
  TP->add_spell_point(-20);
  GOB->set_skill_variable("meditate", 1);
  GOB->set_skill_variable("meditate_env", environment(TP));
  GOB->set_skill_variable("meditate_hp", TP->query_hp());
  GOB->set_skill_variable("meditate_sp", TP->query_sp());
  return 1;
}

