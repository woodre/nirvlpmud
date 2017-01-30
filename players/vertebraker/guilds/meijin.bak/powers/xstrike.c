#include "/players/pavlik/guild/defs.h"
#define COST ((int)GOB->query_stat("prowess")/4 + (int)GOB->query_skill("strike")/3) * 7
#define RANK 50
#define SKILL_NAME "strike"

/* appears ok, Bp Jul 23 22:09 xstrike.c    */
/****************************************************/
/* this is more/less the guild equivalent to Sonic. */
/* hit_player: prow_stat/8 + random(strike_stat/3)  */
/* ep cost   : (prow_stat/4 + strike_stat/3) * 7    */
/****************************************************/

void help() {
  write("\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("     Skill  : Strike \n");
  write("     Syntax : xstrike\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Strike your enemy with amazing accuracy and force.\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main() {
  object weap, obj;
  string *weap_mess;
  int dmg;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(!TP->query_attack()) {
	write("You must be fighting first.\n");
	return 1;
  }

  obj = (object)TP->query_attack();

  if(!obj->query_npc()) {
	write("You cannot use this skill on other players.\n");
	return 1;
  }

  weap = (object)TP->query_weapon();

  if(!weap) {
	write("You must be wielding a weapon to do this.\n");
	return 1;
  }

  write(PRE+"You leap forward and "+HIB+"STRIKE"+NORM+" with "+HIW+"amazing accuracy!\n"+NORM);
  say(ME+" leaps forward and attacks with "+HIW+"amazing accuracy!\n"+NORM);
  dmg = (int)GOB->query_guild_stat("prowess") / 8;			/* 12 */
  dmg += random((int)GOB->query_guild_skill(SKILL_NAME) / 3);		/* random(33) */
  weap_mess = (mixed)weap->query_message_hit(dmg);
  write("You "+weap_mess[1]+" "+IT+weap_mess[0]+".\n");
  say(ME+" "+weap_mess[1]+" "+IT+weap_mess[0]+".\n");
  obj->hit_player(dmg);
  GOB->add_endurance(-COST);
  return 1;
}

