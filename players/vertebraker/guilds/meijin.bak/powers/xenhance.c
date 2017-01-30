#include "/players/pavlik/guild/defs.h"
#define COST 800
#define RANK 50
#define SKILL_NAME "enhance"

/* Ok, -Bp 2226 Jul 21 20:53 xenhance.c */
/*****/
/* increase a weapons wc by 1 */
/*****/

void help() {
  write("\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("     Skill  : Enhance \n");
  write("     Syntax : xenhance <weapon>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Use your increasing knowledge in arms to enhance\n");
  write("         the effectiveness of a weapon.\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main(string str) {
  object wep;
  int wc;
  string type;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }

  wep = present(str, TP);

  if(!wep) {
	write("You don't have a "+str+".\n");
	return 1;
  }
  if(!(wc = (int)wep->weapon_class())) {
	write("You cannot enhance this.\n");
	return 1;
  }
  if(wc > (int)GOB->query_guild_skill(SKILL_NAME) / 4) {
	write("You are not skilled enough to enhance this weapon.\n");
	return 1;
  }

  type = (string)wep->query_type();

  if(GOB->query_guild_skill(type) < 50) {
	write("You are not skilled enough with the "+type+" to try this.\n");
	return 1;
  }
  if(present("xenhance", wep)) {
	write(capitalize(str)+" has already been enhanced.\n");
	return 1;
  }
  if(wep->query_wielded()) {
	write("You must unwield the weapon first.\n");
	return 1;
  }

  write(PRE+"After much studying and dedication to the art of weaponary,\n");
  write(PRE+"You are able to "+HIB+"enhance"+NORM+" this weapon's capabilities.\n");

  if(random((int)GOB->query_guild_skill(SKILL_NAME)) <= 10) {
	write(PRE+"You misjudge the weapon and it "+HIR+"breaks!"+NORM+"\n");
	say(ME+" accidently breaks "+POS+" weapon.\n");
	wep->weapon_breaks();
	return 1;
  }

  wep->set_class((int)wep->weapon_class() + 1);
  move_object(clone_object("players/pavlik/guild/obj/xenhance"), wep);
  GOB->add_endurance(-COST);
  return 1;
}

