#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 245
#define RANK 10
#define SKILL_NAME "consider"

/*****/
/* size up another living thing */
/*****/

/* Ok, Bp Jul 16 21:35 xconsider.c  */
void help() {
  write("\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("     Skill  : Consider \n");
  write("     Syntax : xconsider <target>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Determine how tough an opponent might be.\n");
  write("  [(>------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  object obj;
  int lvl, wc, ac, mhp, hlt;
  string lvl_str, wc_str, ac_str, mhp_str, hlt_str;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(!str && !TP->query_attack()) {
	write("Consider whom?\n");
	return 1;
  }
  if(!str) obj = (object)TP->query_attack();
  else obj = present(str, environment(TP));
  if(!obj) {
	write(capitalize(str)+" is not here.\n");
	return 1;
  }
  if(!living(obj)) {
	write("What?\n");
	return 1;
  }
  if(obj == TP) {
	write("You cannot consider yourself in this fashion.\n");
	return 1;
  }
  lvl = (int)obj->query_level();			/* level */
  if(!lvl) lvl_str = "Unknown";
  else if(lvl <= 5) lvl_str = "Poor";
  else if(lvl <= 10) lvl_str = "Moderate";
  else if(lvl <= 15) lvl_str = "Skilled";
  else if(lvl <= 18) lvl_str = "High";
  else if(lvl <= 21) lvl_str = "Exceptional";
  else lvl_str = "Superb";
  wc = (int)obj->query_wc();				/* weapon class */
  if(!wc) wc_str = "None";
  else if(wc <= 5) wc_str = "Extremely Poor";
  else if(wc <= 10) wc_str = "Poor";
  else if(wc <= 15) wc_str = "Moderate";
  else if(wc <= 18) wc_str = "High";
  else if(wc <= 21) wc_str = "Exceptional";
  else if(wc <= 29) wc_str = "Superb";
  else wc_str = "Deadly";
  ac = (int)obj->query_ac();				/* armor class */
  if(!ac) ac_str = "None";
  else if(ac <= 2) ac_str = "Poor";
  else if(ac <= 5) ac_str = "Moderate";
  else if(ac <= 8) ac_str = "High";
  else if(ac <= 11) ac_str = "Exceptional";
  else ac_str = "Subperb";
  mhp = (int)obj->query_mhp();				/* max hit points */
  if(!mhp) mhp_str = "Unknown";
  else if(mhp <= 80) mhp_str = "Poor";
  else if(mhp <= 150) mhp_str = "Moderate";
  else if(mhp <= 250) mhp_str = "High";
  else if(mhp <= 500) mhp_str = "Exceptional";
  else mhp_str = "Endless";
  hlt = ((int)obj->query_hp() * 100) / mhp;
  if(hlt <= 5) hlt_str = "None";
  else if(hlt <= 10) hlt_str = "Very Poor";
  else if(hlt <= 20) hlt_str = "Poor";
  else if(hlt <= 40) hlt_str = "Bad";
  else if(hlt <= 50) hlt_str = "Below Average";
  else if(hlt <= 60) hlt_str = "Above Average";
  else if(hlt <= 75) hlt_str = "Healthy";
  else if(hlt <= 90) hlt_str = "Exceptional";
  else if(hlt <= 99) hlt_str = "Superb";
  else hlt_str = "Perfect";

  write(PRE+"You "+HIB+"consider"+NORM+" "+capitalize(str)+" ... \n");
  write(PRE+HIW+obj->short()+NORM+"\n");
  write(PRE+"  "+pad("Skill", 8)+": "+lvl_str+".\n");
  write(PRE+"  "+pad("Attack", 8)+": "+wc_str+".\n");
  write(PRE+"  "+pad("Defense", 8)+": "+ac_str+".\n");
  write(PRE+"  "+pad("Stamina", 8)+": "+mhp_str+".\n");
  write(PRE+"  "+pad("Health", 8)+": "+hlt_str+".\n");

  GOB->add_endurance(-COST);
  return 1;
}

