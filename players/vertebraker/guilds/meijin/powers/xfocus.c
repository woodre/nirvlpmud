#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 125
#define RANK 20
#define SKILL_NAME "focus"

/* Ok for testing purposes, may get rm'd or moded. -Bp 
    2091 Jul 21 21:05 xfocus.c     */
/***********************************************/
/* focus guarentees a critical hit in the next */
/* round of combat.  The amount of critical    */
/* damage is dependent on the critical skill.  */
/* Focus costs 125 EPs plus the cost of the EP */
/* cost of the critical.                       */
/***********************************************/

void help() {
  write("\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("     Skill  : Focus \n");
  write("     Syntax : xfocus\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Focus your thoughts and movements to make a more\n");
  write("         effective attack against your enemy.\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main() {
  object obj;
  int x;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(GOB->query_skill_variable("focus_delay")) {
	write("You are not able to focus again yet.\n");
	return 1;
  }
  if(!TP->query_attack()) {
	write("You must be in combat.\n");
	return 1;
  }
  if(TP->query_attack()->is_player()) {
	write("This is not possible against other players.\n");
	return 1;
  }
  if(!TP->query_weapon()) {
	write("You must be wielding a weapon to do this.\n");
	return 1;
  }
  if(GOB->query_off_wield()) {
	write("You cannot do this while you are offwielding.\n");
	return 1;
  }
  write(PRE+"You "+HIB+"focus"+NORM+" your movements.  Your weapon becomes an\n");
  write(PRE+"extension of your body.  You attack with incredible precision!\n");
  say(ME+" attacks with incredible precision!\n");
  GOB->set_skill_variable("focus", 1);
  GOB->focus_delay_start();
  GOB->add_endurance(-COST);
  return 1;
}

