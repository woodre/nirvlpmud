#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 140
#define RANK 20
#define SKILL_NAME "appraise"

/********************************************/
/* Get some basic info on a weapon or armor */
/********************************************/
/* Approved, Bp Jul 16 20:45 appraise.c */

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Appraise \n");
  write("     Syntax : appraise <object>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Determine the value of a weapon or armor.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  object obj;
  int wc, ac;
  string type, name;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(!str) {
	write("Appraise what?\n");
	return 1;
  }
  obj = present(str, TP);
  if(!obj) obj = present(str, environment(TP));

  if(!obj) {
	write("What?\n");
	return 1;
  }
  if(!obj->weapon_class() && !obj->armor_class()) {
	write("You cannot discern anything special about the "+str+".\n");
	return 1;
  }
  name = (string)obj->query_name();
  if(!name) name = capitalize(str);
  write(PRE+"You "+HIB+"appraise"+NORM+" "+name+" with the critical eye of a master.\n");
  say(ME+" "+HIB+"appraises"+NORM+" "+name+" with the critical eye of a master.\n");

  wc = (int)obj->weapon_class();
  if(wc > 20) write(PRE+"This is a powerful weapon of "+HIY+"god-like"+NORM+" power.\n");
  else if(wc >= 19) write(PRE+"This is a powerful weapon of "+HIM+"superior"+NORM+" quality.\n");
  else if(wc >= 18) write(PRE+"This is a weapon of "+HIW+"superb"+NORM+" quality.\n");
  else if(wc >= 15) write(PRE+"This is a weapon of quality.\n");
  else if(wc >= 12) write(PRE+"This is a weapon of average quality.\n");
  else if(wc >= 8) write(PRE+"This is a weapon of "+RED+"poor"+NORM+" quality.\n");
  else if(wc >= 1) write(PRE+"This is a "+RED+"pathetic"+NORM+" weapon.\n");

  ac = (int)obj->armor_class();
  type = (string)obj->query_type();
  if(ac >= 5)
    if(type == "armor") write(PRE+"This is armor of "+HIY+"god-like"+NORM+" power.\n");
    else write(PRE+"This armor is illegal and you should be shot.\n");
  else if(ac >= 4)
    if(type == "armor") write(PRE+"This is armor of "+HIM+"superior"+NORM+" quality.\n");
    else write(PRE+"This armor is illegal and you should be shot.\n");
  else if(ac >= 3)
    if(type == "armor") write(PRE+"This is armor of quality.\n");
    else write(PRE+"This is armor of "+HIY+"god-like"+NORM+" power!\n");
  else if(ac >= 2)
    if(type == "armor") write(PRE+"This is armor of average quality.\n");
    else write(PRE+"This is armor of "+HIM+"superior"+NORM+" quality.\n");
  else if(ac >= 1)
    if(type == "armor") write(PRE+"This is armor of "+HIR+"poor"+NORM+" quality.\n");
    else write(PRE+"This is armor of average quality.\n");

  GOB->add_endurance(-COST);
  return 1;
}

