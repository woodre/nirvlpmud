#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xwho"

/************************/
/* basic "who" commands */
/************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xwho \n");
  write("     Syntax : xwho \n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         List all guild members or players logged in.\n");
  write("         Command options include: \n");
  write("              /guild  - list all in the guild.\n");
  write("              /mud    - list all players on the game.\n");
  write("              /combat - list all players in combat.\n");
  write("              /wiz    - list all visible wizards.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

string totalcap(string str){
  string name, msg, letter;
  int i, count;

  msg = "";
  count = strlen(str);
  for(i=0; i<count; i++){
	letter = extract(str, i, i);
	letter = capitalize(letter);
	msg = msg + letter;
  }
  return msg;
}

int guild_who() {
  object *ob, gob;
  int i, members;
  string name;

  DAEMON->calc_donation_leaders();

  write("\n");
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);
  write("   "+HIB+"[  "+NORM);
  write(BOLD+pad("Name:", 13));
  write(pad("Lvl:", 8));
  write(pad("Rank:", 8));
  write(pad("Sex:", 8));
  write(pad("Location:", 33)+NORM);
  write(HIB+" ]\n"+NORM);
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);

  ob = users();
  for(i=0; i<sizeof(ob); i++) {
	if((gob=present(GUILDID, ob[i])) && (int)ob[i]->query_invis() < (int)TP->query_level()
	&& environment(ob[i])) {
		write("   "+HIB+"["+NORM);
		if(query_idle(ob[i]) >= 120) write(HIC+"%"+NORM);
		else write(" ");
		if(!gob->query_guild_channel()) write(HIM+"~"+NORM);
		else write(" ");
		if(gob->query_donations() >= DAEMON->query_donation_leader(0))
			name = totalcap((string)ob[i]->query_real_name());
		else name = capitalize((string)ob[i]->query_real_name());
		if(ob[i]->query_invis()) name = "("+name+")";
		write(pad(name, 13));
		if((int)ob[i]->query_extra_level())
			write(pad((int)ob[i]->query_level()+"+"+(int)ob[i]->query_extra_level(), 8));
		else
			write(pad((int)ob[i]->query_level(), 8));

		if(present(ALLYID, ob[i]))
			write(" "+pad("Ally", 7));
		else
			write(" "+pad((int)ob[i]->query_guild_rank(), 7));
		write(pad((string)ob[i]->query_gender(), 8));
		write(DAEMON->pad2((string)environment(ob[i])->short(), 33));
		write(HIB+" ]\n"+NORM);
		members++;
	}
  }
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);
  write("   "+HIB+"[  "+NORM);
  write(DAEMON->pad2(BOLD+members+" members logged on.     "+HIM+"~"+BOLD+" = Muffled"+
  "    "+HIC+"%"+BOLD+" = Idle"+NORM, 70));
  write(HIB+" ]\n"+NORM);
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);

  return 1;
}

int mud_who() {
  object *ob;
  int i, members;
  string gname;

  write("\n");
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);
  write("   "+HIB+"[  "+NORM);
  write(BOLD+pad("Name:", 13));
  write(pad("Lvl:", 8));
  write(pad("Guild:", 8));
  write(pad("Sex:", 8));
  write(pad("Location:", 33)+NORM);
  write(HIB+" ]\n"+NORM);
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);

  ob = users();
  for(i=0; i<sizeof(ob); i++) {
	if((int)ob[i]->query_invis() < (int)TP->query_level() && environment(ob[i])) {
		gname = (string)ob[i]->query_guild_name();
		if(!gname) gname = "none";
		if(gname == "Knights Templar") gname = "Knight";
		if(gname == "cyberninja") gname = "Cyber";
		if(gname == "mage") gname = "Mage";
		if(gname == "polymorph") gname = "Poly";
		if(gname == "vampire") gname = "Vamp";
		if(gname == GUILDNAME) gname = HIB+capitalize(GUILDNAME)+NORM;
		write("   "+HIB+"["+NORM);
		if(query_idle(ob[i]) >= 120) write(HIC+"%"+NORM);
		else write(" ");
		if((int)ob[i]->query_pl_k()) write(HIR+"*"+NORM);
		else write(" ");
		write(pad(capitalize((string)ob[i]->query_real_name()), 13));
		if((int)ob[i]->query_extra_level())
			write(pad((int)ob[i]->query_level()+"+"+(int)ob[i]->query_extra_level(), 8));
		else
			write(pad((int)ob[i]->query_level(), 8));
		write(DAEMON->pad2(gname, 8));
		write(pad((string)ob[i]->query_gender(), 8));
		write(DAEMON->pad2((string)environment(ob[i])->short(), 33));
		write(HIB+" ]\n"+NORM);
		members++;
	}
  }
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);
  write("   "+HIB+"[  "+NORM);
  write(DAEMON->pad2(BOLD+members+" people logged on.     "+HIR+"*"+BOLD+" = PK"+
  "    "+HIC+"%"+BOLD+" = Idle"+NORM, 70));
  write(HIB+" ]\n"+NORM);
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);
  return 1;
}

int combat_who() {
  object *ob;
  int i, members, hp, mhp;
  string att_name, gname, shape;

  write("\n");
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);
  write("   "+HIB+"[  "+NORM);
  write(BOLD+pad("Name:", 13));
  write(pad("Lvl:", 8));
  write(pad("Guild:", 10));
  write(pad("Fighting:", 39));
  write(HIB+" ]\n"+NORM);
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);

  ob = users();
  for(i=0; i<sizeof(ob); i++) {
	if((int)ob[i]->query_invis() < (int)TP->query_level() && environment(ob[i])
	&& ob[i]->query_attack()) {
		gname = (string)ob[i]->query_guild_name();
		if(!gname) gname = "none";
		if(gname == "Knights Templar") gname = "Knight";
		if(gname == "cyberninja") gname = "Cyber";
		if(gname == "mage") gname = "Mage";
		if(gname == "polymorph") gname = "Poly";
		if(gname == "vampire") gname = "Vamp";
		if(gname == GUILDNAME) gname = HIB+capitalize(GUILDNAME)+NORM;
		write("   "+HIB+"["+NORM);
		if(query_idle(ob[i]) >= 120) write(HIC+"%"+NORM);
		else write(" ");
		if((int)ob[i]->query_pl_k()) write(HIR+"*"+NORM);
		else write(" ");
		write(pad(capitalize((string)ob[i]->query_real_name()), 13));
		if((int)ob[i]->query_extra_level())
			write(pad((int)ob[i]->query_level()+"+"+(int)ob[i]->query_extra_level(), 8));
		else
			write(pad((int)ob[i]->query_level(), 8));
		write(DAEMON->pad2(gname, 10));
		att_name = (string)ob[i]->query_attack()->query_name();
		if(!att_name) att_name = CYN+"unknown"+NORM;

		hp = (int)ob[i]->query_attack()->query_hp();
		mhp = (int)ob[i]->query_attack()->query_mhp();
		if(hp < mhp/10) shape = HIR+"(VBS)"+NORM;
		else if(hp < mhp/5) shape = HIR+"(BS)"+NORM;
		else if(hp < mhp/2) shape = "(SWH)";
		else if(hp < mhp - mhp/10) shape = "(SLH)";
		else shape = "(GS)";
		write(DAEMON->pad2(capitalize(att_name)+"  "+shape, 39));

		write(HIB+" ]\n"+NORM);
		members++;
	}
  }
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);
  write("   "+HIB+"[  "+NORM);
  write(DAEMON->pad2(BOLD+members+" people in combat.     "+HIR+"*"+BOLD+" = PK"+
  "    "+HIC+"%"+BOLD+" = Idle"+NORM, 70));
  write(HIB+" ]\n"+NORM);
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);

  return 1;
}

int wizard_who() {
  object *ob;
  int i, members;
  string gname;

  write("\n");
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);
  write("   "+HIB+"[  "+NORM);
  write(BOLD+pad("Name:", 13));
  write(pad("Lvl:", 8));
  write(pad("Guild:", 8));
  write(pad("Sex:", 8));
  write(pad("Location:", 33)+NORM);
  write(HIB+" ]\n"+NORM);
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);

  ob = users();
  for(i=0; i<sizeof(ob); i++) {
	if((int)ob[i]->query_invis() < (int)TP->query_level() && environment(ob[i])
	&& (int)ob[i]->query_level() >= 20) {
		gname = (string)ob[i]->query_guild_name();
		if(!gname) gname = "none";
		if(gname == "Knights Templar") gname = "Knight";
		if(gname == "cyberninja") gname = "Cyber";
		if(gname == "mage") gname = "Mage";
		if(gname == "polymorph") gname = "Poly";
		if(gname == "vampire") gname = "Vamp";
		if(gname == GUILDNAME) gname = HIB+capitalize(GUILDNAME)+NORM;
		write("   "+HIB+"["+NORM);
		if(query_idle(ob[i]) >= 120) write(HIC+"%"+NORM);
		else write(" ");
		if(in_editor(ob[i])) write(HIY+"$"+NORM);
		else write(" ");
		write(pad(capitalize((string)ob[i]->query_real_name()), 13));
		write(pad((int)ob[i]->query_level(), 8));
		write(DAEMON->pad2(gname, 8));
		write(pad((string)ob[i]->query_gender(), 8));
		write(DAEMON->pad2((string)environment(ob[i])->short(), 33));
		write(HIB+" ]\n"+NORM);
		members++;
	}
  }
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);
  write("   "+HIB+"[  "+NORM);
  write(DAEMON->pad2(BOLD+members+" wizards logged on.     "+HIY+"$"+BOLD+" = Editing"+
  "    "+HIC+"%"+BOLD+" = Idle"+NORM, 70));
  write(HIB+" ]\n"+NORM);
  write("   "+HIB+"[(>---------------------------------------------------------------------<)]\n"+NORM);

  return 1;
}
 
int main(string str) {
  object obj;

  if(str) str = lower_case(str);
  if(!str || str == "/g" || str == "/guild") guild_who();
  else if(str == "/m" || str == "/mud") mud_who();
  else if(str == "/c" || str == "/combat") combat_who();
  else if(str == "/w" || str == "/wiz") wizard_who();
  else write("Usage: xwho (/guild /mud /combat /wiz)\n");
  return 1;
}

