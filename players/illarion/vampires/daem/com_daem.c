/* Combat Daemon
   Handles matters related to buffing and debuffing
   and damage calculation
 */ 
#include "../def.h"
mapping sp_weps;

reset() {
  if(!sp_weps) sp_weps = ([]);
}

get_debuff(targ) {
  object debuff;
  debuff = present(DEBUFFID, targ);
  if(!debuff) {
    debuff = clone_object(DEBUFF);
    move_object(debuff, targ);
    debuff->set_victim(targ);
  }
  return debuff;
}

get_debuff_monstr(gob, usr) {
  object att, debuff;
  mixed dmap, dkeys;
  int s;
  att = usr->query_attack();
  if(!att || !present(att, ENV(usr))) return "";
  debuff = get_debuff(att);
  dmap = debuff->query_debuffs();
  dkeys = keys(dmap);
  s=sizeof(dkeys);
  if(s==0) return "";
  while(s--) dkeys[s] = dkeys[s][0..0];
  return "["+implode(dkeys,"|")+"]";
}

check_debuff(targ, cmp) {
  object debuff;
  debuff = get_debuff(targ);
  return debuff->check_debuff(cmp);
}

consume_debuff(targ, type, amt) {
  object debuff;
  if(!targ) return 0;
  debuff = get_debuff(targ);
  debuff->consume_debuff(type, amt);
}

add_debuff(targ, type, str, dur) {
  object debuff;
  debuff = get_debuff(targ);
  debuff->add_debuff(type, str, dur);
}

do_emote(r, t, targ) {
  DAEM->do_emote(t, r, 0, targ, 0);
}

start_debuff_emote(targ, type) {
  string r,t;
  switch(type) {
    case "bleeding":
      t = "You start to bleed.\n";
      r = "#MN# starts to bleed.\n";
      break;
    case "dazed":
      t = "You are dazed.\n";
      r = "#MN# is dazed.\n";
      break;    
    case "rot":
      t = "Pain and fear spread through you.\n";
      r = "#MN# looks frightened and in pain.\n";
      break;    
  }
  do_emote(r, t, targ);
}

add_debuff_emote(targ, type) {
  string r,t;
  switch(type) {
    case "bleeding":
      t = "Your bleeding gets worse.\n";
      r = "#MN#'s bleeding gets worse.\n";
      break;
    case "dazed":
      t = "Your daze deepens.\n";
      r = "#MN#'s daze deepens.\n";
      break;   
    case "rot":
      t = "Your sense of pain and fear deepens.\n";
      r = "#MN# looks even more frightened and in pain.\n";
      break;        
  }
  do_emote(r, t, targ);
}

end_debuff_emote(targ, type) {
  string r,t;
  switch(type) {
    case "bleeding":
      t = "You stop bleeding.\n";
      r = "#MN# stops bleeding.\n";
      break;
    case "dazed":
      t = "You are no longer dazed.\n";
      r = "#MN# is no longer dazed.\n";
      break;    
    case "rot":
      t = "The poison causing you pain and fear has burned away.\n";
      r = "#MN# no longer looks as frightened and in pain.\n";
      break;          
  }
  do_emote(r, t, targ);
}

debuff_effect_emote(targ, type) {
  string r,t;
  switch(type) {
    case "bleeding":
      t = "You bleed.\n";
      r = "#MN# bleeds.\n";
      break;
    case "dazed":
      t = "You wobble from your daze.\n";
      r = "#MN# wobbles from #MP# daze.\n";
      break;    
    case "rot":
      t = "Your pain and fear hinders your attacks.\n";
      r = "#MN#'s attacks are hindered by #MP# pain and fear.\n";
      break;        
  }
  do_emote(r, t, targ);
}

do_spell_damage(usr, gob, att) {
  int dam;
  if(!sp_weps[usr]) return;
    
  dam = att->do_damage(sp_weps[usr][0], sp_weps[usr][1]);
  tell_object(usr, "Total spell damage: "+dam+"\n");
  sp_weps[usr] = 0;
}

guild_attack_bonus(usr, gob, att) {
  int chk, bonus;
  int btox;
  
  do_spell_damage(usr, gob, att);
  
  btox = gob->query_btox();
  if(!btox) {
    tell_object(usr,"No btox - no offense bonus.\n");
    return 0;
  }
  
  chk = gob->check_skill("Celerity");
  bonus = (5+btox/5)*chk;
  tell_object(usr,"Extra Hit:");
  if(chk > 0) {
    tell_object(usr,"Success: "+bonus+"\n");
    if(chk == 2) {
      tell_object(usr,"Critical Success: "+bonus+"\n");
    }
    usr->RegisterWeapon(gob, ({ "physical", bonus, "vamp_extra_hit" }));
  } else {
    tell_object(usr,"Fail: "+bonus+"\n");
    if(chk < 0) {
      tell_object(usr,"Critical Fail: "+bonus+"\n");
      usr->add_hit_point(-bonus);
      return 0;
    }
  }
  return 0;
}

extra_attack_bonus(usr, gob, att) {
  object wep;
  int dam;
  tell_object(usr, "extra_attack_bonus\n");
  dam = guild_offense_bonus(usr, gob, att);
  if((wep = usr->query_weapon()))
    dam += wep->hit(att);
  return dam;
}

extra_attack_message_hit(dam, usr, gob) {
  object wep;
  tell_object(usr, "extra_attack_message_hit\n");
  if((wep = usr->query_weapon()))
    return wep->query_message_hit(dam);
}

guild_offense_bonus(usr, gob, att) {
  int chk,bonus;
  int btox;
  
  btox = gob->query_btox();
  tell_object(usr, "guild_offense_bonus called.\n");
  if(!btox) return 0;
  chk = gob->check_skill("Fortitude");  
  bonus = (5+btox/5) * chk;
  write("WC_BONUS: ");
  if(chk > 0) {
    write("Extra Damage: "+bonus+"\n");
    if(chk == 2)
      write("Critical hit: "+bonus+"\n");
  } else if(chk < 0) {
    write("Critical fail: "+bonus+"n");
  } else {
    write("fail: "+bonus+"\n");
  }
  return bonus;  
}

setup_bonuses(usr, gob) {
  usr->RegisterArmor(gob, ({"physical", 0, 10, "vampire_defense_bonus",
                            "other|fire", 0, -50, "vampire_fire_weakness",
                            "other|light", 0, -50, "vampire_light_weakness",
                            "other|dark", 0, 25, "vampire_dark_resistance",
                            "other|poison", 0, 25, "vampire_poison_resistance",
  }) );
  usr->RegisterWeaponBonus(gob, ({"physical", 0, "vampire_offense_bonus"}));
}

get_armor_weight(usr) {
  object *arm;
  int s,wt;
  arm = usr->QueryArmors();
  arm = keys(arm);
  s=sizeof(arm);
  while(s--)
    if(arm[s]) 
      wt+=arm[s]->query_weight();
}

guild_defense_bonus(usr, gob, dam) {
  object att;
  int btox;
  int cchk, fchk;
  int ac, res;
  int wt;
  att=TP;
  if(TP==usr) { /* hitting ourself.  could do something with this later */ return 0; }
  btox = gob->query_btox();
  if(!btox) {
    tell_object(usr,"No btox - no defense bonus.\n");
    return 0;
  }
  wt = get_armor_weight(usr) * 2;
  if(wt < 10) wt = 0;
  
  cchk = gob->check_skill("Celerity",  - wt - (25 * gob->count_dodge_attempt()) );
  fchk = gob->check_skill("Fortitude");
  tell_object(usr,"Dodge Physical: ");
  if(cchk > 0) {
    tell_object(usr,"Success!\n");
    if(cchk == 2) {
      tell_object(usr,"Critical!\n");
    }
    res = 100;
  } else {
    tell_object(usr,"Fail!\n");
    if(cchk < 0)
    {
      tell_object(usr,"Critical Fail!\n");
      res = -100;
    }
  }
  tell_object(usr,"AC physical");
  ac = (5+btox/5) * fchk;
  if(fchk > 0) {
    tell_object(usr,"Success: "+ac+"\n");
    if(fchk == 2) {
      ac *= 2;
      tell_object(usr,"Critical: "+ac+"\n");
    }
  } else {
    tell_object(usr,"Fail: "+ac+"\n");
    if(fchk < 0)
    {
      tell_object(usr,"Critical Fail: "+ac+"\n");
    }
  }
  return 100*res + ac;
}

get_spell_object(usr) {
  return sp_weps[usr];
}

set_spell_object(usr, params) {
  sp_weps[usr] = params;
}

/* Combine multiple spells cast in a round into one spell_object amount */
combined_spell_object(usr, gob, target, name, dam, dtype, s, t, r) {
  string cname;
  int cdam;
  string *custom;
  cdam = usr->query_spell_dam();
  cname = usr->query_spell_name();
  if(cdam && cname != name) {
    tell_object(usr, "Unable to combine spells.  (This should not happen.)\n");
    return 0;
  }
  
  custom = gob->get_custom_emote(name);
  if(sizeof(custom) == 3)
  {
    s = custom[0];
    t = custom[1];
    r = custom[2];
  }
  
  DAEM->do_emote(s, r, t, usr, target);
  usr->spell_object(target, name, cdam+dam, 0, "","","");
  usr->set_spell_dtype(dtype);
  
  return 1;
}