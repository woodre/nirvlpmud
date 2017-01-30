#include "../def.h"
#define EMOTER(a,b,c) (string)call_other("/obj/user/parse_emote","parse_emote",a,b,c)
 
reset(arg) {
}
 
load_commands(gob)
{
  string *files, cmd;
  int s;
  write("Loading commands...\n");
  files = get_dir(LIB+"_*.c");
  s=sizeof(files);
  while(s--) {
    sscanf(files[s], "_%s.c", cmd);
    gob->load_command("guild_cmd", cmd);
  }
  write("Loading soul...\n");
  files = get_dir(SOUL+"_*.c");
  s=sizeof(files);
  while(s--) {
    sscanf(files[s], "_%s.c", cmd);
    gob->load_command("guild_emote", cmd);
  }  
}

exec_command(str) {
  string verb;
  object gob;
  verb = query_verb();
  gob = previous_object();
  return call_other(LIB+"_"+verb,"exec",str,TP,gob);
}

test_combat(str, req, usr, gob, cmd)
{
  object target;
  if(!str) { 
    target = usr->query_attack();
    if(!target || !present(target, ENV(usr)))
    {
      cmd->no_target();
      return 0;
    }
  } else {
    target = present(str, ENV(usr));
    if(!target) 
    {
      cmd->no_target(str);
      return 0;
    }
  }
  if(target != usr->query_attack())
  {
    if(!usr->valid_attack(target))
    {
      cmd->attack_fail(target);
      return 0;
    }
  }
  return target;
}

test_command(str, req, usr, gob, cmd, combat, heal)
{
  string *req_keys;
  object target;
  mixed result;
  int x,s;
  int tmp;
  mixed chk1;
  if(combat) {
    target = test_combat(str, req, usr, gob, cmd);
    if(!target) return 0;
  } else if(str) {
    target = present(str, usr);
    if(!target) target = present(str, ENV(usr));
  }
  
  if(heal) {
    if(gob->query_heal_usage() >= gob->query_max_heals()) {
      cmd->heal_fail();
      return 0;
    }
  }
  
  req_keys = keys(req);
  s=sizeof(req_keys);
  x=0;
  while(x++ < s) {
    mixed cmp;
    string msg;
    string key;
    key = req_keys[x-1];
    cmp = req[key][0];
    msg = req[key][1];
    switch(key) {
      case "skill":
        if(gob->query_skill_info("level", cmp[0]) < cmp[1])
          FAIL(msg);
        break;
      case "debuff":
        if(!COMDAEM->check_debuff(target, cmp))
          FAIL(msg);
        break;
      case "btox":
        if(cmp == 0 && !gob->check_btox())
          FAIL(msg);
        if(gob->query_btox() < cmp)
          FAIL(msg);
        break;
      case "ttox":
        if(cmp == 0 && !gob->check_ttox())
          FAIL(msg);
        if(gob->query_ttox() < cmp)
          FAIL(msg);
        break;
      case "ctox":
        if(cmp == 0 && !gob->check_ctox())
          FAIL(msg);
        if(gob->query_ctox() < cmp)
          FAIL(msg);
        break;
      case "tox_tribute":
        tmp = HEALDAEM->heal_cost(cmp, gob->query_tox_pref());
        if(tmp == 0)
          FAIL("Illegal heal or tox rate.\n");
        if(!gob->check_tribute(-tmp))
          FAIL(msg);
        break;
      case "tribute":
        if(!gob->check_tribute(cmp))
          FAIL(msg);
        break;
      case "no_heals":
        if(usr->query_stuffed() > 0 || usr->query_soaked() > 0 || usr->query_intoxination() > 0)
          FAIL(msg);
        break;
      case "not_self":
        if(target == usr)
          FAIL(msg);
        break;
      case "not_casting":
        if(!stringp(cmp))
        {
          if(usr->query_spell_dam())
            FAIL(msg);
        } else {
          if(usr->query_spell_dam() && usr->query_spell_name() != cmp)
            FAIL(msg);
        }
        break;
      case "sp":
        if(usr->query_spell_point() < cmp)
          FAIL(msg);
        break;
      case "gold":
        if(usr->query_money() < cmp)
          FAIL(msg);
      case "level":
        if(usr->query_level() < cmp)
          FAIL(msg);
        break;
      case "xlevel":
        if(usr->query_extra_level() < cmp)
          FAIL(msg);
        break;
      case "bloodpts":
        if(gob->query_bloodpts() < cmp)
          FAIL(msg);
        break;
      case "glevel":
        if(usr->query_guild_rank() < cmp)
          FAIL(msg);
        break;        
      case "min_humanity":
        if(gob->query_humanity() > cmp)
          FAIL(msg);
        break;
      case "max_humanity":
        if(gob->query_humanity() < cmp)
          FAIL(msg);
        break;        
      default:
        if(!call_other(cmd, key, cmp, msg, target, usr, gob))
          return 0;
    }
  }
  return target?target:usr;
}



asses_costs(result, costs, usr, gob, cmd, heal, target) {
  string *cost_keys;
  int s;
  mixed cost;
  int x,y,z; /* for calculations */
  
  if(heal) gob->count_heal_usage();
  
  cost_keys = keys(costs);
  s = sizeof(cost_keys);
  while(s--) {
    cost = costs[cost_keys[s]];
    switch(cost_keys[s]) {
      case "debuff":
        COMDAEM->consume_debuff(target, cost[0], cost[1]);
        break;
      case "sp":
        usr->add_spell_point(cost);
        break;
      case "gold":
        usr->add_money(cost);
        break;
      case "btox_heal":
        y = gob->query_tox_pref();
        gob->affect_btox(y);
        z = HEALDAEM->heal_cost(cost, y);
        gob->affect_tribute(-z);
        break;
      case "ttox_heal":
        y = gob->query_tox_pref();
        gob->affect_ttox(y);
        z = HEALDAEM->heal_cost(cost, y);
        gob->affect_tribute(-z);
        break;
      case "ctox_heal":
        y = gob->query_tox_pref();
        gob->affect_ctox(y);
        z = HEALDAEM->heal_cost(cost, y);
        gob->affect_tribute(-z);
        break;
      case "humanity_decline":
        if(!random(cost))
          gob->affect_humanity(-1);
        break;
      case "humanity_increase":
        if(!random(cost))
          gob->affect_humanity(1);
        break;
      case "tribute":
        gob->affect_tribute(cost);
        break;
      case "btox":
        gob->affect_btox(cost);
        break;
      case "ctox":
        gob->affect_ctox(cost);
        break;
      case "ttox":
        gob->affect_ttox(cost);
        break;
      default:
        call_other(cmd, cost_keys[s], cost, result, usr, gob);
    }
  }
}

emote(str, usr, target) {
  return EMOTER(str, usr, target);
}

do_emote(s, r, t, usr, target) {
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