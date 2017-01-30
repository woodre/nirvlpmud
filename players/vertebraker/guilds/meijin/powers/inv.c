#include "/players/vertebraker/guilds/meijin/defs.h";
#define COST 0
#define RANK 0
#define SKILL_NAME "inv"

#undef HAND
#undef OFFHAND
#define HAND (int)GOB->query_handed(0)
#define OFFHAND (int)GOB->query_handed(1)

/*****/
/* guild inventory command.  also displays % carry capacity */
/*****/

/* Aprroved, Bp Jul 16 20:55 inv.c */
void help() {
  write("\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("     Skill  : inv \n");
  write("     Syntax : inv\n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Guild inventory command.  Inv displays important\n");
  write("         information on what you are carrying.\n");
  write("  [(>-------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  object *obj, wield, offw;
  int i, wt, count;
  int player_max, total_weight;
  mapping inv_map, type_map, weight_map;
  string *inv_list, name, w_short, w_short2;

  inv_map = ([]);
  type_map = ([]);
  weight_map = ([]);

  obj = all_inventory(TP);
  offw = (object)GOB->query_off_wield();
  wield = (object)TP->query_weapon();

  for(i=0; i<sizeof(obj); i++) {
	name = (string)obj[i]->short();
	if(!name) continue;
	if((str == "w" || str == "weaps" || str == "weapons") && (!obj[i]->weapon_class())) continue;
	if((str == "a" || str == "armor" || str == "armors") && (!obj[i]->armor_class())) continue;
	if((str == "h" || str == "heal" || str == "heals") && (!obj[i]->is_heal())) continue;
	if(obj[i] == wield)
		if(sscanf(name, "%s (wielded)%s", w_short, w_short2)==2)
			name = w_short+" (wielded in "+HAND+" hand)"+w_short2;
	if(obj[i] == offw)
		name = name +" (wielded in "+OFFHAND+" hand)";
	count++;
	inv_map[name] += 1;
	if((int)obj[i]->weapon_class()) type_map[name] = HIW+"weapon    "+NORM;
	else if((int)obj[i]->armor_class()) type_map[name] = "armor     ";
	else if((int)obj[i]->is_heal()) type_map[name] = "heal      ";
	else type_map[name] = "item      ";
	wt = (int)obj[i]->query_weight();
	total_weight += wt;
	if(wt >= 8) weight_map[name] = "ext. heavy";
	else if(wt >= 6) weight_map[name] = "very heavy";
	else if(wt >= 4) weight_map[name] = "heavy";
	else if(wt >= 2) weight_map[name] = "moderate";
	else if(wt >= 1) weight_map[name] = "light";
	else weight_map[name] = "none";
  }

  if(count < 1) {
	write("You are not carrying anything.\n");
	return 1;
  }

  player_max = (int)TP->query_level() + 6 + (int)TP->query_attrib("str") / 5;
  if((int)TP->query_level()==1) player_max = (int)TP->query_level() + 6 + (int)TP->query_attrib("str") / 2;
  if((int)TP->query_frog()) player_max = player_max / 2;
  write("You are carrying "+count+" items (");
  write((100*total_weight)/player_max+"% cc) : \n");

  inv_list = m_indices(inv_map);
  for(i=0; i<sizeof(inv_list); i++) {
	if(inv_map[inv_list[i]] < 2) write("     ");
	else write("  "+pad(inv_map[inv_list[i]], 3));
	write(DAEMON->pad2(inv_list[i], 45));
	write(type_map[inv_list[i]]);
	write(weight_map[inv_list[i]]+"\n");
  }
  return 1;
}

