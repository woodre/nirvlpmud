#include "/players/pavlik/guild/defs.h"
#define COST (5 * dmg / 2) * 7
#define RANK 30
#define SKILL_NAME "finish"

/* Ok, change 3/2 to 5/2 to comply with /doc/build/RULES/guild_spells
   2814 Jul 21 21:02 xfinish.c */
/*****/
/* the purpose of this skill is to deliver a 'mortal blow' to   */
/* the target.  checks are made to be sure that the targets     */
/* hit points are low enough (below 45) so that the damage max  */
/* is not exceeded.  the code uses heal_self and hit_player to  */
/* make sure that the xstrike call does indeed kill the inteded */
/* target.  please note that the damage possible check is the   */
/* important part of making sure this skill is legal.           */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Finish \n");
  write("     Syntax : xfinish\n");
  write("     Cost   : ? ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         This skill allows you to finish off an enemy\n");
  write("         with a single blow.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main() {
  object obj;
  int msg, dmg;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(!TP->query_attack()) return 0;
  obj = (object)TP->query_attack();

  if(!obj->query_npc()) {
	write("You cannot do this to another player.\n");
	return 1;
  }

  dmg = (int)GOB->query_guild_skill(SKILL_NAME) / 2;
  if(dmg > 45) dmg = 45;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }

  /*
   * This is the important part of the code.  Here we make sure that the
   * target's HPs are LOWER than the amount of damage we are allowed to do.
   * Cannot be used against monsters level 25 or higher!
   */
  if(obj->query_hp() > dmg || obj->query_level() >= 25) {
	write(IT+" cannot be finished that easily.\n");
	return 1;
  }

  msg = random(3);
  if(msg == 0) write(PRE+"You determine that "+IT+"'s time here is "+HIB+"FINISHED!"+NORM+"\n");
  if(msg == 1) write(PRE+"You decide to put an "+HIB+"END"+NORM+" to "+IT+"'s miserable existence!\n");
  if(msg == 2) write(PRE+IT+" forfeits its life to your "+HIB+"superior"+NORM+" skills!\n");
  write(PRE+"You "+HIW+"decimate "+NORM+IT+"'s defenses and deliver the "+HIB+"killing blow!"+NORM+"\n");
  say(ME+" decimates "+IT+"'s defenses and delivers the killing blow!\n");

  /* always hit for maximum amount allowed since we are trying to finish the target off */
  /* code checks above makes sure we are not doing damage above our limitaions */
  /* REMEMBER - the purpose of this spell is to KILL the target */
  obj->heal_self(-((int)obj->query_hp()));
  obj->hit_player(50);
  GOB->add_endurance(-COST);

  return 1;
}

