#include "/players/pavlik/guild/defs.h"
#define COST 560
#define RANK 60
#define SKILL_NAME "cripple"

/* Approved. -Bp Jul 21 20:49 xcripple.c */
/*****/
/* this skill reduces the targets wc and ac by a small amount.  the */
/* target will recover after a short period of time.  the target    */
/* recovers quicker if the player leaves.                           */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Cripple \n");
  write("     Syntax : xcripple\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         This is an attack of such power that it reduces\n");
  write("         you enemy's ability to fight back.  A crippled\n");
  write("         opponent becomes slower and is easier to hit.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main() {
  object ob, obj;
  int num, num_ac, num_wc;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
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
  if(obj->query_level() >= 25) {
	write(IT+" cannot be crippled.\n");
	return 1;
  }
  if(present("xcripple", obj)) {
	write(IT+" has already been crippled.\n");
	return 1;
  }

  write(PRE+"You summon all your strength as you prepare to "+HIB+"cripple "+NORM+IT+".\n");
  write(PRE+"You unleash all your "+HIR+"fury"+NORM+" in one single blow!\n");

  /*** determine the total amount of points to subtract ***/
  num = (int)GOB->query_guild_skill(SKILL_NAME) + (int)GOB->query_guild_stat("strength");
  num = random(num) / 20;

  if(!random(num)) {
	write("\n"+PRE+"You "+HIW+"misjudge"+NORM+" your swing and "+HIW+"miss completely!"+NORM+"\n\n");
	say(ME+" takes a big swing at "+IT+" and misses!\n");
	GOB->add_endurance(-(COST / 2));
	return 1;
  }

  num_wc = (2 * num) / 3;
  num_ac = num / 3;

  /* make sure num does not exceed 25% of org_wc or 33% of org_ac */
  if((int)obj->query_wc() / 4 > num_wc) num_wc = (int)obj->query_wc() / 4;
  if((int)obj->query_ac() / 3 > num_ac) num_ac = (int)obj->query_ac() / 3;

  write(PRE+"Your "+HIW+"massive"+NORM+" attack "+HIB+"cripples"+NORM+" "+IT+"'s body!\n");
  write(PRE+IT+" staggers under the force of your attack!\n");
  write(ME+"'s massive attack CRIPPLES "+IT+"!\n");
  obj->set_ac((int)obj->query_ac() - num);
  obj->set_wc((int)obj->query_wc() - num);
  ob = clone_object("players/pavlik/guild/obj/xcripple");
  ob->set_num_wc(num_wc);
  ob->set_num_ac(num_ac);
  ob->set_owner(TP);
  ob->set_target(obj);
  move_object(ob, obj);
  GOB->add_endurance(-COST);
  return 1;
}

