#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 60
#define SKILL_NAME "parry"

/**************************************************************/
/* This skill allows the player to use the offwielded weapon  */
/* to parry attacks.  The offwielded weapon class is reduced  */
/* by 1/2 and the player can "block" opponents attacks.       */
/* The code uses the paladin shield_block functions in        */
/* living.c  All the important code for parry is located in:  */
/* /players/pavlik/guild/combat.h                             */
/**************************************************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Parry \n");
  write("     Syntax : xparry\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Parry allows you to block some of your enemy's\n");
  write("         attack.  You offensive capabilities are reduced\n");
  write("         when you are parrying.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main() {
  object obj;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_skill_variable("parry")) {
	write(PRE+"You will no longer parry your enemy's attacks.\n");
	GOB->remove_skill_variable("parry");
	return 1;
  }

  if(!GOB->query_off_wield()) {
	write("You must be offwielding first.\n");
	return 1;
  }

  write(PRE+"You will now attempt to parry your enemy's attacks.\n");
  GOB->set_skill_variable("parry", 2);
  return 1;
}

