#include "def.h"
#define BTOX_HEAL_ITVL 10

/* Vampire Guild Object
 * By Illarion - 2014
 * Original Vampire Guild by Nooneelse
 * Updated Vampire Guild by Eurale
 * Don't be a dick - comment any changes
 */

object usr, gob;
 
int humanity;
int bloodpts;
mixed *skills;
string *custom_emotes;

/* tox limits */
int btox,ttox,ctox;
int btox_max, ttox_max, ctox_max;
int tribute, tribute_max;
int tox_pref;
int max_heals;
static int btox_int;
static int dodge_attempts;
static int heal_usage;

reset() {
}

extra_look() {
  if(TP == ETO) return "You are a vampire.\nUse \"vhelp\" to learn more";
  else if(present(GID, TP)) return ETO->query_name()+" is a fellow vampire";
}

id(str) { 
  if(str=="notstuff" || str == "notsoak" || str == "notintox")
  {
    HEALDAEM->mud_heal_attempt(usr, gob, str);
    return 1;
  }
  return str == GID || str == "testfangs" || str=="notheals" || str=="GI"
      || str=="guild_monitor" || str == "generic_wc_bonus";
}

query_name() { return GID; }

get() { return 1; }
drop() { return 1; }

init() {
  if(TP!=ETO) return;
  usr = TP;
  gob = TO;
  restore();
  if(!skills) skills = allocate(0);
  if(!custom_emotes) custom_emotes = allocate(0);
  if(!tox_pref) tox_pref = 14;
  if(!max_heals) max_heals = 1;
  add_action("renew","renew");
  DAEM->load_commands(gob);
  HEALDAEM->calc_tox_max(gob);
  COMDAEM->setup_bonuses(usr, gob);
  set_heart_beat(1);
}

load_command(fun, cmd)
{
  add_action(fun, cmd);
}

guild_cmd(str) {
  return DAEM->exec_command(str);
}

heart_beat() {
  object att;
  int chk;
  
  dodge_attempts = 0;
  heal_usage = 0;
  
  if(!usr->query_weapon())
    usr->wield(usr, 1, ({"physical", 10+query_skill_info("level", "Sanguisugency")/10, 0}));
    
  att = usr->query_attack();
  if(att && !present(att, ENV(usr))) att = 0;
  
  usr->RemoveWeapon(gob);
  if(att) COMDAEM->guild_attack_bonus(usr, gob, att);

  if(ttox) ttox -= att?(random(6)?0:1):(1+random(3));
  if(ctox) ctox -= att?(random(6)?0:1):(1+random(3));
  if(ttox < 0) ttox = 0;
  if(ctox < 0) ctox = 0;
  
  if((btox_int+=2) > BTOX_HEAL_ITVL)
  {
    btox_int = 0;
    if(btox) {
      chk = 2 * this_object()->check_skill("Sanguisugency");
    }
    usr->add_hit_point((2+(int)HEALDAEM->get_regen("hp",usr))*(att?0:1)*(btox?10+chk:1));
    usr->add_spell_point((2+(int)HEALDAEM->get_regen("sp",usr))*(att?0:1)*(btox?10+chk:1));
    if(--btox < 0) btox = 0;  
  } else if(att) {
    if(--btox < 0) btox = 0;  
  }
}

query_btox() { return btox; }
query_ttox() { return ttox; }
query_ctox() { return ctox; }

check_btox() { return btox < btox_max; }
check_ttox() { return ttox < ttox_max; }
check_ctox() { return ctox < ctox_max; }

affect_btox(x) {
  if(x > 0 && !check_btox()) return -1;
  btox+=x;
  if(btox < 0) btox = 0;
  return btox;
}
affect_ttox(x) {
  if(x > 0 && !check_ttox()) return -1;
  ttox+=x;
  if(ttox < 0) ttox = 0;
  return ttox;
}
affect_ctox(x) {
  if(x > 0 && !check_ctox()) return -1;
  ctox+=x;
  if(ctox < 0) ctox = 0;
  return ctox;
}

query_tox_pref() {
  if(tox_pref < 5) tox_pref = 5;
  else if(tox_pref > 14) tox_pref = 14;
  return tox_pref;
}

set_tox_pref(x) {
  tox_pref = x;
  return query_tox_pref();
}

monitor_code(str) {
  switch(str) {
    case "btox": return btox_max == 0 ? "--" : ""+(btox * 100 / btox_max);
    case "ttox": return ttox_max == 0 ? "--" : ""+(ttox * 100 / ttox_max);
    case "ctox": return ctox_max == 0 ? "--" : ""+(ctox * 100 / ctox_max);
    case "debuffs" : return COMDAEM->get_debuff_monstr(gob, usr);
  }
  return 0;
}

query_humanity() {
  if(humanity < 0) humanity = 0;
  if(humanity > 100) humanity = 100;
  return humanity;
}

affect_humanity(x) {
  humanity+=x;
  return query_humanity();
}

set_humanity(x) {
  humanity=x;
  return query_humanity();
}

query_tribute() {
  return tribute;
}

check_tribute(x) {
  return !(tribute+x > tribute_max || tribute + x < 0);
}

affect_tribute(x) {
  if(!check_tribute(x)) return -1;
  tribute+=x;
  return tribute;
}

query_tribute_max() { return tribute_max; }
set_tribute_max(x) { return (tribute_max = x); }

save() {
  save_object(SAVE + usr->query_real_name());
}

restore() {
  restore_object(SAVE + usr->query_real_name());
}

renew() {
  save();
  destruct(gob);
  move_object(clone_object(GOB), usr);
  return 1;
}

/*
  Heals.  also see daem/heal_daem
*/

set_tox_max(b,t,c) {
  btox_max=b; 
  ttox_max=t; 
  ctox_max=c;
}

/* 
  Skills
*/

query_skills() { return skills; }
set_skills(s) { skills = s; }

int add_skill(string skill_name, mixed skill_attribs) {
  return (int)call_other(SKDAEM, "add_skill", skill_name, skills, skill_attribs);
}

int remove_skill(string skill_name) {
  return (int)SKDAEM->remove_skill(skill_name, skills);
}

int check_skill(string skill_name, int bonus) {
  return (int)SKDAEM->check_skill(skill_name, bonus, skills, usr);
}

int check_skill_advance(string skill_name) {
  return (int)SKDAEM->check_skill_advance(skill_name, skills, usr);
}

int advance_skill(string skill_name) {
  return (int)SKDAEM->advance_skill(skill_name, skills, usr);
}

mixed query_skill_info(string info, string name) {
  return call_other(SKDAEM, "query_skill_"+info, name, skills);
}

mixed set_skill_info(string info, string name, mixed arg) {
  return call_other(SKDAEM, "set_skill_"+info, name, skills, arg);
}

/* try something different
gen_wc_bonus(att) {
  return COMDAEM->guild_attack_bonus(usr, gob, att);
}
*/

query_message_hit(dam) {
  return COMDAEM->extra_attack_message_hit(dam, usr, gob);
}

vampire_defense_bonus(wearer, dam) {
  return COMDAEM->guild_defense_bonus(usr, gob, dam);
}

vampire_offense_bonus(att) {
  return COMDAEM->guild_offense_bonus(usr, gob, att);
}

vamp_extra_hit(att) {
  return COMDAEM->extra_attack_bonus(usr, gob, att);
}

count_dodge_attempt() {
  return dodge_attempts++;
}

query_max_heals() { return max_heals; }
set_max_heals(x) { return (max_heals = x); }

query_heal_usage() { return heal_usage; }
count_heal_usage() { return ++heal_usage; }

get_custom_emote(name) {
  int i;
  i = member_array(name, custom_emotes);
  if(i == - 1) return 0;
  return custom_emotes[i+1];
}

set_custom_emote(name, s, r, t) {
  int i;
  i = member_array(name, custom_emotes);
  if(i == - 1) 
    custom_emotes += ({ name, ({s, r, t }) });
  else 
    custom_emotes[i+1] = ({s, r, t });
}