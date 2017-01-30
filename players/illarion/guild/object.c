/* Guild Object for Blademasters
 * Coded by Illarion, Jan-xxx 2004
 */

#include "/players/illarion/guild/def.h"


mixed *skills;
mixed *enhancements;
int spam_level;
int souls_absorbed;
int souls_spent;

static object owner;

static int base_wc;
static int base_ac;
static int armor_wt;

static int def_rounds,temp_d_mod;
static int att_rounds,temp_o_mod;
static int no_extra,parrystate;

static object weapon;
static int start_grip;
static object multi_target;

mapping hit_spell;

/* Appearance functions */
status id(string str) {
/* No new armor or spells while using guild skills */
  if(str == "notarmor" || str == "notspell")
    if(TO->check_weapon())
      return 1;
  return (str == "gauntlet" || str == OB_NAME || str=="generic_wc_bonus" || str=="GI");
}

string short() {
  return "An Oni Gauntlet (worn)";
}

void long() {
  write("The soul-devouring gauntlet granted to you by the Oni.\n"+
        "Use "+BLD("ghelp")+" for more information.\n");
}

status get() {
  return 1;
}

status drop() {
  return 1;
}


/* Saving and Restoring */

void restore_guild_stats() {
  if(!owner) return;
  tell_object(owner,"Remembering your lore...\n");
  restore_object(SAVE_DIR+(string)owner->query_real_name());
}

void save_guild_stats() {
  if(!owner) return;
  tell_object(owner,"Saving your lore...\n");
  save_object(SAVE_DIR+(string)owner->query_real_name());
}

reset(arg) {
  if(arg)
    save_guild_stats();
}

quit_hook() {
  TO->end_grip();
  save_guild_stats();
}

/* Guild Powers */

void init() {
  string *filenames,verb;
  int x;
  if(this_player() && environment() && !owner && this_player()==environment())
    owner=this_player();
  else
    return;

  restore_guild_stats();

  add_action("quit_hook","quit");

  if(!skills) {
    skills=(mixed)DAEM->init_skills();
  }



/* Each file in the power dir is loaded as a verb.  the guild_spell function
   handles calling main() function in the corresponding file to trigger the power
   The list is pulled by the main DAEM so every guild object doesn't have to
   do it.
*/

  filenames=(mixed)DAEM->query_power_list();
  for(x=0;x<sizeof(filenames);x++)
    add_action("guild_spell",filenames[x]);

}

int guild_spell(string arg) {
  if(call_other(POWER_DIR+query_verb(),"main",arg,TO,owner))
    return 1;
  return 0;
}

/* Skills */

int query_base_ac() {
  return base_ac;
}

int query_base_wc() {
  return base_wc;
}

int query_armor_wt() {
  return armor_wt;
}

void set_base_wc(int x) {
  base_wc=x;
}

void set_base_ac(int x) {
  base_ac=x;
}

void set_armor_wt(int x) {
  armor_wt=x;
}

mixed *query_skills() {
  return skills;
}

int query_skill_level(string skill_name) {
  int ind;
  ind=member_array(skill_name,skills);
  if(ind==-1)
    return 0;
  return skills[ind+1];
}

int query_practices(string skill_name) {
  int ind;
  ind=member_array(skill_name,skills);
  if(ind==-1)
    return 0;
  return skills[ind+2];
}

void add_practice(string skill_name,status type) {
  int ind;
  ind=member_array(skill_name,skills);
  if(ind==-1)
    return;
  skills[ind+2]++;
  DAEM->prac_spam(owner,skill_name,type);
}

void raise_skill(string skill_name) {
  int ind;
  ind=member_array(skill_name,skills);
  if(ind==-1)
    return;
  skills[ind+1]++;
  skills[ind+2]=0;
  save_guild_stats();
}

/* misc */

int query_spam_level() {
  return spam_level;
}

/* Guild Weapon Conditions */

void set_spam_level(int x) {
  spam_level=x;
}

/* Damage functions */

heart_beat() {
  att_rounds=0;
  def_rounds=0;
  temp_o_mod=0;
  temp_d_mod=0;
}

void set_no_extra(int x) {
  no_extra=x;
}

void set_parrystate() {
  parrystate=1;
}

void set_weapon(object wep) {
  set_heart_beat(1);
  DAEM->kill_shadow(weapon,owner);
  weapon=wep;
  DAEM->set_shadow(weapon,owner,TO);
}

status check_weapon() {
  if(!weapon)
    return 0;
  if((object)owner->query_weapon() != weapon) {
    owner->RemoveArmor(TO);
    set_heart_beat(0);
    weapon=0;
    return 0;
  }
  return 1;
}

void end_grip() {
  if(!check_weapon()) return;
  call_other(POWER_DIR+"release","main","",TO,owner);
}

object query_weapon() {
  return weapon;
}

int gen_wc_bonus(object who) {
  int dam;
  if(!check_weapon())
    return 0;
  if(!who)
    who=(object)owner->query_attack();
  if(!who) return 0;
  multi_target=who;
  return (int)DAEM->calc_damage(owner,who,TO,base_wc,temp_o_mod);
}

void try_extra_attack(int hit) {
  int spell_result;
  if(parrystate) {
    parrystate=0;
    return;
  }
  if(hit_spell) {
    spell_result=(int)DAEM->do_spell(hit_spell,owner,multi_target,TO,hit);
    hit_spell=0;
  }
  if(!multi_target || spell_result==-1) return;
  if(spell_result==1 ||
     (!no_extra && DAEM->extra_attack(owner,multi_target,TO,++att_rounds,temp_o_mod))
    ){
    owner->toggle_already_fight();
    owner->attack();
  }
  multi_target=0;
  no_extra=0;
}

void weapon_hit_something() {
  try_extra_attack(1);
}

void weapon_missed() {
  try_extra_attack(0);
}

/* Armor functions */

int armor_func(object owner) {
  if(!check_weapon())
    return 0;
  return (int)DAEM->calc_defense(owner,TP,TO,def_rounds++,temp_d_mod,armor_wt);
}

/* soul absorbtion */

int add_souls_absorbed(int x) {
  return souls_absorbed+=x;
}

int query_souls_absorbed() {
  return souls_absorbed;
}

int query_souls_available() {
  return souls_absorbed-souls_spent;
}

int add_souls_spent(int x) {
  return souls_spent+x;
}