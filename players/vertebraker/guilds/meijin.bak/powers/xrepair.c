#include "/players/pavlik/guild/defs.h"
#define COST 250
#define MONEY_COST 500
#define RANK 40
#define SKILL_NAME "repair"

/*
 * Cost made to typical 500 coins. -Bp 
 * 2201 Jul 21 21:44 xrepair.c
 */
/*****************************************************/
/* Gives the player a chance to fix a broken weapon. */
/* A failed attempt will destroy the weapon.         */
/*****************************************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Repair \n");
  write("     Syntax : xrepair <target>\n");
  write("     Cost   : "+COST+" ep + "+MONEY_COST+" gp\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Use your expertise in arms to repair a broken\n");
  write("         weapon.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  object obj;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(!str) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(TP->query_money() < MONEY_COST) {
	write("You are too poor.\n");
	return 1;
  }

  obj = present(str, TP);

  if(!obj) {
	write("You do not have a "+str+".\n");
	return 1;
  }
  if(!obj->weapon_class()) {
	write("You can only repair weapons.\n");
	return 1;
  }
  if(!obj->query_broke()) {
	write("The "+str+" isn't broken.\n");
	return 1;
  }
  if(obj->query_wielded()) {
	write("You must unwield the weapon first.\n");
	return 1;
  }
  if(random(100) < (int)obj->weapon_class() * 3) {
	write(PRE+"You make a wrong move and destory the weapon!\n");
	say(ME+" accidently destroys a "+str+".\n");
	TP->add_weight(-((int)obj->query_weight()));
	destruct(obj);
	GOB->add_endurance(-COST);
	return 1;
  }

  obj->fix_weapon();

  write(PRE+"Thanks to your expertise with weapons, you are able to quickly "+HIB+"repair"+NORM+"\n");
  write(PRE+"the "+str+".  "+(string)obj->short()+" feels good as new.\n");
  say(ME+" quickly repairs a "+str+".\n");

  GOB->add_endurance(-COST);
  TP->add_money(-MONEY_COST);
  return 1;
}

