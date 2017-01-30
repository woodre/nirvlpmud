#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "skills"

/*****/
/* display players skills */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skills are the abilities and special powers that a\n");
  write("     Meijin has.  To see a list of skills you currently\n");
  write("     have simply type 'skills'.  To get more detailed\n");
  write("     help on a specific skill type 'xhelp <skill>'.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

string display_bonus(string str) {
  int i, bonus;
  string tmp;

  tmp = "";
  bonus = (int)GOB->query_guild_bonus(str);
  if(bonus > 0) {
        if(bonus > 4) bonus = 4;
        for(i=0; i<bonus; i++) tmp = tmp + "+";
  }
  else if(bonus < 0) {
        if(bonus < -4) bonus = -4;
        for(i=0; i>bonus; i--) tmp = tmp + "-";
  }
  return tmp;
}

int main() {
  string *skills;
  int i, col;

  skills = m_indices((mixed)GOB->query_guild_skills());
  col = 0;

  write(HIW+"                          Meijin Guild Skills                        \n"+NORM);
  write(HIB+" [(>-------------------------------------------------------------------------<)]\n"+NORM);

  for(i=0; i<sizeof(skills); i++) {
	if(!col) write("    ");
	write(HIW+pad(capitalize(skills[i]), 12)+NORM+": "+pad((int)GOB->query_skill(skills[i]), -3)+"%");
	write(display_bonus(skills[i])+"       ");
	col++;
	if(col == 3) {
		write("\n");
		col = 0;
	}
  }

  if(col) write("\n");
  write(HIB+" [(>-------------------------------------------------------------------------<)]\n"+NORM);

  return 1;
}

