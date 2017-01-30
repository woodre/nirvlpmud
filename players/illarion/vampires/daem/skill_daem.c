#include "../def.h"
#define ENTRIES_PER_SKILL 10
#define PREV previous_object()
#define CRIT 500

int get_skill_index(string skill_name, mixed skills) {
  string real_skill_name;
  if(skills==0) {
    return -1;
  }
  real_skill_name="^^^"+skill_name+"^^^";
  return member_array(real_skill_name,skills);
}

int add_skill(string skill_name, mixed *skills, mixed *skill_attribs) {
  string use_attrib,practice_attrib;
  int use_difficulty,practice_difficulty_success,practice_difficulty_failure;
  int train_difficulty,train_cost;
  int skill_index;
  string real_skill_name;
  real_skill_name="^^^"+skill_name+"^^^";

  skill_index=get_skill_index(skill_name, skills);
  if(skill_index != -1)
    return -1;

  switch(sizeof(skill_attribs)) {
    default: return 0;
    case 7: train_cost=skill_attribs[6];
    case 6: train_difficulty=skill_attribs[5];
    case 5: practice_difficulty_failure=skill_attribs[4];
    case 4: practice_difficulty_success=skill_attribs[3];
    case 3: use_difficulty=skill_attribs[2];
    case 2: practice_attrib=skill_attribs[1];
            use_attrib=skill_attribs[0];
  }
  if(member_array(use_attrib,({"mag","sta","str","ste","dex","int","wil","pie","luc","cha"})) == -1) return 0;
  if(member_array(practice_attrib,({"mag","sta","str","ste","dex","int","wil","pie","luc","cha"})) == -1) return 0;

  if(use_difficulty==0) use_difficulty=100;
  else if(use_difficulty < 1) return 0;
  if(practice_difficulty_success==0) practice_difficulty_success=75;
  else if(practice_difficulty_success<1) return 0;
  if(practice_difficulty_failure==0) practice_difficulty_failure=25;
  else if(practice_difficulty_failure<1) return 0;
  if(train_difficulty==0) train_difficulty=10;
  else if(train_difficulty<1) return 0;
  if(train_cost==0) train_cost=100;
  else if(train_cost<1) return 0;
  skills += ({ real_skill_name, 1, 0, use_attrib, practice_attrib,
               use_difficulty,practice_difficulty_success,
               practice_difficulty_failure,train_difficulty,train_cost });
  PREV->set_skills(skills);
  return 1;
}


int remove_skill(string skill_name, mixed skills) {
  int skill_index,x;
  mixed *new_skills;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index==-1)
    return 0;
  new_skills=({});
  for(x=0;x<skill_index;x++)
    new_skills+=({skills[x]});
  for(x=skill_index+ENTRIES_PER_SKILL;x<sizeof(skills);x++)
    new_skills+=({skills[x]});
  PREV->set_skills(new_skills);
  return 1;
}

int check_skill(string skill_name, int bonus, mixed skills, object owner) {
  int skill_roll,difficulty_roll,practice_roll,practice_difficulty_roll,critical_roll;
  int use_attrib_bonus,practice_attrib_bonus;
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index==-1)
    return 0;
  critical_roll = random(CRIT+1);
  use_attrib_bonus=(int)owner->query_attrib(skills[skill_index+3])/3;
  practice_attrib_bonus=(int)owner->query_attrib(skills[skill_index+4])/3;

  skill_roll=random(skills[skill_index+1]+use_attrib_bonus+bonus);
  difficulty_roll=random(skills[skill_index+5]);

  if(critical_roll != 0 && (skill_roll >= difficulty_roll || critical_roll == CRIT)) {
    practice_roll=random(skills[skill_index+6]+practice_attrib_bonus);
    difficulty_roll=random(100);
    if(practice_roll >= difficulty_roll) {
      skills[skill_index+2]++;
    }
    PREV->set_skills(skills);
    return 1+critical_roll/CRIT;
  } else {
    practice_roll=random(skills[skill_index+7]+practice_attrib_bonus);
    difficulty_roll=random(100);
    if(practice_roll >= difficulty_roll) {
      skills[skill_index+2]++;
    }
    PREV->set_skills(skills);
    return 0 - (critical_roll == 0?1:0);
  }
}

int practices_needed(int skill_level, int train_difficulty) {
  int train_difficulty_divisor;
  train_difficulty_divisor=10;
  return skill_level * (train_difficulty + train_difficulty*skill_level/train_difficulty_divisor);
}

int experience_needed(int skill_level, int train_cost) {
  int train_cost_divisor;
  train_cost_divisor=10;
  return skill_level * (train_cost + train_cost*skill_level/train_cost_divisor);
}

int experience_free(object who) {
  int total_xp;
  int used_xp;
  int l,xl;
  l=(int)who->query_level();
  xl=(int)who->query_extra_level();
  total_xp=(int)who->query_exp();
  if(l==19 && xl !=0)
    used_xp=(int)call_other("room/adv_guild","query_cost_for_extra_level",xl);
  else
    used_xp=(int)call_other("room/adv_guild","get_next_exp",l-1);
  return total_xp-used_xp;
}

mixed query_skill_information(mixed skills) {
  int x;
  mixed *brief_skills;
  string temp;
  if(skills==0) return ({});
  brief_skills=({});
  for(x=0; x<sizeof(skills); x+=ENTRIES_PER_SKILL) {
    sscanf(skills[x],"^^^%s^^^",temp);
    brief_skills+=({temp,skills[x+1],100*skills[x+2]/practices_needed(skills[x+1],skills[x+8])});
  }
  return brief_skills;
}

int check_skill_advance(string skill_name, mixed skills, object owner) {
  int skill_index;
  status enough_practices,enough_experience;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index==-1)
    return 0;
  if(skills[skill_index+2] >= practices_needed(skills[skill_index+1],skills[skill_index+8]))
    enough_practices=1;
  else
    enough_practices=0;
  if(experience_free(owner) > experience_needed(skills[skill_index+1],skills[skill_index+9]))
    enough_experience=1;
  else
    enough_experience=0;
  if(enough_experience && enough_practices)
    return 1;
  if(!enough_practices && !enough_experience)
    return -3;
  if(!enough_practices)
    return -2;
  return -1;
}

int advance_skill(string skill_name, mixed skills, object owner) {
  int skill_index;
  int advance_check;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index==-1)
    return 0;
  advance_check = check_skill_advance(skill_name, skills, owner);
  if(advance_check != 1)
    return advance_check;
  skills[skill_index+1]++;
  skills[skill_index+2]=0;
  owner->add_exp(-experience_needed(skills[skill_index+1],skills[skill_index+9]));
  PREV->set_skills(skills);
  return 1;
}

int query_skill_level(string skill_name, mixed skills) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  else
    return skills[skill_index+1];
}

int query_skill_practices(string skill_name, mixed skills) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  else
    return skills[skill_index+2];
}

string query_skill_use_attrib(string skill_name, mixed skills) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return "";
  else
    return skills[skill_index+3];
}

string query_skill_practice_attrib(string skill_name, mixed skills) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return "";
  else
    return skills[skill_index+4];
}

int query_skill_use_difficulty(string skill_name, mixed skills) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  else
    return skills[skill_index+5];
}

int query_skill_practice_difficulty_success(string skill_name, mixed skills) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  else
    return skills[skill_index+6];
}

int query_skill_practice_difficulty_failure(string skill_name, mixed skills) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  else
    return skills[skill_index+7];
}

int query_skill_train_difficulty(string skill_name, mixed skills) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  else
    return skills[skill_index+8];
}

int query_skill_train_cost(string skill_name, mixed skills) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  else
    return skills[skill_index+9];
}

int set_skill_level(string skill_name, mixed skills, int what) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  if(what <= 0)
    return 0;
  skills[skill_index+1]=what;
  PREV->set_skills(skills);
  return 1;
}

int set_skill_practices(string skill_name, mixed skills, int what) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  if(what<0)
    return 0;
  skills[skill_index+2]=what;
  PREV->set_skills(skills);
  return 1;
}

int set_skill_use_attrib(string skill_name, mixed skills, string what) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  if(member_array(what,({"mag","sta","str","ste","dex","int","wil","pie","luc","cha"})) == -1)
    return 0;
  skills[skill_index+3]=what;
  PREV->set_skills(skills);  
  return 1;
}

int set_skill_practice_attrib(string skill_name, mixed skills, string what) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  if(member_array(what,({"mag","sta","str","ste","dex","int","wil","pie","luc","cha"})) == -1)
    return 0;
  skills[skill_index+4]=what;
  PREV->set_skills(skills);
  return 1;
}

int set_skill_use_difficulty(string skill_name, mixed skills, int what) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  if(what<0)
    return 0;
  skills[skill_index+5]=what;
  PREV->set_skills(skills);  
  return 1;
}

int set_skill_practice_difficulty_success(string skill_name, mixed skills, int what) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  if(what<0)
    return 0;
  skills[skill_index+6]=what;
  PREV->set_skills(skills);  
  return 1;
}

int set_skill_practice_difficulty_failure(string skill_name, mixed skills, int what) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  if(what<0)
    return 0;
  skills[skill_index+7]=what;
  PREV->set_skills(skills);  
  return 1;
}

int set_skill_train_difficulty(string skill_name, mixed skills, int what) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  if(what<0)
    return 0;
  skills[skill_index+8]=what;
  PREV->set_skills(skills);  
  return 1;
}

int set_skill_train_cost(string skill_name, mixed skills, int what) {
  int skill_index;
  skill_index=get_skill_index(skill_name, skills);
  if(skill_index == -1)
    return -1;
  if(what<0)
    return 0;
  skills[skill_index+9]=what;
  PREV->set_skills(skills);  
  return 1;
}