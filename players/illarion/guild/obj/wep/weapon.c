/* weapon.c - guild weapon (and armor) for blademasters guild
 * This weapon doesn't save or autoload.  Instead it is cloned
 * when needed.
 */

#include "/players/illarion/guild/def.h"
inherit "obj/weapon.c";

object guild_object;
/* Used to keep track of wether the weapon is in the correct hands or not */
object owner_ob;

object current_att;
int base_ac;
/* Flat-out kill any chance of extra attacks */
int no_extra;

/* Keep track of these because they modify the chances of further ones */
int extra_attacks;
int def_round;

/* Additional bonuses and penalties that can be added in various ways.
   They always reset at the end of a round
 */
int temp_d_mod;
int temp_o_mod;

string empower_type;
int empower_rounds;
/* Make sure the target of the current attack is hit, as it can vary
   due to counter-attacks
 */
object empower_target;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

}

void set_owner(object ob) {
  owner_ob=ob;
}

void set_guild_object(object ob) {
  guild_object=ob;
}

void set_base_ac(int amt) {
  base_ac=amt;
}

void add_temp_d_mod(int amt) {
  temp_d_mod+=amt;
}

void add_temp_o_mod(int amt) {
  temp_o_mod+=amt;
}

void set_no_extra() {
  no_extra=1;
}

id(str) {
  if(str=="notarmor" && previous_object()->query_type()=="shield") return 1;
  if(str=="notspell") return 1;
  return ::id(str);
}

wield(str) {
  if(::wield(str)) {
    TP->RegisterArmor(TO,({"physical",base_ac,0,"armor_func"}));
    set_heart_beat(1);
    return 1;
  }
}

stopwield() {
  if(::stopwield()) {
    guild_object->set_wep_hits(hits);
    guild_object->set_wep_misses(misses);
    DAEM->do_skill_spam("unwield",guild_object,environment(),0,broke?-1:1);
    guild_object->save_guild_stats();
    destruct(TO);
    return 1;
  }
}

init() {
  if(!environment()) return;
  if(environment() !=owner_ob) {
    if(guild_object) {
      guild_object->set_wep_hits(hits);
      guild_object->set_wep_misses(misses);
      guild_object->save_guild_stats();
    }
    destruct(TO);
    return;
  }
  ::init();
}
/* Should the weapon break, it must be repaired by the NPC
   That solid it to the player to begin with */

weapon_breaks() {
  guild_object->set_wep_broken(1);
  command("unwield",owner_ob);
  return 1;
}

heart_beat() {
  if((int)wielded_by->query_spell_point() < 2) {
    DAEM->do_skill_spam("drain",guild_object,wielded_by);
    command("unwield",wielded_by);
  }
  wielded_by->add_spell_point(-2);
}

int armor_func(object user) {
  if(user != wielded_by) {
    user->RemoveArmor(TO);
    return 0;
  }
  if(def_round==0) {
    /* First defensive check of a round, so all previous offensive mods are null */
    temp_o_mod=0;
  }
  return (int)DAEM->calc_defense(owner_ob,TP,guild_object,def_round++,temp_d_mod);
}

void add_parry_damage() {
  hits+=1;
}

query_pro_weapon() {
  return 1;
}

varargs int proficiency_hit(object who) {
  if(!who) who=current_att;
  return (int)DAEM->calc_damage(wielded_by,who,guild_object,class_of_weapon,temp_o_mod);
}

int weapon_hit(object att) {
  /* now that we're starting our first attack, defense penalties should be cleared */
  extra_attacks=0;
  def_round=0;
  current_att=att;
  empower_target=att;
}

string *query_message_hit(int dmg) {
  switch(dmg) {
    default: return ({" to small fragments","massacred"});
    case 20..29: return ({" with a bone crushing sound","smashed"});
    case 10..19: return ({" very hard","hit"});
    case 5..9:   return ({" hard","hit"});
    case 3..4:   return ({"","hit"});
    case 2:      return ({"","grazed"});
    case 1:      return ({" in the stomach","tickled"});
    case 0:      return ({"","missed"});
  }
}

/* Allows the extra attack and counterattack skills to execute an additional attack */
int fake_attack(object who) {
  int dam;
  string *dmess,att_name;
  object room;
  room=environment(wielded_by);
  if(!who || !room || !present(who,room)) return 0;
  empower_target=who;
  att_name=QN(who);
  dam=class_of_weapon+proficiency_hit(who);
  dam=(int)who->hit_player(random(dam));
  if(!who) return dam;
  dmess=query_message_hit(dam);
  att_name=QN(who);
  tell_object(wielded_by,"You "+dmess[1]+" "+att_name+dmess[0]+".\n");
  tell_room(environment(wielded_by),
            QN(wielded_by)+" "+dmess[1]+" "+att_name+dmess[0]+".\n",
            ({wielded_by}));
  return dam;
}

/* Try for an extra attack using the extra attack skill */
void extra_attack() {
  int ex_att_check;
  int dam;
/* Ensures no further attacks after a critical failure in enhanced or crit */
  if(no_extra) {
    no_extra=0;
    return;
  }
  if(!current_att) return;
  if(!DAEM->extra_attack(wielded_by,current_att,guild_object,++extra_attacks,temp_o_mod))
    return;
  dam=fake_attack(current_att);
  if(dam==0)
    TO->count_misses();
  else
    TO->count_hit_made();
}

count_hit_made(x,no_ex) {
  ::count_hit_made(x);
  if(empower_rounds && empower_target) {
    empower_rounds--;
    empower_target->hit_player(2+random(9+(class_of_weapon-10)*2),"other|"+empower_type);
    DAEM->do_skill_spam("empower"+empower_type+"hit",guild_object,owner_ob,empower_target,1);
    empower_target=0;
  }
  if(!no_ex)
    extra_attack();
}

count_misses(no_ex) {
  ::count_misses();
  if(!no_ex)
    extra_attack();
}

query_empowered() {
  return empower_rounds;
}

empower(string type) {
  empower_rounds=4;
  empower_type=type;
}
