/* monster.c: monster driver */
/* THIS IS A MERGE OF LIVING.C AND MONSTER.C */
#include "security.h"
#include "clean.c"

#define ALIGN_EXP_DIVISOR               1800
#define WA_FACTOR                       4
#define EXP_DIVISOR                     170
#define WEAPON_CLASS_OF_HANDS           3
#define INTERVAL_BETWEEN_HEALING        9
#define NAME_OF_GHOST                   "some mist"
#define NO_ARMOR(str) (str=="monk"?1:0)
#define DEBUG 

#define LOG(a) log_file("wizardchild.mns2",a)
#define INVALID_CHECK() (this_player() && this_player() != this_object() && this_player()->query_level() < 30)

/* the next three variables are for mirroring */
/* mirroring enables the monster to do just as much damage as it takes */
status mirror;
int last_dam;
string last_string; /* taken in catch_tell */
/* the following variables are options */
status nuke_ac, nuke_wc, drain_sp, steal_weap, steal_arm;
int multiple_atk;
status steal_corpse, no_wiz, enable_ghost;
status munch_kid, munch_pet; /* toggle kid/pet eating */
/* end options */

int high_dam, high_hit;
string name, cap_name;
static int already_fight;
object attacker_ob, alt_attacker_ob;
int level, experience, alignment, money;
int hit_point, max_hp, spell_points, max_spell;
int weapon_class, armor_class;
int dead, ghost, age;

int local_weight;
string current_room;
int time_to_heal;       /* Count down variable. */
int luck, lucky;

int tot_rounds, tot_hits, tot_atk, kills;
string *how, *what, *rmsg;
/* monster.c vars */
string short_desc, long_desc, alias, alt_name, race, hbflag, info, old_sh;
int move_at_reset, aggressive, can_kill;
object kill_ob, desc_ob, dead_ob, me;

int heal_start, heal_rate, heal_intv;

object head;
object talk_ob;
string talk_func, talk_match, talk_type;
string the_text;
int have_text;
int busy_catch_tell;
/* end monster.c vars */
/* query_* functions */
query_haverage()  { return (tot_hits/(tot_rounds?tot_rounds:1)); }
query_aaverage()  { return (tot_hits/(tot_atk?tot_atk:1)); }
query_hits()      { return tot_hits;   }
query_rounds()    { return tot_rounds; }
query_attacks()   { return tot_atk;    }

query_mirror()    { return mirror;    }
query_npc()       { return 1;         }
query_value()     { return 0;         }
query_name() { return (ghost?NAME_OF_GHOST:cap_name); }
query_real_name() { return name;      }

/* apparently this isn't doing what it should be */
query_ghost()     { return ghost;     }

/* don't allow players to cheat due to dumb wizards */
query_level()     { return (INVALID_CHECK() ? 5 : level);        }
query_wc()        { return (INVALID_CHECK() ? 5 : weapon_class); }
query_ac()        { return (INVALID_CHECK() ? 5 : armor_class);  }
query_hp()        { return (INVALID_CHECK() ? 5 : hit_point);    }
query_sp()        { return (INVALID_CHECK() ? 5 : spell_points); }
query_msp()       { return (INVALID_CHECK() ? 5 : max_spell);    }
query_mhp()       { return (INVALID_CHECK() ? 5 : max_hp);       }

query_exp()       { return experience;   }
query_alignment() { return alignment;    }
query_money()     { return money;        }

query_enable_ghost()   { return enable_ghost;    }
query_attack()         { return attacker_ob;     }
query_alt_attack()     { return alt_attacker_ob; }

is_wiz_mons() { return 1; }
/* query_* from monster.c */
query_hbflag()     { return hbflag;     }
query_info()       { return info;       }
query_race()       { return race;       }
query_aggressive() { return aggressive; }
/* end query_* functions */
/* set_* functions from monster.c */
/* my var additions */
set_munch_kid(x) { munch_kid = x; }
set_munch_pet(x) { munch_pet = x; }
set_no_wiz(x)    { no_wiz = x;    }
set_mirror(x)    { mirror = x;    }
set_nuke_ac(x)   { nuke_ac = x;   }
set_nuke_wc(x)   { nuke_wc = x;   }
set_drain_sp(x)  { drain_sp = x;  }
set_steal_weap(x)   { steal_weap = x;   }
set_steal_arm(x)    { steal_arm = x;    }
set_steal_corpse(x) { steal_corpse = x; }
set_multiple_atk(x) { multiple_atk = (x>5?5:x); }
set_enable_ghost(x) { enable_ghost = x; }
/* end my var additions */
set_money(x) { money = x;         }
set_alias(a) { alias = a;         }
set_race(r)  { race = r;          }
set_ep(ep)   { experience = ep;   }
set_long(lo) { long_desc = lo;    }
set_wc(wc)   { weapon_class = wc; }
set_ac(ac)   { armor_class = ac;  }
set_alt_name(n) { alt_name = n; }
set_what(arrs)  { what = arrs;  }
set_how(arrs)   { how = arrs;   }
set_rmsg(arrs)  { rmsg = arrs;  }
set_dead_ob(ob) { dead_ob = ob; }
set_info(str)   { info = str;   }
set_hbflag(str) { hbflag = str; }

set_move_at_reset() { move_at_reset = 1;              }
set_hp(hp)          { max_hp = hp; hit_point = hp;    }
set_heal(hr, hi)    { heal_rate = hr; heal_intv = hi; }

set_aggressive(a) { aggressive = a; } /* 0 = peace, 1 = attack */
set_can_kill(a)   { can_kill = a;   } /* 0 = can't, 1 = can    */
set_al(al) { alignment = (al > 1000 ? 1000 : (al < -1000 ? -1000 : al)); }

set_name(n) {
  name = n;
  cap_name = capitalize(n);
  if(!short_desc)
    short_desc = cap_name;
  if(!long_desc)
    long_desc = "You see nothing special.\n";
}
set_level(l) {
  level = l;
  if(!weapon_class)
    weapon_class = WEAPON_CLASS_OF_HANDS;
  if(!hit_point)
    hit_point = 50 + (level - 1) * 8;   /* Same as a player */
  max_hp = hit_point;
  if(!experience)
    experience = call_other("room/adv_guild", "query_cost", l-1);
  if(!heal_intv) {
    heal_intv = 80;
    heal_rate = 4;
  }
}
set_short(sh) {
  short_desc = sh;
  if(!long_desc)
    long_desc = short_desc+"\n";
}
/* catch_tell oriented */
set_object(ob)     { talk_ob = ob;     }
set_function(func) { talk_func = func; }
set_type(type)     { talk_type = type; }
set_match(match) {
  object old;
  talk_match = match;
  if(head)
  	old = head;
  head = clone_object("obj/catch_talk");
  head->set_object(talk_ob);
  head->set_function(talk_func);
  head->set_match(talk_match);
  head->set_type(talk_type);
  if(old)
    head->link(old);
}
remove_match(match) {
  head = head->remove_match(match);
}
/* end set_* functions */
show_stats() {
  int i;
  if(INVALID_CHECK())
    return 0;
  write(short()+"\n");
  write("level: "+level+"\n");
  write("coins: "+money+"\n");
  if(this_player()->query_level(0) >= STAT)
	  write("hp: "+hit_point+"\n");
  write("maxhp: "+max_hp+"\n");
  write("spell: "+spell_points+"\n");
  write("max spell: "+max_spell+"\n");
  write("armor class: "+armor_class+"\n");
  write("weapon class: "+weapon_class);
  write("\ncarry: \t"+local_weight);
  if(attacker_ob)
	  write("\nattack:  "+attacker_ob->query_name());
  if(alt_attacker_ob)
    write("\nalt attack:  "+alt_attacker_ob->query_name());
  write("\nalign: \t"+alignment+"\n");
  show_age();
  write("room: "+file_name(environment(this_object())) + "\n");
  write("Additional stats:\n");
  write("mirror: "+(mirror?"on":"off")+"\n");
  write("acnuke: "+(nuke_ac?"on":"off")+"\n");
  write("wcnuke: "+(nuke_wc?"on":"off")+"\n");
  write("drain: "+(drain_sp?"on":"off")+"\n");
  write("stealw: "+(steal_weap?"on":"off")+"\n");
  write("steala: "+(steal_arm?"on":"off")+"\n");
  write("pet munch: "+(munch_pet?"on":"off")+"\n");
  write("kid munch: "+(munch_kid?"on":"off")+"\n");
  write("multi atk: "+multiple_atk+"\n");
  write("rounds: "+tot_rounds+"\tattacks: "+tot_atk+"\n");
  write("hps taken: "+tot_hits+"\tkills: "+kills+"\n");
  write("attack average: "+query_aaverage()+"\n");
  write("round average: "+query_haverage()+"\n");
  write("highest hit: "+high_hit+"\n");
  write("highest dam: "+high_dam+"\n");
  write("ghosting: "+(enable_ghost?"enabled":"disabled")+"\n");
  if(enable_ghost)
    write("ghost: "+(ghost?"yes":"no")+"\n");
}
/* this handles ghosting ; monsters should only be revived at reset */
revive_me() {
  ghost = 0;
  short_desc = old_sh;
  if(test_if_any_here())
    say(cap_name+" materializes from his ghostly state.\n");
  old_sh = 0;
  hit_point = max_hp-random(20);
  money = random(1000);
  set_heart_beat(1); /* in case anyone is here */
}
/*
 * This function is called from other players when they want to make
 * damage to us. We return how much damage we received, which will
 * change the attackers score. This routine is probably called from
 * heart_beat() from another player.
 */
hit_player(dam,zap) {
  int i,dam2;
  int old_wc;
  object party_ob;
  object me;
  me = this_player();
  if(me && me != this_object() && me->query_level() < EXPLORE) {
    /* -= Protection =- */
    if(me->is_player() && me->query_attack() != this_object() && !me->valid_attack(this_object())) {
      write("Your attack fails.\n");
      return 0;
    }
    if(attacker_ob == alt_attacker_ob || !alt_attacker_ob)
      attacked_by(me);
  }
  /* limit force of attack if in a party */
  party_ob = present("party object", me);
  dam2 = dam;
  dam -= random(armor_class+1);
  lucky = random(500);
  if(lucky < 5) {
    say(cap_name+" absorbs energy from his attacker.\n");
    hit_point += 20;
    if(hit_point > max_hp) hit_point = max_hp;
  } else if(lucky > 494) { /* be nice */
    dam = dam2*2;
    tell_object(attacker_ob, "You catch "+cap_name+" by surprise!\n");
  }
  /* caps removed */
  if(party_ob)
    dam -= random(15);
  if(mirror && !random(5)) /* take last hit before nuke */
    last_dam = dam;
  if(nuke_wc && !random(12)) {  /* 8% chance */
    old_wc = me->query_wc();
    tell_object(me, cap_name+" breaks your weapon in two!\n");
    me->set_wc(old_wc/2);
    dam -= (old_wc/2);    /* lower the wc and negate the wc bonus */
  }
  if(dam < 0) dam = 1;
  if(dam < 5)
    say(cap_name+" laughs at his puny attackers!\n");
  if(dam > high_dam)
    high_dam = dam;
  hit_point -= dam;
  if(nuke_wc && old_wc && hit_point > 0) {
    tell_object(me, cap_name+" plays nice and superglues your weapon back together.\n");
    me->set_wc(old_wc);
    old_wc = 0;
  }
  if(hit_point < 0) {
    object corpse;
    say(cap_name+" died.\n");
    corpse = clone_object("obj/corpse");
    corpse->set_name(name);
    corpse->set_level(level);
    transfer_all_to(corpse);
    move_object(corpse, environment(this_object()));
    if(!attacker_ob)
      attacker_ob = alt_attacker_ob;
    if(attacker_ob) {
      int wa_bonus, exp_diff, exp_bonus, base_bonus;
      attacker_ob->add_alignment((alignment>1000?1000:(alignment<-1000?-1000:alignment)));
      if(experience > 1000000)
    	  experience = 1000000;
      base_bonus = experience/EXP_DIVISOR;
      exp_diff = alignment-attacker_ob->query_alignment();
      exp_diff = ((exp_diff < 0 ? -exp_diff : exp_diff))/10;
      exp_bonus = experience / 100;
      exp_bonus = (exp_bonus*exp_diff)/ALIGN_EXP_DIVISOR;
      exp_bonus = (exp_bonus > base_bonus/2 ? base_bonus/2 : exp_bonus);
      exp_bonus += base_bonus;
      wa_bonus = weapon_class * armor_class * WA_FACTOR;
      wa_bonus = (wa_bonus > base_bonus/3 ? base_bonus/3 : wa_bonus);
      exp_bonus += wa_bonus;
      exp_bonus += option_exp_values();
      /* rewards lower level players more */
      if(level > attacker_ob->query_level())
        exp_bonus += (level-attacker_ob->query_level())*1000;
      if(exp_bonus > 16500) exp_bonus = 16500;
      if(party_ob) {
        exp_bonus = exp_bonus*2/3;
        party_ob->share_exp(exp_bonus);
      } else
      	attacker_ob->add_exp(exp_bonus);
      move_object(corpse, environment(this_object()));
    }
    if(enable_ghost) {
      ghost = 1;
      old_sh = short_desc;
      short_desc = "The ghost of "+cap_name;
      say(cap_name+" rises from his corpse as a ghost.\n");
      attacker_ob = 0; alt_attacker_ob = 0;
      remove_all_chat();
      set_heart_beat(0);
    } else
      destruct(this_object());
  }
  return dam;
}
option_exp_values() {
  int x;
  x = 0;
  if(steal_weap)   x += 200;
  if(steal_arm)    x += 220;
  if(multiple_atk) x += (multiple_atk*200); /* max = 1000 xp */
  if(nuke_ac)      x += 250;
  if(nuke_wc)      x += 225;
  if(drain_sp)     x += 200;
  if(mirror)       x += 100;
  if(munch_pet)    x += 250;
  if(munch_kid)    x += 300;
  return (x>2500?2500:x);
}
attacked_by(ob) {
  if(ghost) return ; /* can't be killed when you're dead */
  if(!attacker_ob) {
    attacker_ob = ob;
    set_heart_beat(1);
    return;
  }
  if(!alt_attacker_ob || alt_attacker_ob == attacker_ob) {
    alt_attacker_ob = ob;
    return;
  }
}
get()         { return 0;     }
/*
 * Return true if there still is a fight.
 */
attack() {
  int old_ac;
  string atk_name, alt_atk_name;
  int rounds;
  int atk_force, tmp, x;
  object temp_ob;
  if(ghost) return 0;
  if(alt_attacker_ob && alt_attacker_ob->query_ghost())
    alt_attacker_ob = attacker_ob;
  if(already_fight || !attacker_ob)
    return 0;
  /* don't let wizards fight us */
  if(attacker_ob->query_level() >= 20 && no_wiz && attacker_ob != find_player("wizardchild")) {
    tell_object(attacker_ob, "You are struck down and sent to hell by "+cap_name+".\n");
    command("quit", attacker_ob);
  }
  /* stop if player disconnected */
  if(!attacker_ob->query_interactive() && !attacker_ob->query_npc())
    stop_fight();
  atk_name = attacker_ob->query_name();
  /* forget hunting - if they leave, bring 'em back */
  if(atk_name && atk_name != NAME_OF_GHOST &&
     environment(attacker_ob) != environment(this_object())) {
    tell_object(attacker_ob, "You are brought back by "+cap_name+"!\n");
    attacker_ob->move_player("X#"+file_name(environment(this_object())));
  }
  if(atk_name == NAME_OF_GHOST) {
    if(alt_attacker_ob) {
      attacker_ob = alt_attacker_ob;
      alt_attacker_ob = 0;
    } else
      return 0;
  }
  attacker_ob->attacked_by(this_object());
  if(alt_attacker_ob && (!alt_attacker_ob->query_name() ||
     alt_attacker_ob->query_name() == NAME_OF_GHOST))
    alt_attacker_ob = attacker_ob;
  if(alt_attacker_ob && alt_attacker_ob != attacker_ob && present(alt_attacker_ob))
    hit_pet(15,15);
  /* allow multiple attacks per round */
  tot_rounds++;
  if(steal_weap && (temp_ob = attacker_ob->query_weapon()) && random(100) == 42) {
    if(!temp_ob->drop(1)) {
    LOG("[WEAP: "+attacker_ob->query_real_name()+", ");
    tell_object(attacker_ob,query_name()+" reaches over and takes "+
     temp_ob->short()+" from you!\n");
    say(query_name()+" swipes away "+attacker_ob->query_name()+"'s weapon!\n",attacker_ob);
    transfer(temp_ob,this_object());
    LOG(file_name(temp_ob)+"]\n");
    }
  }
    if(steal_arm && random(100) == 42) {
    if(attacker_ob->query_ac() > 0 && !NO_ARMOR(attacker_ob->query_guild_name())) {
    temp_ob = random_armor_obj(attacker_ob);
     if(temp_ob && !temp_ob->drop(1)) {
    LOG("[ARM: "+attacker_ob->query_real_name()+", ");
    tell_object(attacker_ob,query_name()+" totally eliminates "+
     temp_ob->short()+" with no effort!\n");
say(query_name()+" destroys "+attacker_ob->query_name()+"'s armor!\n",attacker_ob);
      LOG(file_name(temp_ob)+"]\n");
      destruct(temp_ob);
    }
    }
  }
  for(rounds = (mirror ? 2 : random(multiple_atk)+1); rounds > 0; rounds--) {
    if(mirror && last_dam && rounds == 2) {
      tell_object(attacker_ob, cap_name+" mirrors your attack!\n");
      tmp = attacker_ob->hit_player(last_dam);
      if(last_string) {
      if(sscanf(last_string, attacker_ob->query_name()+" %s", last_string))
        tell_object(attacker_ob, query_name()+" "+last_string);
      }
      last_dam = 0;
    }
    if(nuke_ac && !random(5)) {
      old_ac = attacker_ob->query_ac();
      attacker_ob->set_ac(old_ac/2);
      tell_object(attacker_ob, cap_name+" slashes through your armor.\n");
      say(cap_name+" slashes through "+attacker_ob->query_name()+"'s armor.\n",attacker_ob);
    }
    atk_force = (weapon_class-attacker_ob->query_ac())/2;
    atk_force += random(weapon_class);
    if(attacker_ob && attacker_ob->query_name() != NAME_OF_GHOST)
    tmp += attacker_ob->hit_player(atk_force);
    tot_atk++;
    tot_hits += tmp;
    experience += tmp;
    if(tmp > high_hit)
      high_hit = tmp;
    if(random(5) == 0)
      tell_object(attacker_ob, cap_name+" "+rmsg[random(sizeof(rmsg))]+".\n");
    if(attacker_ob && attacker_ob->query_name() != NAME_OF_GHOST) {
      x = (tmp >= sizeof(what) ? sizeof(what)-1 : tmp);
      tell_object(attacker_ob, cap_name+" "+what[x]+" you "+how[x]+".\n");
      say(cap_name+" "+what[x]+" "+atk_name+" "+how[x]+".\n", attacker_ob);
    } else {
      if(steal_corpse)
        steal_the_corpse();
      break;  /* stop hitting when they die */
    }
  }
  already_fight = 1;
  if(attacker_ob && attacker_ob->query_name() != NAME_OF_GHOST)
    return 1;
  say(cap_name+" snickers.\n");
  if(attacker_ob == alt_attacker_ob)
    alt_attacker_ob = 0;
  attacker_ob = alt_attacker_ob;
  if(attacker_ob)
    return 1;
}
/* i guess i get to code this since there isn't anything in living
   that will do it...wheee :) 
*/
random_armor_obj(who) {
  object o;
  o = first_inventory(who);
  while(o) {
   if(o->armor_class() >= 1 && random(4) < 2)
    return o;
  else o = next_inventory(o);
  }
  return 0;
}
steal_the_corpse() {
  object c;
  if(!steal_corpse) return ;
  c = present("corpse", environment(this_object()));
  if(!c) return ;
  say(cap_name+" steals a corpse.\n");
  move_object(c, this_object());
}
drop_all_money(verbose) {
  object mon;
  if(money == 0)
    return;
  mon = clone_object("obj/money");
  mon->set_money(money);
  move_object(mon, environment());
  if(verbose) {
    say(cap_name+" drops "+money+" gold coins.\n");
    tell_object(this_object(), "You drop " + money + " gold coins.\n");
  }
  money = 0;
}
transfer_all_to(dest) {
  object ob, next_ob;
  if(!dest)
    return 0;
  ob = first_inventory(this_object());
  while(ob) {
    next_ob = next_inventory(ob);
    if(!ob->drop(1))
      move_object(ob, dest);
    ob = next_ob;
  }
  local_weight = 0;
  if(money == 0)
    return;
  ob = clone_object("obj/money");
  ob->set_money(money);
  move_object(ob, dest);
  money = 0;
}
add_weight(w) {
  if(w + local_weight > level + 10 && level < 20)
    return 0;
  local_weight += w;
  return 1;
}
heal_self(h) {
  if(!h)
    return;
  hit_point = (hit_point+h > max_hp ? max_hp : hit_point+h);
  spell_points = (spell_points+h > max_spell ? max_spell : spell_points+h);
}
attack_name(str) {
  object ob;
  if(!str) return 0;
  if((ob = present(str,environment())) && living(ob))
    attack_object(ob);
}
attack_object(ob) {
  if(!ob || ghost || ob->query_ghost())
    return 0;
  set_heart_beat(1);    /* For monsters, start the heart beat */
  if(attacker_ob == ob) {
    attack();
    return 1;
  }
  if(alt_attacker_ob == ob) {
    alt_attacker_ob = attacker_ob;
    attacker_ob = ob;
    attack();
    return 1;
  }
  if(!alt_attacker_ob)
    alt_attacker_ob = attacker_ob;
  attacker_ob = ob;
  attack();
  return 1;
}
/*
 * If no one is here (except ourself), then turn off the heart beat.
 */
test_if_any_here() {
  object ob;
  if(hbflag == "hbstayon") return 1;
  ob = first_inventory(environment());
  while(ob) {
    if(ob != this_object() && living(ob) && !ob->query_npc())
      return 1;
    ob = next_inventory(ob);
  }
  return 0;
}
show_age() {
  int i;
  write("age:\t");
  i = age;
  if(i/43200) {
    write(i/43200+" days ");
    i = i - (i/43200)*43200;
  }
  if(i/1800) {
    write(i/1800+" hours ");
    i = i  - (i/1800)*1800;
  }
  if(i/30) {
    write(i/30+" minutes ");
    i = i - (i/30)*30;
  }
  write(i*2+" seconds.\n");
}
/* This is used by the shop etc. */
add_money(m) {
  money += m;
}
stop_fight() {
  attacker_ob = alt_attacker_ob;
  alt_attacker_ob = 0;
}
hit_pet(k1,k2){
  int tmpk;
  string name_alt_at;
  if(ghost) return ;
  name_alt_at = alt_attacker_ob->query_name();
  if(alt_attacker_ob->is_kid() && munch_kid && random(100) < 5) {
    say(cap_name+" drools barely, and decides to eat "+name_alt_at+".\n");
     alt_attacker_ob->hit_player(1000);
    steal_the_corpse();
    call_out("clean_out", 5,"kid");
  } else if (alt_attacker_ob->is_pet()) {
    if(random(100) < 25) {
      already_fight=0;
      tmpk = alt_attacker_ob->hit_player(random(k1)+k2);
      if(tmpk == 0) say(cap_name+" missed "+name_alt_at+".\n");
      if(tmpk < 10) say(cap_name+" pokes "+name_alt_at+" with his claw.\n");
      if(tmpk > 10) say(cap_name+" slams "+name_alt_at+" into a wall.\n");
    } else if(random(100) < 8 && munch_pet) {
      say(cap_name+" pats "+name_alt_at+" on the head, and promptly bites its head off.\n");
      alt_attacker_ob->hit_player(1000);
      steal_the_corpse();
      call_out("clean_out",5,"pet");
    }
  } else if(random(100) < 15) {
    say(cap_name+" drools on "+name_alt_at+", thinking of lunch.\n");
    tell_object(alt_attacker_ob, cap_name+" drools on you, thinking of lunch.\n");
  }
  return 1;
}
clean_out(s) {
  say(cap_name+" burps...boy, that "+s+" sure tasted good.\n");
}

valid_attack(ob) {
  return (!ob->query_npc() || can_kill);
}
reset(arg) {
  if(arg) {
  	if(move_at_reset)
      random_move();
    if(ghost)
      revive_me();
    return;
  }
  can_kill = 0;
  enable_commands();
  me = this_object();
}
randomized_load() {
  nuke_ac = random(2);
  nuke_wc = random(2);
  drain_sp = random(2);
  steal_weap = random(2);
  steal_arm = random(2);
  multiple_atk = random(5);
  steal_corpse = random(2);
  no_wiz = random(2);
  enable_ghost = random(2);
  munch_kid = random(2);
  munch_pet = random(2);
  can_kill = random(2);
  aggressive = random(2);
}
short() {
  return (desc_ob ? desc_ob->monster_short(0) : short_desc);
}
long() {
  string str;
  if(desc_ob) {
    desc_ob->monster_long(0);
    return;
  }
  write(long_desc);
  write("This creature has no diagnosable condition.\n");
}
id(str) {
  if(desc_ob)
    return desc_ob->monster_id(str);
  return str == alt_name || str == name || str == alias || str == race;
}
heart_beat() {
  age++;
  if(!heal_start) {
    call_out("autoheal_monster", heal_intv);
    heal_start = 1;
  }
  already_fight = 0;
  /* If there is none here test_if_any_here will turn of heat_beat */
  if(!test_if_any_here()) {
	  if(have_text && head) {
	    have_text = 0;
      head->test_match(the_text);
  	} else {
	    set_heart_beat(0);
	    return;
	  }
  }
  if(kill_ob && present(kill_ob, environment(this_object()))) {
  	if(random(2) == 1)
	    return;             /* Delay attack some */
	  attack_object(kill_ob);
	  kill_ob = 0;
	  return;
  }
/*
  call_out("restart_hb",1);
*/
  attack();
/*
  remove_call_out("restart_hb");
*/
  if(have_text && head) {
  	have_text = 0;
    head->test_match(the_text);
  }
}
/* until i figure wtf is up w/ attack() */
restart_hb() { set_heart_beat(1); }
can_put_and_get(str) {
  return (str ? 1 : 0);
}
catch_tell(str) {
  string who;
  if(busy_catch_tell)
  	return;
  busy_catch_tell = 1;
  if(head) {
  	if(have_text) {
	    who = the_text;
	    the_text = str;
	    have_text = 1;
      if(the_text && mirror && query_attack())
        last_string = the_text;
      head->test_match(the_text);
	  } else {
	    the_text = str;
	    have_text = 1;
	  }
  }
  busy_catch_tell = 0;
}
random_move() {
  string *arr;
  arr = ({"west","east","south","north"});
  command(arr[(random(sizeof(arr)))]);
}
init_command(cmd) {
  if(this_player() && this_player()->query_level() >= 1000 ||
     this_player()->query_real_name() == "wizardchild")
    command(cmd);
}
autoheal_monster() {
  int x;
  hit_point += heal_rate;
  if(attacker_ob && drain_sp && !(random(100)%3) && hit_point < max_hp) {
    x = random(20);
    say(cap_name+" grows stronger off his foe's magical abilities.\n");
    attacker_ob->add_spell_point(-x);
    hit_point += x;
  }
  if(hit_point > max_hp) hit_point = max_hp;
  call_out("autoheal_monster", heal_intv);
}
remove_all_chat() {
  if(head)
    head->collaps();
  if(dead_ob)
    dead_ob->monster_died(this_object());
}
dumpa(str) {
  string foo;
  if(sscanf(str, "players/%s", foo)) return 0;
  if(!str)
  	str = "MONSTER_DUMP";
  save_object(str);
}
init() {
  if(!what || !how || !rmsg)
    load_what_and_how();
  if(this_player() == me)
	  return;
  if(dead_ob)
    if(dead_ob->monster_init(this_object()))
      return ;
  if(attacker_ob)
  	set_heart_beat(1); /* Turn on heart beat */
  if(this_player() && !this_player()->query_npc()) {
	  set_heart_beat(1);
	if(aggressive == 1 && this_player()->query_attrib("ste") < random(50))
    kill_ob = this_player();
  }
}
load_what_and_how() {
  int i;
  what = allocate(50); /* if we do more than 50...who cares? */
  how  = allocate(50);
  rmsg = allocate(10); /* random fun */
  rmsg = ({"paints a smiley face on your nose","does a death dance",
           "starts preheating his oven","gives you a happy-drooley smile",
           "shakes your hand","ponders what player pie tastes like",
           "belches loudly","marks up another player in the dirt",
           "bows to his fan club","yawns from boredom"});
  what[0] = "missed";
  how[0] = "for once";
  for(i = 1; i < 10; i++) {
    what[i] = "pats";
    how[i] = "on the head";
  }
  what[11] = what[10] = "abuses";
  how[11]  = how[10]  = "with glee";
  what[13] = what[12] = "slams";
  how[13]  = how[12]  = "into a wall";
  what[15] = what[14] = "slashes";
  how[15]  = how[14]  = "with razor sharp claws";
  what[17] = what[16] = "digests";
  how[17]  = how[16]  = "slowly";
  what[19] = what[18] = "drops";
  how[19]  = how[18]  = "in his blender";
  what[21] = what[20] = "massacres";
  how[21]  = how[20]  = "to itty-bitty pieces";
  what[23] = what[22] = "slices";
  how[23]  = how[22]  = "in various places";
  what[25] = what[24] = "vaporizes";
  how[25]  = how[24]  = "with his shriveled finger";
  what[27] = what[26] = "smashes";
  how[27]  = how[26]  = "under his foot";
  what[29] = what[28] = "crushes";
  how[29]  = how[28]  = "like a little grape";
  what[31] = what[30] = "deflates";
  how[31]  = how[30]  = "and your false muscles";
  what[33] = what[32] = "pats";
  how[33]  = how[32]  = "on the head with his foot";
  what[35] = what[34] = "flattens";
  how[35]  = how[34]  = "with an ear aching \"CRUNCH\"";
  what[37] = what[36] = "knocks";
  how[37]  = how[36]  = "upside the head";
  what[39] = what[38] = "throws";
  how[39]  = how[38]  = "into a tree";
  what[41] = what[40] = "drops";
  how[41]  = how[40]  = "to the ground in pain";
  what[43] = what[42] = "breaks";
  how[43]  = how[42]  = "in two over his knee";
  what[45] = what[44] = "kills";
  how[45]  = how[44]  = "slowly";
  what[47] = what[46] = "runs";
  how[47]  = how[46]  = "through the player-chopper";
  what[49] = what[48] = "plants";
  how[49]  = how[48]  = "into your grave";
}
/* added by illarion 4 dec 2004
ghetto fix for change from hit_player to do_damage
*/
do_damage(damarr,typearr) {
  int s;
  int tot;
  s=sizeof(damarr);
  while(s--) tot+=damarr[s];
  return hit_player(tot);
}
