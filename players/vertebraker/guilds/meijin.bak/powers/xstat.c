#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 1000
#define SKILL_NAME "xstat"

/*************************************************************/
/* Wiz Command:  Allows wizards to view guild members stats. */
/*************************************************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xStat \n");
  write("     Syntax : xstat <player>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : wizard\n");
  write("     Description : \n");
  write("         This command is only avaliable to wizards.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }


string display_bonus(string str, object gob) {
  int i, bonus;
  string tmp;

  tmp = "";
  bonus = (int)gob->query_guild_bonus(str);
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

int main(string str){
  object obj, gob;
  mapping skills;
  string *names;
  int i, col;

  if(TP->query_level() < 20) return 0;
  if(!(obj = find_player(str))) {
	write(capitalize(str)+" could not be found.\n");
	return 1;
  }
  if(!(gob = present(GUILDID, obj))) {
	write(capitalize(str)+" does not have a guild object.\n");
	return 1;
  }
  write(HIW+obj->short()+NORM+"\n");
  write(pad("Endurance : "+(int)gob->query_endurance()+"/"+(int)gob->query_max_endurance(), 30));
  write("Hit Points : "+(int)obj->query_hp()+"/"+(int)obj->query_mhp()+"\n");
  write(pad("Guild Rank: "+(int)obj->query_guild_rank(), 30));
  write("Guild Exp  : "+(int)obj->query_guild_exp()+"\n");
  write(pad("Tithe     : "+(int)gob->query_tithe()+"%", 30));
  write("Donations  : "+(int)gob->query_donations()+"\n");
  write(pad("Practices : "+(int)gob->query_practices(), 30));
  write("New Skills : "+(int)gob->query_new_skills()+"\n");
  write("\n");

  write("Dexterity: "+pad((int)gob->query_stat("dexterity"), -3)+" %");
  write(pad(display_bonus("dexterity", gob), 10));
  write("Agility: "+pad((int)gob->query_stat("agility"), -3)+" %");
  write(pad(display_bonus("agility", gob), 10));
  write("Endurance   : "+pad((int)gob->query_stat("endurance"), -3)+" %");
  write(pad(display_bonus("endurance", gob), 10)+"\n");
  write("Strength : "+pad((int)gob->query_stat("strength"), -3)+" %");
  write(pad(display_bonus("strength", gob), 10));
  write("Prowess: "+pad((int)gob->query_stat("prowess"), -3)+" %");
  write(pad(display_bonus("prowess", gob), 10));
  write("Constitution: "+pad((int)gob->query_stat("constitution"), -3)+" %");
  write(pad(display_bonus("constitution", gob), 10)+"\n");
  write("\n");

  skills = (mapping)gob->query_guild_skills();
  names = m_indices(skills);

  col = 0;
  for(i=0; i<sizeof(names); i++) {
	if(col == 3) {
		col = 0;
		write("\n");
	}
	write(pad(capitalize(names[i]), 12) + ": " + pad(skills[names[i]], -3) + " %");
	write(pad(display_bonus(names[i], gob), 10));
	col++;
  }
  if(col == 1) write("\n");
  else write("\n\n");

  return 1;
}

