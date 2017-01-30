/* daem.c - does most of the actual work
 */

#include "../def.h"

/* These values control how much of a bonus is awarded
 * whem the enhanced damage and critical strile skill
 * checks succeed
 */
#define ENHANCED_BONUS 150
#define CRITICAL_BONUS 200

/* The weight of the armor used is multiplied by this
   value to establish a penalty to parry and dodge
 */
#define ARMOR_PENALTY 5

mapping skills;
mapping skill_messages;
string *power_list;
string *doc_list;

/* Skills
 *
 * The rules are the same as in my skills.txt document, although the
 * implentation is altered a bit because the skill structure for the
 * guild is static.
 */

void reset(status arg) {
  int x,s;
  string *templist,tmp;
  if(!power_list) {
    power_list=({});
    templist=get_dir(POWER_DIR+"*");
    s=sizeof(templist);
    for(x=0;x<s;x++)
      if(sscanf(templist[x],"%s.c",tmp))
        power_list+=({tmp});
  }
  if(!doc_list) {
    doc_list=({});
    templist=get_dir(DOC+"*.txt");
    s=sizeof(templist);
    for(x=0;x<s;x++)
      if(sscanf(templist[x],"%s.txt",tmp))
        doc_list+=({tmp});
  }

  if(!skills)
    skills=(["extra attack":({"dex","int",100,75,25,10,100}),
             "enhanced damage":({"str","int",100,75,25,10,100}),
             "critical strike":({"int","int",100,75,25,10,100}),
             "dodge":({"dex","int",100,75,25,10,100}),
             "parry":({"con","int",100,75,25,10,100}),
             "armor use":({"int","int",100,75,25,10,100}),
             "counter":({"str","int",100,75,25,10,100}),
           ]);
  if(!skill_messages)
    skill_messages=(["dodge":({"[*]You deftly step out of the way of $AN$'s attack.",
                               "$PN$ deftly steps out of the way of your attack.",
                               "$PN$ deftly steps out of the way of $AN$'s attack.",
                               "[*]You roll out of harm's way.",
                               "$PN$ rolls out of harm's way."}),
                     "dodgefail":({"[-]You fail to dodge $AN$'s attack.","","",
                                   "You fail to dodge out of harm's way.",""}),
                     "dodgecrit":({"[!]You attempt to dodge, but step directly into $AN$'s attack!",
                                   "$PN$ steps directly into your attack!",
                                   "$PN$ steps directly into $AN$'s attack!",
                                   "[!]You try to roll out of harm's way, but roll into it instead!",
                                   "$PN$ rolls directly into harm's way!"}),
                     "parry":({"[*]You parry $AN$'s attack with your blade.",
                               "$PN$'s blade blocks your attack.",
                               "$PN$ blocks $AN$'s attack with $PP$ blade.",
                               "[*]You angle your sword and deflect an attack.",
                               "$PN$ angles $PP$ sword and deflects an attack."}),
                     "parryfail":({"[-]You fail to parry $AN$'s attack.","","",
                                   "You fail to deflect any damage.",""}),
                     "parrycrit":({"[!]You deflect $AN$'s attack, right toward a more vulnerable spot!",
                                   "$PN$ deflects your attack, but toward a more vulnerable spot!",
                                   "$PN$ deflects $AN$'s attack, but toward a more vulnerable spot!",
                                 }),
                     "armor use":({"[*]You shift into $AN$'s attack, catching it on your armor.",
                                   "$PN$ catches your attack on a piece of $PP$ armor.",
                                   "$PN$ catches $AN$'s attack on a piece of $PP$ armor.",
                                   "You shift your armor into harm's way.",
                                   "$PN$ shifts $PP$ armor into harm's way."
                                 }),
                     "armor usefail":({"[-]You aren't able to use your armor to block additional damage.",
                                  "","",
                                  "[-]You aren't able to use your armor to block additional damage.",
                                  ""}),
                     "armor usecrit":({"[!]Your attempt to shift your armor leaves you more vulnerable to attack!",
                                  "","",
                                  "[!]Your attempt to shift your armor leaves you more vulnerable to attack!",
                                  ""}),
                     "extra attack": ({ "[*]Moving at blinding speed, you unleash another attack!",
                                        "$PN$'s form blurs, and $PR$ attacks you again!",
                                        "$PN$'s form blurs, and $PR$ attacks $AN$ again!",
                                        "[*]Your sword blurs, and you unleash another attack!",
                                        "$PN$'s form blurs, and another $PN$ attacks!",
                                      }),
                      "extra attackfail":({"[-]You don't see an opportunity for another attack.",
                                           "","",
                                           "[-]You don't see an opportunity for another attack.",
                                           ""
                                         }),
                      "extra attackcrit":({
                        "[!]You attempt another attack, but leave yourself critically open instead!",
                        "$PN$ leaves $PO$self critically open to attack from you!",
                        "$PN$ stumbles, leaving $PO$self critically open to attack!",
                        "",
                        ""
                      }),
                      "critical strike":({"[*]You aim at an especially vulnerable part of $AN$.",
                                          "$PN$'s strikes at one of your vulnerable points.",
                                          "$PN$'s strike at $AN$ changes subtly.",
                                          "",
                                          ""
                                        }),
                      "critical strikefail":({"[-]You fail to correctly aim at a vulnerable point",
                                              "",
                                              "",
                                              "",
                                              ""
                                            }),
                      "critical strikecrit":({"[!]Your strike goes critically awry, leaving you off-balance.",
                                              "$PN$'s strike goes wild, leaving $PO$ off-balance.",
                                              "$PN$ strikes wildly, and seems off-balance.",
                                              "",
                                              ""
                                            }),
                      "enhanced damage":({"[*]Power flows through your arms as you strike.",
                                          "",
                                          "",
                                          "",
                                          ""
                                        }),
                      "enhanced damagefail":({"[-]You fail to properly apply your strength to your attack.",
                                              "",
                                              "",
                                              "",
                                              ""
                                            }),
                      "enhanced damagecrit":({"[!]You overextend trying to add power to your strike, and leave yourself off-balance.",
                                              "$PN$ swings too hard, leaving $PO$self vulnerable.",
                                              "$PN$ swings too hard, and stumbles a bit.",
                                              "",
                                              ""
                                            }),
                      "counter":({"[*]Sensing an opening following your successful defense, you launch a counter-attack!",
                                  "$PN$ takes advantage of an opening you left, and launches a counter-attack!",
                                  "$PN$ takes advantage of an opening left by $AN$, and launches a counter-attack!",
                                  "",
                                  ""
                                }),
                      "counterfail":({"[-]You seek an opening to counter-attack, but don't sense one.",
                                      "",
                                      "",
                                      "",
                                      ""
                                    }),
                      "countercrit":({"[!]You attempt to counter $AN$'s attack, but misjudge and leave yourself open instead!",
                                      "$PN tries to counter your attack, but misjudges and leaves $PO$self vulnerable instead.",
                                      "$PN$ tries to counter $AN$'s attack, but leaves $PO$self vulnerable to attack instead.",
                                      "",
                                      ""
                                    }),
                       "grip":({"","","",
                                "You shift to a two-handed grip on your sword.",
                                "$PN$ shifts to a two-handed grip on $PP$ sword.",
                              }),
                       "gripfail":({"","","",
                                    "You return to a normal grip on your sword.",
                                    "$PN$ stops gripping $PP$ sword in both hands."
                                  }),
                     ]);
}
/* Emotes for skills and other occasions */

string code_resolve(string code, object p, object a) {
  switch(code) {
    case "PN": return QN(p);
    case "PP": return POS(p);
    case "PR": return PRO(p);
    case "PO": return OBJ(p);
    case "AN": return QN(a);
    case "AP": return POS(a);
    case "AR": return PRO(a);
    case "AO": return OBJ(a);
    default: return "error";
  }
}

string parse_spam(string str, object p, object a) {
  string before,mid,after;
  while(sscanf(str,"%s$%s$%s",before,mid,after)>=2)
    str=(before?before:"")+code_resolve(mid,p,a)+(after?after:"");
  return str+"\n";
}

void do_skill_spam(string skill_name,object gob,object owner,object att,int result) {
  string *message;
  int slevel;
  object room;
  slevel=(int)gob->query_spam_level();
  if(!slevel) return;
  if(result==0) {
    skill_name+="fail";
  }
  else if(result==-1) {
    skill_name+="crit";
  }
  if(!member(skill_messages,skill_name))
    return;
  room=environment(owner);
  message=skill_messages[skill_name];
  if(att) {
    if(message[0]!="")
      tell_object(owner,parse_spam(message[0],owner,att));
    if(slevel==2) {
      if(message[1]!="")
        tell_object(att,parse_spam(message[1],owner,att));
      if(room && message[2]!="")
        tell_room(room,parse_spam(message[2],owner,att),({owner,att}));
    }
  } else {
    if(message[3]!="")
      tell_object(owner,parse_spam(message[3],owner,att));
    if(room && slevel==2 && message[4]!="")
      tell_room(room,parse_spam(message[4],owner,att),({owner}));
  }

}

/* Skill checking code */

int check_skill(string skill_name,object guild_ob,object owner,object attacker,int bonus) {
  int skill_roll,difficulty_roll,practice_roll,practice_difficulty_roll;
  int use_attrib_bonus,practice_attrib_bonus;
  int skill_level;

  int result;
  skill_level=(int)guild_ob->query_skill_level(skill_name);
  if(!member(skills,skill_name))
    return 0;
  skill_roll=random(skill_level+1);
  use_attrib_bonus=(int)owner->query_attrib(skills[skill_name][0])-10;
  difficulty_roll=random(skills[skill_name][2]+use_attrib_bonus);
  practice_attrib_bonus=(int)owner->query_attrib(skills[skill_name][1])-10;
  if(difficulty_roll != skills[skill_name][2]-1 && ( difficulty_roll == 0 || skill_roll+bonus >= difficulty_roll)) {
    practice_roll=random(skills[skill_name][3]);
    difficulty_roll=random(100);
    if(practice_roll+practice_attrib_bonus >= difficulty_roll) {
      guild_ob->add_practice(skill_name,1);
    }
    result=1;
  } else {
    practice_roll=random(skills[skill_name][4]);
    difficulty_roll=random(100);
    if(practice_roll+practice_attrib_bonus >= difficulty_roll) {
      guild_ob->add_practice(skill_name,0);
    }
    if(!random(100+skill_level)) /* critical failure */
      result=-1;
    else
      result=0;
  }
  do_skill_spam(skill_name,guild_ob,owner,attacker,result);
  return result;
}

int practices_needed(int skill_level,int train_difficulty) {
  int train_difficulty_divisor;
  train_difficulty_divisor=10;
  return skill_level * (train_difficulty + train_difficulty*skill_level/train_difficulty_divisor);
}

practice_scale(string skill_name,int skill_level,int practices) {
  return SCALE->show_scale(practices,practices_needed(skill_level,skills[skill_name][5]),10);
}

int experience_needed(int skill_level,int train_cost) {
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

int check_skill_advance(string skill_name,object gob,object owner) {
  status enough_practices,enough_experience;
  int skill_level,practices;
  if(!member(skills,skill_name))
    return 0;
  skill_level=(int)gob->query_skill_level(skill_name);
  practices=(int)gob->query_practices(skill_name);

  enough_practices=(practices >= practices_needed(skill_level,skills[skill_name][5]));

  enough_experience=(experience_free(owner) > experience_needed(skill_level,skills[skill_name][6]));

  if(enough_experience && enough_practices)
    return 1;
  if(!enough_practices && !enough_experience)
    return -3;
  if(!enough_practices)
    return -2;
  return -1;
}

int advance_skill(string skill_name,object gob,object owner) {
  if(!member(skills,skill_name))
    return 0;

  if(check_skill_advance(skill_name,gob,owner) != 1)
    return -1;
  owner->add_exp(-experience_needed((int)gob->query_skill_level(skill_name),skills[skill_name][6]));
  gob->raise_skill(skill_name);
  return 1;
}

mixed *init_skills() {
  return ({"extra attack",1,0,"enhanced damage",1,0,"critical strike",1,0,
  "dodge",1,0,"parry",1,0,"armor use",1,0,"counter",1,0});
}

/* Max bonuses in ac and wc.  They also can't be greater than the wc of
   the weapon wielded for wc, or the ac of the armor worn for the armor.

   To get a wc bonus of 20, the player needs a wc 20 weapon, and an average
   of 100 or higher in the attack skills

   To get an ac bonus of 15, the player has to already be wearing armor
   with an ac of 15, plus have an average of 100 or higher in the defense
   skills.
 */

int calc_max_wc(object gob) {
  int wc;
  wc=10+((int)gob->query_skill_level("enhanced damage")+
        (int)gob->query_skill_level("critical strike")+
        (int)gob->query_skill_level("extra attack"))/30;
  if(wc>20) wc=20;
  return wc;
}

int calc_max_ac(object gob) {
  int ac;
  ac=5+((int)gob->query_skill_level("parry")+
        (int)gob->query_skill_level("dodge")+
        (int)gob->query_skill_level("armor use"))/30;
  if(ac>15) ac=15;
  return ac;
}

/* Combat calculations and spammage */

/* Determines the appropriate spammage (or lack of it) given what happened
   during defensive checks.  The spammage depends on the various checks.
   dodgecheck/parrycheck 2 - the attack was immediately doded/parried for no damage.
   dodgecheck 1/parrycheck 1 - succeeded, but after a failure from the other skill
   armorusecheck 1 - armoruse check succeeded, and double ac is applied
   0 in anything means the check failed
   -1 in anything means a critical failure (extra damage for dodge parry unless
     the other one succeeded, negative ac for armor use)


 */

int attempt_counter(object owner,object att,object gob) {
  int check;
  object room;
  check=check_skill("counter",gob,owner,att,0);
  room=environment(owner);
  /* Simulate an attack */
  if(check==1 && att && room && present(att,room) && gob->check_weapon()) {
    int dam;
    object wep;
    string *mess,name;
    wep=(object)gob->query_weapon();
    dam=(int)wep->weapon_class();
    dam+=(int)wep->hit(att);
    /* No extra attacks for counterattacks */
    gob->set_no_extra(1);
    dam+=(int)gob->gen_wc_bonus(att);
    /* Make sure the counter doesn't kill the target, that could break something */
    if(dam>(int)att->query_hp())
      dam=(int)att->query_hp()-1;
    dam=(int)att->hit_player(random(dam),"physical");
    if(dam==0) {
      mess=({"","missed"});
      wep->count_misses();
    } else {
      mess=(mixed)wep->query_message_hit(dam);
      wep->count_hit_made();
    }
    name=QN(att);
    tell_object(owner,"You "+mess[1]+" "+name+mess[0]+".\n");
    tell_room(room,QN(owner)+" "+mess[1]+" "+name+mess[0]+".\n",({owner}));
  }
  return check;
}

int calc_defense(object owner,object attacker,object gob,int def_round,int dmod,int armor_wt) {
  object wep;
  int dcheck,pcheck,vcheck,ccheck;
  int modifier;
  int final_return;
  int ac;
/* used to ensure only one counter-attack is attempted per attack by
   an enemy */
  int counter_attempted;

  wep=(object)gob->query_weapon();
  modifier = -(def_round*10) + dmod;
  armor_wt*=ARMOR_PENALTY;
  /* 50% dodge checked first, 50% parry */
  if(random(2)) {
    dcheck=check_skill("dodge",gob,owner,attacker,modifier+armor_wt);
    if(dcheck==1) {
      if(!counter_attempted) {
        counter_attempted;
        if(attempt_counter(owner,attacker,gob)==-1)
          dcheck=-1;
        else
          return 10000;
      } else
        return 10000;
    }
    pcheck=check_skill("parry",gob,owner,attacker,modifier+armor_wt);
    if(pcheck==1) {
      gob->set_no_extra(1);
      wep->count_hit_made();
      if(!counter_attempted) {
        counter_attempted;
        if(attempt_counter(owner,attacker,gob)==-1)
          pcheck=-1;
        else
          return 10000;
      } else
        return 10000;
    }
  } else {
    pcheck=check_skill("parry",gob,owner,attacker,modifier+armor_wt);
    if(pcheck==1) {
      gob->set_no_extra(1);
      wep->count_hit_made();
      if(!counter_attempted) {
        counter_attempted;
        if(attempt_counter(owner,attacker,gob)==-1)
          pcheck=-1;
        else
          return 10000;
      } else
        return 10000;
    }
    dcheck=check_skill("dodge",gob,owner,attacker,modifier+armor_wt);
    if(dcheck==1) {
      if(!counter_attempted) {
        counter_attempted;
        if(attempt_counter(owner,attacker,gob)==-1)
          dcheck=-1;
        else
          return 10000;
      } else
        return 10000;
    }
  }
  /* -100% resistance for 1 failure, -200% resistance for 2 */
  final_return = 10000*(dcheck+vcheck);
  /* If the player is wearing armor, they get double ac, unless this skill
     fails, in which case they get normal ac, or, in the case of a critical
     failure, they end up with 0ac
  */
  ac=(int)gob->query_base_ac();
  if(ac > 0) {
    vcheck=check_skill("armor use",gob,owner,attacker,modifier);
    if(vcheck==1 && !counter_attempted)
      if(attempt_counter(owner,attacker,gob)==-1)
        vcheck=-1;
  }
  /* subtract 0*ac for normal ac, 1*ac for 0ac, or 2*ac for -ac */
  final_return += (vcheck-1)*(ac);
  return final_return;
}

/* Determines how much damage is done by the weapon */

int calc_damage(object owner,object victim,object gob,int wc,int mod) {
  int echeck,ccheck;
  int result;
  echeck=check_skill("enhanced damage",gob,owner,victim,mod);
  ccheck=check_skill("critical strike",gob,owner,victim,mod);
  result=wc;
  /* any critical failure should cause a miss */
  if(echeck==-1) {
    gob->add_temp_d_mod(-30);
    gob->set_no_extra(1);
    result=0;
  }
  if(ccheck==-1) {
    gob->add_temp_d_mod(-40);
    gob->set_no_extra(1);
    result=0;
  }
  if(echeck==1)
    result=result*ENHANCED_BONUS/100;
  if(ccheck==1)
    result=result*CRITICAL_BONUS/100;
/* subtract wc back out, as it's already there in the weapon
 * this gives a final result between 0 and 2x WC
 */
  return result-wc;
}

int extra_attack(object owner,object victim,object gob,int num_attempts,int mod) {
  int check;
  int attempts_mod;
  /* Progressively greater penalties for each additional attack:
     -10,-30,-60,-100,-150,-210,-280, etc.
     ie technically unlimited but greatly diminishing returns
   */
  while(num_attempts) {
    attempts_mod+=num_attempts;
    num_attempts--;
  }
  attempts_mod*=-10;
  check=check_skill("extra attack",gob,owner,victim,attempts_mod+mod);
  if(check==1)
    return 1;
  if(check==-1)
    previous_object()->add_temp_d_mod(-20);
  return 0;
}

void prac_spam(object owner,string skill_name,status type) {
  object gob;
  gob=present(OB_NAME,owner);
  if(!gob || !gob->query_spam_level()) return;
  if(type) tell_object(owner,"You've learned something new about "+skill_name+".\n");
  else tell_object(owner,"Failure teaches you something new about "+skill_name+".\n");
}

string *query_power_list() {
  return power_list;
}

string *query_doc_list() {
  return doc_list;
}

/* Weapon Shadowing */

void kill_shadow(object weapon,object owner) {
  if(!weapon || !owner) return;
  weapon->remove_bm_shadow();
}

void set_shadow(object weapon,object owner,object gob) {
  object shad;
  if(!weapon || !owner) return;
  shad=clone_object(GDIR+"misc/weap_shadow.c");
  shad->start_bm_shadow(weapon,owner,gob);
  return;
}
