#include "/players/pavlik/guild/defs.h"
#define ATT capitalize((string)ob[i]->query_name())
#define COST 30
#define RANK 40
#define SKILL_NAME "bloodstorm"

/* looks OK, -Bp Jul 23 22:06 xstorm.c  */
/******************************************************/
/* This is the classic area_attack skill.  This skill */
/* allows the player to have several "weapon hits" on */
/* each monster in the room.  The cost depends on the */
/* weapon_class of the weapon being used and how many */
/* attacks the player gets.                           */
/* hit_player: random(wc) * attacks                   */
/* ep cost   : (wc * attacks) * 7                     */
/******************************************************/

void help() {
  write("\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("     Skill  : Blood Storm \n");
  write("     Syntax : xstorm\n");
  write("     Cost   : ? "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         This powerful ability allows you to attack every\n");
  write("         enemy within the room.\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

int main() {
  object wep;
  object *ob;
  int attacks, damage, cost;
  int target_dmg, dmg;
  int i, x;
  string *msgs;
  string my_msg, room_msg;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(!(wep = (object)TP->query_weapon())) {
	write("You must be wielding a weapon to do this.\n");
	return 1;
  }

  attacks = (int)GOB->query_guild_skill(SKILL_NAME) / 25;
  if(attacks > 3) attacks = 3;
  damage = (int)wep->weapon_class();
  cost = (damage * attacks) * 7;

  write(PRE+"You begin to turn the deadly steps of the "+HIR+"Blood Storm"+NORM+".\n");
  write(PRE+"You spin faster and faster, twirling your weapon in an amazing\n");
  write(PRE+"diplay of "+HIW+"skill"+NORM+" and "+HIW+"mastery"+NORM+".\n");
  write(PRE+"At the pinnacle of the dance "+HIW+"you ATTACK!"+NORM+"\n");
  say(ME+" begins to turn a slow deadly dance.  "+POS+" weapon twirls in\n");
  say("an amazing display of skill and mastery.\n");
  say("At the pinnacle of the dance, "+ME+" attacks!\n");

  ob = all_inventory(environment(TP));
  for(i=0; i<sizeof(ob); i++) {
	if(GOB->query_endurance() < cost) {
		write(PRED+"You have grown too tired to continue.\n");
		return 1;
	}
	if(!living(ob[i]) || ob[i] == TP || !ob[i]->query_npc()) continue;
	target_dmg = 0;
	my_msg = "";
	room_msg = "";
	for(x=0; x<attacks; x++) {
		dmg = random(damage);
		target_dmg += dmg;
		msgs = (mixed)wep->query_message_hit(dmg);
		my_msg += PRED+"You "+msgs[1]+" "+ATT+msgs[0]+".\n";
		room_msg += ME+" "+msgs[1]+" "+ATT+msgs[0]+".\n";
	}
	ob[i]->hit_player(target_dmg);
	write(my_msg);
	say(room_msg);
	GOB->add_endurance(-cost);
	if(ob[i]) ob[i]->attacked_by(TP);
  }
  return 1;
}

