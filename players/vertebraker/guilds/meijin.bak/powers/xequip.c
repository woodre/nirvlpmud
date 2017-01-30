#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xequip"

/*****/
/* Ok Bp 2081 Jul 21 20:54 xequip.c  */
/* display what the player is wearing and wielding */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xequip \n");
  write("     Syntax : xequip \n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         This command will display the equipment you\n");
  write("         wielding and wearing.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
query_skill_name() { return SKILL_NAME; }

object find_armor_type(string str) {
  object *ob;
  int i;

  ob = all_inventory(TP);
  for(i=0; i<sizeof(ob); i++) {
    if((string)ob[i]->query_type() == str && (int)ob[i]->query_worn())
      return ob[i];
  }
  return 0;
}

int main() {
  object ob, obj;
  int i;

  write(HIB+
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);

  write(PRE+"You are using:\n");

  write("\t"+pad("As a weapon", 15)+":\t");
  if(!TP->query_weapon()) write("nothing.\n");
  else write((string)TP->query_weapon()->short()+"\n");

  if(GOB->query_skill("offwield")) {
	write("\t"+pad("Offwielded", 15)+":\t");
	if(GOB->query_off_wield()) write((string)GOB->query_off_wield()->short()+" (wielded)\n");
	else write("nothing.\n");
  }

  write("\n");
  write(PRE+"You are wearing:\n");
  write("\t"+pad("On head", 15)+":\t");
	obj = find_armor_type("helmet");
	if(!obj) write("nothing.\n");
	else write((string)obj->short()+"\n");
  write("\t"+pad("On body", 15)+":\t");
	obj = find_armor_type("armor");
	if(!obj) write("nothing.\n");
	else write((string)obj->short()+"\n");
  write("\t"+pad("On feet", 15)+":\t");
	obj = find_armor_type("boots");
	if(!obj) write("nothing.\n");
	else write((string)obj->short()+"\n");

  write("\n");
  write(HIB+
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);

  return 1;
}

