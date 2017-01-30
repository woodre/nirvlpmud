void set_gexp(int x) { GuildXP = x; }
void add_gexp(int x) { GuildXP += x; }
void sub_gexp(int x) { GuildXP -= x; }
int query_gexp() { return GuildXP; }

void set_glevel(int x) { GuildLevel = x; }
int query_glevel() { return GuildLevel; }

int sizeof_guildlevelcosts() { return SizeofGLC; }

void set_school_exp(int x) { SchoolsXP = x; }
void add_school_exp(int x) { SchoolsXP += x; }
void sub_school_exp(int x) { SchoolsXP -= x; }
int query_school_exp() { return SchoolsXP; }

void set_school_level(int x) { SchoolsLvl = x; }
void add_school_level(int x) { SchoolsLvl += x; }
void sub_school_level(int x) { SchoolsLvl -= x; }
int query_school_level() { return SchoolsLvl; }

void set_school_pts(int x) { SchoolsPts = x; }
void add_school_pts(int x) { SchoolsPts += x; }
void sub_school_pts(int x) { SchoolsPts -= x; }
int query_school_pts() { return SchoolsPts; }

int sizeof_schoolscosts() { return SizeofSC; }

void set_school(string x, int y) { if(member_array(x, VALIDSCHOOLS) > -1) Schools[x] = y; }
void add_school(string x, int y) { if(member_array(x, VALIDSCHOOLS) > -1) Schools[x] += y; }
void sub_school(string x, int y) { if(member_array(x, VALIDSCHOOLS) > -1) Schools[x] -= y; }

int query_school(string x) { return Schools[x]; }

void set_school_bonus(string x, int y) { if(member_array(x, VALIDSCHOOLS) > -1) SchoolsBonus[x] = y; }
void add_school_bonus(string x, int y) { if(member_array(x, VALIDSCHOOLS) > -1) SchoolsBonus[x] += y; }
void sub_school_bonus(string x, int y) { if(member_array(x, VALIDSCHOOLS) > -1) SchoolsBonus[x] -= y; }

int query_school_bonus(string x) { return SchoolsBonus[x]; }

string show_school_bonus(string x)
{
  if(SchoolsBonus[x] > 50)        return "++++";
  else if(SchoolsBonus[x] > 30)   return "+++";
  else if(SchoolsBonus[x] > 15)   return "++";
  else if(SchoolsBonus[x] > 0)    return "+";
  else if(SchoolsBonus[x] == 0)   return "";
  else if(SchoolsBonus[x] < 0)    return "-";
  else if(SchoolsBonus[x] < -15)  return "--";
  else if(SchoolsBonus[x] < -30)  return "---";
  else if(SchoolsBonus[x] < -50)  return "----";
}

void set_attrib_exp(int x) { AttribsXP = x; }
void add_attrib_exp(int x) { AttribsXP += x; }
void sub_attrib_exp(int x) { AttribsXP -= x; }
int query_attrib_exp() { return AttribsXP; }

void set_attrib_level(int x) { AttribsLvl = x; }
void add_attrib_level(int x) { AttribsLvl += x; }
void sub_attrib_level(int x) { AttribsLvl -= x; }
int query_attrib_level() { return AttribsLvl; }

void set_attrib_pts(int x) { AttribsPts = x; }
void add_attrib_pts(int x) { AttribsPts += x; }
void sub_attrib_pts(int x) { AttribsPts -= x; }
int query_attrib_pts() { return AttribsPts; }

int sizeof_attribscosts() { return SizeofAC; }

void set_attrib(string x, int y) { if(member_array(x, VALIDATTRIBS) > -1) Attribs[x] = y; }
void add_attrib(string x, int y) { if(member_array(x, VALIDATTRIBS) > -1) Attribs[x] += y; }
void sub_attrib(string x, int y) { if(member_array(x, VALIDATTRIBS) > -1) Attribs[x] -= y; }

int query_attrib(string x) { return Attribs[x]; }

void set_attrib_bonus(string x, int y) { if(member_array(x, VALIDATTRIBS) > -1) AttribsBonus[x] = y; }
void add_attrib_bonus(string x, int y) { if(member_array(x, VALIDATTRIBS) > -1) AttribsBonus[x] += y; }
void sub_attrib_bonus(string x, int y) { if(member_array(x, VALIDATTRIBS) > -1) AttribsBonus[x] -= y; }

int query_attrib_bonus(string x) { return AttribsBonus[x]; }

string show_attrib_bonus(string x)
{
  if(AttribsBonus[x] > 50)        return "++++";
  else if(AttribsBonus[x] > 30)   return "+++";
  else if(AttribsBonus[x] > 15)   return "++";
  else if(AttribsBonus[x] > 0)    return "+";
  else if(AttribsBonus[x] == 0)   return "";
  else if(AttribsBonus[x] < 0)    return "-";
  else if(AttribsBonus[x] < -15)  return "--";
  else if(AttribsBonus[x] < -30)  return "---";
  else if(AttribsBonus[x] < -50)  return "----";
}

void set_spell_level_trains(int x) { SpellLevelTrains = x; }
void add_spell_level_trains(int x) { SpellLevelTrains += x; }
void sub_spell_level_trains(int x) { SpellLevelTrains -= x; }
int query_spell_level_trains() { return SpellLevelTrains; }

void set_guild_color(string x) { GuildColor = x; }
mixed query_guild_color() { return GuildColor; }

int query_hbeats() { return HBeats; }

status know_spell(string spellname, string school);

void save_gob(); /* prototype declaration */

name_sort(s1, s2) {
  return s1 > s2;
}

void add_spell(string x, string y, int z) /* x = spell name */
{                                         /* y = school */
  switch(y)                               /* z = spell level */
  {
    case "abju" : LearnedAbju += ({ x }); 
    	            LearnedAbju = sort_array(LearnedAbju, "name_sort", this_object()); break; 
    case "conj" : LearnedConj += ({ x }); 
    	            LearnedConj = sort_array(LearnedConj, "name_sort", this_object()); break;
    case "ench" : LearnedEnch += ({ x }); 
    	            LearnedEnch = sort_array(LearnedEnch, "name_sort", this_object()); break;
    case "evoc" : LearnedEvoc += ({ x }); 
    	            LearnedEvoc = sort_array(LearnedEvoc, "name_sort", this_object()); break;
    case "divi" : LearnedDivi += ({ x }); 
    	            LearnedDivi = sort_array(LearnedDivi, "name_sort", this_object()); break;
    case "illu" : LearnedIllu += ({ x }); 
    	            LearnedIllu = sort_array(LearnedIllu, "name_sort", this_object()); break;
    case "necr" : LearnedNecr += ({ x }); 
    	            LearnedNecr = sort_array(LearnedNecr, "name_sort", this_object()); break;
    case "tran" : LearnedTran += ({ x }); 
    	            LearnedTran = sort_array(LearnedTran, "name_sort", this_object()); break;
  } 
  switch(z)
  {
    case 1 : LearnedOne += ({ x }); LearnedOne = sort_array(LearnedOne, "name_sort", this_object()); break;  
    case 2 : LearnedTwo += ({ x }); LearnedTwo = sort_array(LearnedTwo, "name_sort", this_object()); break;
    case 3 : LearnedThree += ({ x }); LearnedThree = sort_array(LearnedThree, "name_sort", this_object()); break;
    case 4 : LearnedFour += ({ x }); LearnedFour = sort_array(LearnedFour, "name_sort", this_object()); break;
    case 5 : LearnedFive += ({ x }); LearnedFive = sort_array(LearnedFive, "name_sort", this_object()); break;
    case 6 : LearnedSix += ({ x }); LearnedSix = sort_array(LearnedSix, "name_sort", this_object()); break;
    case 7 : LearnedSeven += ({ x }); LearnedSeven = sort_array(LearnedSeven, "name_sort", this_object()); break;
  }  
  save_gob();  
}

void remove_spell(string x, string y, int z) /* x = spell name */
{                                            /* y = school */
  switch(y)                                  /* z = spell level */
  {
    case "abju" : LearnedAbju -= ({ x }); break; 
    case "conj" : LearnedConj -= ({ x }); break;
    case "ench" : LearnedEnch -= ({ x }); break;
    case "evoc" : LearnedEvoc -= ({ x }); break;
    case "divi" : LearnedDivi -= ({ x }); break;
    case "illu" : LearnedIllu -= ({ x }); break;
    case "necr" : LearnedNecr -= ({ x }); break;
    case "tran" : LearnedTran -= ({ x }); break;
  } 
  switch(z)
  {
    case 1 : LearnedOne -= ({ x }); break;  
    case 2 : LearnedTwo -= ({ x }); break;
    case 3 : LearnedThree -= ({ x }); break;
    case 4 : LearnedFour -= ({ x }); break;
    case 5 : LearnedFive -= ({ x }); break;
    case 6 : LearnedSix -= ({ x }); break;
    case 7 : LearnedSeven -= ({ x }); break;
  }  
  save_gob();  
}

void set_spell_delay(string x, int y) { Delays[x] = y; }
int query_spell_delay(string x) { return Delays[x]; }

status player_attack_no_hit() { return (Casting ? 1 : 0); }