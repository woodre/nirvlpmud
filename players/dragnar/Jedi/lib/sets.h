/************** Guild sets, queries, and adjusts ***************/
set_carry_obj(object ob) { carry_obj = ob; }
object query_carry_obj() { return carry_obj; }
set_carry_obj_name(string str) { carry_obj_name = str; }

set_force_delay(int x){ force_delay = x; }
query_force_delay(){ return force_delay; }
adj_force_delay(int x){ force_delay += x; }

set_mind_shield(int x){ mind_shield = x; }     
query_mind_shield(){ return mind_shield; }     
adj_mind_shield(int x){ mind_shield += x; }

set_goodness_pool(int x){ goodness_pool = x; }
query_goodness_pool(){ return goodness_pool; }
adj_goodness_pool(int x){ goodness_pool += x; }

set_absorb(int x){ absorb = x; }
query_absorb(){ return absorb; }

set_rage(int x){ rage = x; }
query_rage(){ return rage; }

set_mcp(int x){ mcp = x; }
query_mcp(){ return mcp; }
adj_mcp(int x){ mcp += x; }

set_saber_type(int x) { saber_type = x; }
query_saber_type() { return saber_type; }

set_cp(int x){ cp = x; }
query_cp(){ return cp; }
adj_cp(int x) {
    if(x < 0 && carry_obj && !random(query_skill("telekinesis"))) DropCarry();
  cp += x;
}

set_mon_on(int x) { mon_on = x; }
query_mon_on(){ return mon_on;}

set_skill_points(int x){ skill_points = x; }
query_skill_points(){ return skill_points; }
adj_skill_points(int x){ skill_points += x; }

set_wep_life(int x){ wep_life = x; }
query_wep_life(){ return wep_life; }
adj_wep_life(int x){ wep_life += x; }

set_mon_color(string str){ mon_color = str; }
query_mon_color() {
  int x;
  string temp;

if( mon_color == "auto" ) {
    x = ((USER->query_hp() * 100) / (USER->query_mhp()));
    switch(x) {
    case 80..100:
      temp = HIG;
      break;
    case 60..79:
      temp = HIB;
      break;
    case 40..59:
      temp = HIY;
      break;
    case 0..39:
      temp = HIR;
      break;
    default:
      temp = HIM;
      break;
  }
}
  else temp = mon_color;
  return temp;
}

set_wep_color(string x) { wep_color = x; }
query_wep_color(){ return wep_color; }

query_combat_method(){ return 2; }
query_paladin_shield(){ return 1; }

set_my_master(string s) { return my_master = (s) ? s : "none"; }
query_my_master(){ return my_master; }

set_secondary_masters(string s) { secondary_masters += s; }
query_secondary_masters() { return secondary_masters; }

set_council(int x){ council = x; }
query_council(){ return council; }

set_darkside(int x){ darkside = x; }
query_darkside(){ return darkside; }

set_skill(string str, int lev) {
  skills += ({ str, lev, });
}
adj_skill(string str, int lev) {
  int index;

  if(str != "saber" && str != "telekinesis" && 
     str != "telepathy" && str != "physical") return 0;
  if(!skills)  skills = ({ "saber",0,"telekinesis",0,"physical",0,"telepathy",0,});
  index = member_array(str,skills);
  if(index < 0) {
    set_skill(str, lev);
    return;
  }
  skills[index+1] += lev;
  return;
}
int query_skill(string str) {
  int index;
  
  index = member_array(str, skills);
  if(index < 0) return 0;
  else return skills[index+1];
}

set_offwep(ob) { offwep = ob; }
query_offwep() { return offwep; }
remove_offwep(){ offwep = 0; }

/*****************************************************************/
