#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 40
#define SKILL_NAME "offwield"

#undef HAND
#undef OFFHAND
#define HAND GOB->query_handed(0)
#define OFFHAND GOB->query_handed(1)

/*****/
/* offwield allows the player to wield a second weapon.  all the */
/* damage and cost code is located at: ~/guild/combat.h          */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Offwield \n");
  write("     Syntax : offwield <weapon>\n");
  write("     Cost   : n/a\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Offwield allows you to wield a second weapon.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }
int query_trainable() { return 1; }

string creator(object obj) {
  string name, who, tmp;

  name = file_name(obj);
  if(sscanf(name, "players/%s/%s", who, tmp) == 2) return capitalize(who);
  else return "Unknown";
}

int main(string str) {
  object obj, offw;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(!str && !(offw=(object)GOB->query_off_wield())) {
	write("Offwield what?\n");
	return 1;
  }

  if(!str && offw) {
	write("You stop wielding "+offw->query_name()+" in your "+OFFHAND+" hand.\n");
	say(ME+" stops wielding "+offw->query_name()+" in "+POS+" "+OFFHAND+" hand.\n");
	GOB->set_off_wield(0);
	return 1;
  }

  obj = present(str, TP);

  if(!obj) {
	write("You don't have a "+str+".\n");
	return 1;
  }

  if(present("notweapon", TP)) {
	write("For some reason your are unable to wield this weapon.\n");
	return 1;
  }

  if(!obj->weapon_class()) return 0;

  if(obj == offw || obj == (object)TP->query_weapon()) {
	write("You already wield it!\n");
	return 1;
  }

  if(!obj->query_type()) {
	write("This weapon does not have its weapon_type set.  This is probably an\n");
	write("oversight of the weapon's creator ("+creator(obj)+").\n");
	return 1;
  }

  if(!GOB->query_skill(obj->query_type())) {
	write("You do not know how to offwield this type of weapon.\n");
	return 1;
  }

  if(offw && present(offw, TP)) {
	write("You stop wielding "+offw->query_name()+" in your "+OFFHAND+" hand.\n");
	say(ME+" stops wielding "+offw->query_name()+" in "+POS+" "+OFFHAND+" hand.\n");
	GOB->set_off_wield(0);
  }

  if(obj->query_weight() > (int)GOB->query_guild_stat("strength") / 8) {
	write("This weapon is too heavy for you to offwield.\n");
	return 1;
  }

  if(obj->weapon_class() > ((int)GOB->query_guild_skill(SKILL_NAME) / 10) + 
  ((int)GOB->query_guild_stat("dexterity") / 10)) {
	write("You are not skilled enough to offwield this weapon.\n");
	return 1;
  }

  write("You wield "+obj->query_name()+" in your "+OFFHAND+" hand.\n");
  say(ME+" wields "+obj->query_name()+" in "+POS+" "+OFFHAND+" hand.\n");
  GOB->set_off_wield(obj);
  return 1;
}
