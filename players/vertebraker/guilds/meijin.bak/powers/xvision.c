#include "/players/pavlik/guild/defs.h"
#define COST 2
#define RANK 10
#define SKILL_NAME "nightvision"

/****************************************************/
/* allows players to see in the dark.  this uses    */
/* set_light, which is unfortunate because it       */
/* allows everyone else in the room to see as well. */
/****************************************************/

void help() {
  write("\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("     Skill  : Nightvision \n");
  write("     Syntax : xvision\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         The nightvision skill allows you to see where\n");
  write("         there is no light.  Using nightvision will slowly\n");
  write("         drain your endurance.\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main() {
  int vis;
  if(!GOB->query_guild_skill(SKILL_NAME)) return 0;

  vis = (int)GOB->query_skill_variable("nightvision");
  if(vis) {
	write(PRE+"You are no longer using night vision.\n");
	GOB->night_vision_stop();
	return 1;
  }
  write(PRE+"You focus your senses and your vision seems much sharper.\n");
  GOB->night_vision_start();
  return 1;
}

