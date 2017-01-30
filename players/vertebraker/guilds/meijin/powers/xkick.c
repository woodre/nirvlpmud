#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST ((int)GOB->query_stat("strength") / 5 + (int)GOB->query_skill("kick") / 4) * 7
#define RANK 10
#define SKILL_NAME "kick"

/* Ok, may need to adjust the *7. -Bp 2102 Jul 21 21:13 xkick.c */
/************************************************************/
/* basic attack skill.                                      */
/* hit_player: (strength_stat / 10) + random(kick_stat / 4) */
/* ep cost   : ((strength_stat / 5) + (kick_stat / 4)) * 7  */
/************************************************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Kick \n");
  write("     Syntax : xkick <target>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Deliver a fierce kick to your enemy.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main(string str) {
  object obj;
  int dmg;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(str == "cost") {
	write("Cost is 10 + (Kick/6) : \n");
	write("  10 + ( "+(int)GOB->query_skill(SKILL_NAME)+" / 6 )\n");
	return 1;
  }

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }

  if(!str) obj = (object)TP->query_attack();
  else obj = present(str, environment(TP));
  if(!obj) return 0;

  if(!random(2)) {
    write(PRE+"You leap into the air and "+HIB+"kick"+NORM+" "+IT+" square in the chest!\n");
    say(ME+" leaps into the air and kicks "+IT+" square in the chest!\n");
  }
  else {
    write(PRE+"You backflip and "+HIB+"kick"+NORM+" "+IT+" soundly on the chin!\n");
    say(ME+" backflips and kicks "+IT+" soundly on the chin!\n");
  }

  dmg = (int)GOB->query_guild_stat("strength") / 10;
  dmg += random( (int)GOB->query_guild_skill(SKILL_NAME) / 4 );

  obj->hit_plauer(dmg);
  if(TP->query_level() > 20) write("xkick damage is: "+dmg+"\n");
  GOB->add_endurance(-(COST));
  return 1;
}

