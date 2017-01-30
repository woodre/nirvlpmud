#include "../def.h"
#define EMOTER(a,b,c) (string)call_other("/obj/user/parse_emote","parse_emote",a,b,c)

status check_living_target(object caster, object target, object spell) {
  string spell_name;
  spell_name = (string)spell->query_spell_name();
  if(!target)
    FAIL("Your target is not here!\n");
  if(!living(target)) 
    FAIL("You may only cast "+spell_name+" on living things.\n");
  if((string)target->query_real_name() == "guest") 
    FAIL("You may not cast spells on Guest.\n");
  if((int)caster->query_level() < 20 && (int)target->query_level() > 19 && target->is_player()) 
    FAIL("You may not use your powers on wizards.\n");
  if(target->query_ghost() && !spell->allow_ghost()) 
    FAIL("You may not cast "+spell_name+" on ghosts.\n");
  
  return 1;
}

status check_non_living_target(object caster, object target, object spell) {
  if(!target)
    return 0;
  if(living(target))
    return 0;
    
  return 1;
}

status check_combat_target(object caster, object target, object spell) {
  if(!check_living_target(caster, target, spell))
    return 0;
  if((object)caster->query_attack() == target)
    return 1;
  return (int)caster->valid_attack(target);
}

/*
Determines if the user is allowed to use the command they just entered
str:                   argument typed by user
requirements:          requirements created in the command object
usr:                   object using the ability
gob:                   guild object
spell:                 command object
default_target:        what target to use if the user didn't enter a string
special_target_string: one or more values that are acceptable even if they don't resolve to a target.
  seperate values with |

*/
object test_command(string str, mapping requirements, object usr, object gob, object spell, string default_target, string special_target_string, string target_range) {
  object target;
  string *req_keys;
  int s, x;
  if(!str) {
    if(default_target=="self")
      target = usr;
    if(default_target=="room")
      target = spell;
    if(default_target=="attacker")
      target = (object)usr->query_attack();
  } else {
    string target_string,tmp;
    if(sscanf(str,"%s %s", target_string, tmp) != 2)
      target_string = str;
    if(target_range == "mud")
      target = find_living(target_string);
    if(!target && target_range == "room")
      target = present(target_string, ENV(usr));
    if(!target)
      target = present(target_string, usr);
  }
  
  req_keys = keys(requirements);
  s = sizeof(req_keys);
  while(x++ < s--) {
    mixed cmp;
    string msg;
    string key;
    key = req_keys[x-1];
    cmp = requirements[key][0];
    msg = requirements[key][1];  
    switch(key) {
      case "living_target":
        if(!(default_target == "room" && target == spell) && !check_living_target(usr, target, spell))
          FAIL(msg);
      case "combat_target":
        if(!(default_target == "room" && target == spell) && !check_combat_target(usr, target, spell))
          FAIL(msg);
      case "non_living_target":
        if(!(default_target == "room" && target == spell) && !check_non_living_target(usr, target, spell))
          FAIL(msg);      
      case "not_self":
        if(usr == target)
          FAIL(msg);
      case "sp":
        if((int)usr->query_sp() < (int)cmp)
          FAIL(msg);
        break;
      case "hp":
        if((int)usr->query_hp() < (int)cmp)
          FAIL(msg);
        break;
      case "coins":
        if((int)usr->query_money() < (int)cmp)
          FAIL(msg);
        break;
      case "exp":
        if((int)gob->query_light_points() < (int)cmp && (int)usr->query_free_exp() < (cmp))
          FAIL(msg);
      case "level":
        if((int)gob->query_healer_level() < (int)cmp)
          FAIL(msg);
      default:
        if(!call_other(spell, key, str, usr, gob, target))
          FAIL(msg);
      break;
    }
  
  }
  
  if(special_target_string && !target)
  {
    if(member_array(target_string, explode(special_target_string, "|")) != -1)
      return spell;
  }
  
  return target;
}

void asses_costs(int result, mapping costs, object usr, object gob, object spell, object target) {
  string *cost_keys;
  int s, x;
  
  cost_keys = keys(costs);
  s = sizeof(cost_keys);
  while(x++ < s--) {
    mixed amt;
    string key;
    key = cost_keys[x-1];
    amt = costs[key];
    switch(key) {
      case "sp":
        usr->add_spell_point(-amt);
        break;
      case "hp":
        usr->add_hit_point(-amt);
        break;
      case "exp":
        gob->add_light_points(-amt);
        break;
      case "coins":
        usr->add_money(-amt);
        break;
      default:
        call_other(spell, key, usr, gob, target);
        break;
    }
  }
  
  return;
}

/* Determines if a spell is successful. 
  difficulty - base difficulty of the spell
  difficulty_type - which variables are used (see switch statement)
  difficulty_multiplier - higher amounts make the spell easier to cast
  healer_level - total level and +level power of the healer
  piety - piety of the healer
  difficulty_bonus - make it easier (or more difficult) to cast the spell (not currently used)
*/
status check_difficulty(int difficulty, string difficulty_type, int difficulty_multiplier, int healer_level, int piety, int difficulty_bonus)
{
  switch(difficulty_type) {
    case "total":
      return random(difficulty) <= difficulty_multiplier * (healer_level + piety + difficulty_bonus);
    case "piety":
      return random(difficulty) <= difficulty_multiplier * (piety + difficulty_bonus);
    case "level":
      return random(difficulty) <= difficulty_multiplier * (healer_level + difficulty_bonus);
    default:
      return 0;
  }
}

string emote(string str, object usr, object target) {
  return EMOTER(str, usr, target);
}

void do_emote(string s, string r, string t, object usr, object target) {
  object room, *exempt;
  if(s && usr)
    tell_object(usr, emote(s, usr, target));
  if(t && target)
    tell_object(target, emote(t, usr, target));
  if(r && ( room = ENV(usr))) {
    exempt = ({});
    if(usr) exempt += ({usr});
    if(target) exempt += ({target});
    tell_room(room, emote(r, usr, target), exempt);
  }
}

void load_commands(object usr, object gob) {
  string *files, cmd;
  int s;
  write("Loading commands...\n");
  files = get_dir(POWER+"_*.c");
  s=sizeof(files);
  while(s--) {
    sscanf(files[s], "_%s.c", cmd);
    gob->load_command("healer_cmd", cmd);
  }
}

status exec_command(string str, object gob) {
  string verb;
  verb = query_verb();
  return (int)call_other(POWER+"_"+verb,"exec",str,TP,gob);
}

void display_fail_message(object usr, string msg)
{
  if(msg && usr)
    notify_fail(msg);
}