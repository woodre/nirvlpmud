#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xsc"

/***************/
/* guild score */
/***************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xsc \n");
  write("     Syntax : xsc \n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Displays your guild score and statistics.\n");
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

string display_age() {
  int i;
  string tmp;

  i = (int)TP->query_age();

  if (i/43200) {
    tmp = (i/43200) + " days ";
    i = i - (i/43200)*43200;
  }
  if (i/1800) {
    tmp = tmp + "and " + (i/1800) + " hours ";
    i = i  - (i/1800)*1800;
  }
  return tmp;
}

string align_title() {
  int alignment;

  alignment = (int)TP->query_alignment();
  if(alignment > 10 * 64) return "White Lord";
  if(alignment > 10 * 32) return "Paladin";
  if(alignment > 10 * 16) return "Crusader";
  if(alignment > 10 * 8) return "Good";
  if(alignment > 10 * 4) return "Honorable";
  if(alignment > - 10 * 4) return "Neutral";
  if(alignment > - 10 * 8) return "Malicious";
  if(alignment > - 10 * 16) return "Evil";
  if(alignment > - 10 * 32) return "Infamous";
  if(alignment > - 10 * 64) return "Black Knight";
  return "lord of evil";
}

int main() {
  int level, next_exp, spendable;
  int endu, endu_max;
  int spacer;
  string woc;

  /* level = TP->query_level(); */
  level = (int)this_player()->query_level();
  next_exp = (int)DAEMON->query_rank_cost(TP->query_guild_rank() + 1);
  spendable = (int)TP->query_guild_exp() - (int)DAEMON->query_rank_cost(TP->query_guild_rank());

  write(HIB+
  "[(>---------------------------------------------------------------------------<)]\n"+NORM);
  write("    "+HIW+TP->short()+" {"+align_title()+"}\n"+NORM);

  write("    "+pad("Level: "+TP->query_level(), 32));
  write("Extra Level: "+TP->query_extra_level()+"\n");

  write("    "+pad("Experience: "+TP->query_exp(), 32));
  write("Quest Points: "+TP->query_quest_point()+"\n");

  write("    "+pad("Hit Points: "+TP->query_hp()+"/"+TP->query_mhp(), 32));
  write("Spell Points: "+TP->query_sp()+"/"+TP->query_msp()+"\n");

  endu = (int)GOB->query_endurance();
  endu_max = (int)GOB->query_max_endurance();
  write("    "+pad("Endurance: "+endu+"/"+endu_max, 32));
  write("Coins: "+TP->query_money()+"\n");

  write("    "+pad("Age: "+display_age(), 32));
  write("Intox: "+(int)TP->query_intoxination()*100/(level+3)+"%  ");
  write("Stuff: "+(int)TP->query_stuffed()*100/(level*8)+"%  ");
  write("Soak: "+(int)TP->query_soaked()*100/(level+3)+"% \n");
  write("\n");

  write("    "+pad("Guild Rank: "+(int)TP->query_guild_rank(), 32));
  write("Guild Experience: "+(int)TP->query_guild_exp()+"\n");
  write("    "+pad("Tithe: "+(int)GOB->query_tithe()+" %", 32));
  write("Next Rank: "+next_exp+" exp");
  if(next_exp > TP->query_guild_exp()) write(" ("+(next_exp - (int)TP->query_guild_exp())+" needed)");
  write("\n");
  write("    "+pad("Practices: "+(int)GOB->query_practices(), 32));
  write("Donations: "+(int)GOB->query_donations()+"\n");
  write("\n");

  write("    Dexterity: "+pad((int)GOB->query_stat("dexterity"), -3)+" %");
  write(pad(display_bonus("dexterity"), 10));
  write("Agility: "+pad((int)GOB->query_stat("agility"), -3)+" %");
  write(pad(display_bonus("agility"), 10));
  write("Endurance   : "+pad((int)GOB->query_stat("endurance"), -3)+" %");
  write(pad(display_bonus("endurance"), 10)+"\n");

  write("    Strength : "+pad((int)GOB->query_stat("strength"), -3)+" %");
  write(pad(display_bonus("strength"), 10));
  write("Prowess: "+pad((int)GOB->query_stat("prowess"), -3)+" %");
  write(pad(display_bonus("prowess"), 10));
  write("Constitution: "+pad((int)GOB->query_stat("constitution"), -3)+" %");
  write(pad(display_bonus("constitution"), 10)+"\n");
  write("\n");

  woc = (string)GOB->query_weapon_of_choice();
  if(woc) {
	write("    Weapon   : "+HIW+pad(capitalize(woc), 15)+NORM+"Rating : ");
	write(HIW+pad((int)GOB->query_skill(woc), -3)+" %");
	write(display_bonus(woc)+NORM+"\n");
	spacer = 1;
  }
  if(GOB->query_parry()) {
	write("    You are "+HIW+"parrying"+NORM+" attacks.\n");
	spacer = 1;
  }
  if(GOB->query_new_skills()) {
	write("    You can learn "+(int)GOB->query_new_skills()+" new skills.\n");
	spacer = 1;
  }

  if(spacer) write("\n");
  write(HIB+
  "[(>---------------------------------------------------------------------------<)]\n"+NORM);

  return 1;
}
