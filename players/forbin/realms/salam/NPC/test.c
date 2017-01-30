/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     NPC
 *  Create Date:  2004.06.05
 *  Last Edit:    2004.06.16 -Forbin
 *  Notable Changes:    
 *    2004.06.15 -added bunch of debugging/logging stuff to see what
 *                  kind of damage this mob does [Forbin]
 *    2004.06.23 -capped damage when greater than 300,000 experience
 *                approved by Verte [Forbin]
 */ 

#include "/players/forbin/realms/salam/salamdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

#define DEBUG

object Crown, Weapon;
int ThrownOut, Bezerk;
int WC_Count, AC_Count;
int Regular_Round, Bezerk_Round;
int FireBall_Damage, FireBall_Hits, FireBall_Num;
int Inferno_Damage, Inferno_Hits;
int Healing_Total;
int Worthness;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Crown = clone_object(OBJ+"coal_crown.c"); 
  move_object(Crown, this_object());
  command("wear crown", this_object());   
  Weapon = clone_object(OBJ+"neruumsh.c"); 
  move_object(Weapon, this_object());
  command("wield axe", this_object()); 
  set_name("Sebassis");
  set_alt_name("sebassis");
  set_alias("king");
  set_race("salamite");
  set_gender("male");
  set_short(HIR+"Sebassis,"+NORM+RED+" the "+HIR+"Sala"+NORM+RED+"mite"+HIR+" King"+NORM);
  set_long(
    "  This dark red giant dwarfs you.  Black, obsidian armor covers most\n"+
    "of his body; what remains visible is covered in bright red scales.  He\n"+
    "holds a large axe in his left hand and wears a crown of black coal on\n"+ 
    "his head.  A large red triangle, pointing downward, has been painted\n"+
    "onto his armored chest.  It would be very wise to tread lightly in his\n"+
    "glorious presence.\n");
  set_level(25);
  set_hp(1100+random(200));
  set_al(-999);
  set_wc(46);
  set_wc_bonus(41);
  set_ac(22);
  set_heal(2,1);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("Sebassis roars: \"Why do you disturb me?\"\n");
    load_chat("The King glares at you...\n");
    load_chat("Sebassis points at you and says, \"Leave why you still can!\"\n");
    load_chat("Sebassis growls: \"Who let you in here?\"\n");
  set_a_chat_chance(20);
    load_a_chat("Sebassis thunders: \"Where are my guardsmen?\"\n");
    load_a_chat("Sebassis kicks you in the chest.\n");
    load_a_chat("The Salamite King swings hard, knocking you to the ground.\n");  
    load_a_chat("The Salamite King roars loudly.\n");
    load_a_chat("Sebassis draws back Neruumsh, ready to strike.\n");
  ThrownOut = 0;
  Bezerk = 0;
  WC_Count = 0;
  AC_Count = 0;
  Regular_Round = 0;
  Bezerk_Round = 0;
  FireBall_Damage = 0;
  FireBall_Hits = 0;
  FireBall_Num = 0;
  Inferno_Damage = 0;
  Inferno_Hits = 0;
  Healing_Total = 0;
}

init(){
  ::init();
}

query_salamite_king() { return 1; }

heart_beat() {
  ::heart_beat();
  if(!environment())  return ;
  if(!attacker_ob) return ;
  if(!Bezerk) Regular_Round ++;
  else Bezerk_Round ++;
  if(weapon_class < 46) weapon_class = 46;
  if(armor_class < 22 && !Bezerk) armor_class = 22;
  WC_Count += weapon_class; /* used to calc average wc for calculate_worth() */
  AC_Count += armor_class;  /* used to calc average ac for calculate_worth() */
  if(hit_point < 600 && !ThrownOut) throw_out();
  if(hit_point < 300 && !Bezerk) bezerk();
  if(hit_point < 100) { hit_point += 4; Healing_Total += 4; }
  if(environment(attacker_ob) != environment(this_object())) return;
  if(!random(5)) dark_magick();      /* 20% chance of special */
  else if(!random(5)) lava_strike(); /* 16% chance of special */
  else if(!random(4)) toss();        /* 16% chance of special */
  else if(!random(3)) fireball();    /* 16% chance of special */
  else if(!random(4)) inferno();     /*  8% chance of special */
  else {
#ifdef DEBUG
  mdmsg("no special called this round");
#endif
  }
  if(attacker_ob == this_object()) {
    stop_fight();
    stop_fight();
  }
}

/* 
 *  ***********************************************************************
 *  Function:    heal_self
 *  Description: no heal_self damage allowed
 *  Arguments:   none
 *  ***********************************************************************
 */

heal_self(int i) {
  if(i < 0){
    tell_room(environment(), "Sebassis laughs heartily, easily shrugging off your attack!\n");
    return 1;
  }
  ::heal_self(i);
  return 1;
}

/* 
 *  ***********************************************************************
 *  Function:    stop_fight 
 *  Description: players cannot stop the fight
 *  Arguments:   none
 *  ***********************************************************************
 */

stop_fight() {
  if(this_player()->query_level() > 20 || this_player() == this_object()) {
    ::stop_fight();
    return 1;
  }
  return;
}

/* 
 *  ***********************************************************************
 *  Function:    throw_out 
 *  Description: called when hit_point < 600 (only called once), throws all
 *                 attacking players from room and summons a mob to attack
 *  Arguments:   none
 *  ***********************************************************************
 */

throw_out() {
  object ob, target, mob;
  string where;
#ifdef DEBUG
  mdmsg("throw_out() called");
#endif
  if(!environment(this_object()) || !((object)this_object()->query_attack()))
    return;
  mob = clone_object(NPC+"brute.c");
  move_object(mob, RMS+"cots07.c");
  ob = first_inventory(environment(this_object()));
  while(ob) {
    if (ob->query_attack() == this_object()) {
      target = ob;
      ob = next_inventory(ob);
      switch(random(4)) {
        case 0: where = "throat"; break;
        case 1: where = "head"; break;
        case 2: where = "arm"; break;
        case 3: where = "leg"; break;
      }
#ifdef DEBUG
  mdmsg("throw_out(): "+target->query_name()+" moved");
#endif
      tell_object(target, 
        HIW+"\n\nSebassis grabs you by your "+where+" and launches you out of the room!"+NORM+"\n\n\n");
      tell_room(environment(),
        "Sebassis grabs "+target->query_name()+" by "+this_player()->query_possessive()+" "+where+" and launches "+this_player()->query_objective()+" out of the room!\n", ({target}));
      target->move_player("flying through the air#"+RMS+"cots07.c");
      tell_object(target,
        HIW+"A salamite brute rushes into the room to protect the king.\n"+NORM);
      target->attacked_by(mob);
    }
    else
      ob = next_inventory(ob);
  }
  ThrownOut = 1;
  return;  
}

/* 
 *  ***********************************************************************
 *  Function:    bezerk
 *  Description: called when hit_point < 300 (only called once), 
 *                 weapon_class doubles, armor_class halves, heals
 *                 100+random(50) hps heal_rate and heal_intv set to 0
 *  Arguments:   none
 *  WC_Bonus:    - handled in calculate_worth()
 *  ***********************************************************************
 */

bezerk() {
  int heal_amt;
#ifdef DEBUG
  mdmsg("bezerk() called");
#endif
  if(!environment(this_object()) || !((object)this_object()->query_attack()))
    return;
  tell_room(environment(),
    HIB+"\nFeeling the battle has turned, Sebassis flies into a BeZErK rAgE!"+NORM+"\n\n");
  weapon_class *= 2;
  armor_class /= 2;
  heal_amt = 100 + random(50);
  hit_point += heal_amt;
  Healing_Total += heal_amt;
  heal_rate = 0;
  heal_intv = 0;
  Bezerk = 1;
#ifdef DEBUG
  mdmsg("bezerk() WC: "+weapon_class+" AC: "+armor_class+" Heal Amount: "+heal_amt);
#endif
}

/* 
 *  ***********************************************************************
 *  Function:    dark_magick
 *  Description: 30+random(40) other|dark damage to main attacker_ob
 *  Arguments:   none
 *  WC_Bonus:    13
 *    .20 (chance) * 50 (avg dmg) = 10 * 1.5 (dmg type) = 12.5 = 13
 *  ***********************************************************************
 */

dark_magick() {
  int amt;
  object random_attacker_ob;
#ifdef DEBUG
  mdmsg("dark_magick() called");
#endif
  if(random_attacker_ob = (object)this_object()->get_attacker()) {
    if(environment(random_attacker_ob) == environment()) {
      tell_object(random_attacker_ob, 
        "\nSebassis waves his hand at you...\n"+
        "     "+HIK+"DaRK mAgICk"+NORM+" channels into you, wracking you with pain...\n\n");
      tell_room(environment(),
        "Sebassis waves his hand at "+random_attacker_ob->query_name()+"...\n"+
        "     "+random_attacker_ob->query_name()+"'s body is wracked with pain by "+HIK+"dArk MaGicK"+NORM+"...\n", ({random_attacker_ob}));
      amt = 30 + random(40);
      random_attacker_ob->hit_player(amt, "other|dark");
#ifdef DEBUG
  mdmsg("dark_magick(): "+random_attacker_ob->query_name()+" DAMAGE: "+amt+" other|dark");
#endif
    }
  }
}

/* 
 *  ***********************************************************************
 *  Function:    lava_strike
 *  Description: 40+random(60) other|fire damage to main attacker
 *  Arguments:   none
 *  WC_Bonus:    14
 *    .16 (chance) * 70 (avg dmg) = 11 * 1.5 (dmg type) = 13.75 = 14
 *  ***********************************************************************
 */

lava_strike() {
  int amt;
  object random_attacker_ob;
#ifdef DEBUG
  mdmsg("lava_strike() called");
#endif
  if(random_attacker_ob = (object)this_object()->get_attacker()) {
    if(environment(random_attacker_ob) == environment()) {
      tell_object(random_attacker_ob, 
        "\nSebassis points at the lava pit...\n"+
        "     "+HIR+"MOLTEN LAVA"+NORM+" leaps forth and douses you...\n\n");
      tell_room(environment(),
        "Sebassis points at the lava pit...\n"+
        "     "+random_attacker_ob->query_name()+" is covered with "+HIR+"LAVA"+NORM+" as molten rock leaps forth...\n", ({random_attacker_ob}));
      amt = 40 + random(60);
      random_attacker_ob->hit_player(amt, "other|fire");
#ifdef DEBUG
  mdmsg("lava_strike(): "+random_attacker_ob->query_name()+" DAMAGE: "+amt+" other|fire");
#endif
    }
  }
}

/* 
 *  ***********************************************************************
 *  Function:    toss 
 *  Description: 50+random(80) damage to random attacker
 *  Arguments:   none
 *  WC_Bonus:    14
 *    .16 (chance) * 90 (avg dmg) = 14 * 1 (straight dmg) = 14
 *  ***********************************************************************
 */

toss() {
  int amt;
  string where;
  object random_attacker_ob;
#ifdef DEBUG
  mdmsg("toss() called");
#endif
  if(random_attacker_ob = (object)this_object()->get_attacker()) {
    if(environment(random_attacker_ob) == environment()) {    
      switch(random(4)) {
        case 0: where = "throat"; break;
        case 1: where = "head"; break;
        case 2: where = "arm"; break;
        case 3: where = "leg"; break;
      }
      tell_object(random_attacker_ob, 
        HIW+"Sebassis grabs you by your "+where+" and slams you to the ground!"+NORM+"\n");
      tell_room(environment(),
        "Sebassis grabs "+random_attacker_ob->query_name()+" by "+random_attacker_ob->query_possessive()+" "+where+" and slams "+random_attacker_ob->query_objective()+" to the ground!\n", ({random_attacker_ob}));
      amt = 50 + random(80);
      random_attacker_ob->hit_player(amt);
#ifdef DEBUG
  mdmsg("toss(): "+random_attacker_ob->query_name()+" DAMAGE: "+amt);
#endif
    }
  }
}

/* 
 *  ***********************************************************************
 *  Function:    fireball 
 *  Description: random room (other|fire) damage based on total player hps
 *  Arguments:   none
 *  WC_Bonus:    - handled in calculate_worth()
 *  ***********************************************************************
 */

fireball() {
  object ob, target;
  int counter, total_hit_point_pool;
  int num, dam, sdam, rdam, tdam, tdamall;
#ifdef DEBUG
  mdmsg("fireball() called");
#endif
  counter = 0;
  total_hit_point_pool = 0;
  tdamall = 0;
  if(!environment(this_object()) || !((object)this_object()->query_attack()))
    return;
  ob = first_inventory(environment(this_object()));
  while(ob) {
    if (ob->query_attack() == this_object()) {
      counter ++;
      total_hit_point_pool += ob->query_hit_point();
      ob = next_inventory(ob);
    }
    else
      ob = next_inventory(ob);
  }
  if(counter < 0) counter = 1;
  num = total_hit_point_pool / counter;
  if(num > 300) dam = 200;
  else if(num > 140 && num < 301) dam = 120;
  else dam = 70;
  sdam = ((dam * 2) / 3);
  rdam = ((dam * 3) / 4);
  ob = first_inventory(environment(this_object()));  
  while(ob) {
    if (ob->query_attack() == this_object() && environment(ob) == environment(this_object())
      && ob->is_player()) {
      target = ob;
      ob = next_inventory(ob);
      tell_room(environment(),
        RED+"Sebassis conjures a smoldering ball of fire! He throws it into the\n"+
        "center of the room, where it ignites a firestorm\n"+NORM);
      tell_object(target, 
        HIR+"\n\n\t\tFire rages all around you\n\n\n"+NORM);
      tdam = sdam + random(rdam);
      target->hit_player(tdam, "other|fire");
      tdamall += tdam;
#ifdef DEBUG
  mdmsg("fireball(): "+target->query_name()+" DAMAGE: "+tdam+" other|fire");
#endif
    }
    else
      ob = next_inventory(ob);
  }
  FireBall_Damage += dam;
  FireBall_Hits ++;
#ifdef DEBUG
  mdmsg("fireball(): HPP: "+total_hit_point_pool+" COUNTER: "+counter+" NUM: "+num+" DAM: "+dam); 
  mdmsg("fireball(): TOTAL DAMAGE: "+tdamall+" other|fire");
#endif
}

/* 
 *  ***********************************************************************
 *  Function:    inferno 
 *  Description: hits random attacker_ob for 1/2 hps (other|fire)
 *  Arguments:   none
 *  WC_Bonus:    - handled in calculate_worth()
 *  ***********************************************************************
 */

inferno() {
  int dam;  
  object random_attacker_ob;
#ifdef DEBUG
  mdmsg("inferno() called");
#endif
  if(random_attacker_ob = get_attacker()) {
    if(environment(random_attacker_ob) == environment()) {    
      dam = random_attacker_ob->query_hit_point();
      dam /= 2;
      tell_object(random_attacker_ob,
        "Sebassis raises his hands high into the air...\n"+
        "    You are engulfed in a torrent of flames...\n");
      tell_room(environment(),
        "Sebassis raises his hands high into the air...\n"+
        "    "+random_attacker_ob->query_name()+" is engulfed in a torrent of flames...\n", ({random_attacker_ob}));
      tell_room(environment(),
        HIR+"\n               (  .      )\n"+
        "           )           (              )\n"+
        "                 .  '   .   '  .  '  .\n");
      tell_room(environment(),
        HIR+"        (    , )       (.   )  (   ',    )\n"+
        "         .' ) ( . )    ,  ( ,     )   ( .\n"+
        "      ). , ( .   (  ) ( , ')  .' (  ,    )\n");
      tell_room(environment(),
        HIR+"     (_,) . ), ) _) _,')  (, ) '. )  ,. (' )\n"+
        "    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n"+NORM);      
      random_attacker_ob->hit_player(dam, "other|fire");
      Inferno_Damage += dam;
      Inferno_Hits ++;
#ifdef DEBUG
  mdmsg("inferno(): "+random_attacker_ob->query_name()+" DAMAGE: "+dam+" other|fire");
#endif
    }
  }
}

/*    
 *  ***********************************************************************
 *  Function:    select_attacker & is_attacker (Thanks, Verte!)
 *  Description: these two functions control choosing random attackers
 *  Arguments:   is_attacker: object
 *  Returns:     returns a random attacker, 
 *  ***********************************************************************
 */

get_attacker() {
  int chosen, chosenn;
  int x, size;
  string arraylist;
  object *atts;
#ifdef DEBUG
  mdmsg("  get_attacker() called");
#endif
  atts = all_inventory(environment());
  atts = filter_array(atts, "is_attacker", this_object());
  size = sizeof(atts);
  chosen = random(sizeof(atts));
  chosenn = chosen + 1;
#ifdef DEBUG
  arraylist = "({";
  for(x=0; x<sizeof(atts); x++) {
    arraylist += "\""+atts[x]->query_name()+"\",";
  }
  arraylist += "})";
  mdmsg("  ArrayList: "+arraylist);
  mdmsg("  ArraySize: "+size+" Chosen: "+chosenn+" "+atts[chosen]->query_name());
#endif
  return atts[chosen];
}

is_attacker(object ob) {
  if(ob->is_player()) {
    return (ob->query_attack() == this_object());
  }
}


/* 
 *  ***********************************************************************
 *  Function:    calculate_worth 
 *  Description: used to adjust for bezerk(), inferno() and healing changes
 *  Arguments:   none
 *  Notes:       bezerk:  because bezerk() modifies heal_rate and heal_intv
 *                          I use the ratio of rounds with set_heal(2,1) to
 *                          rounds with set_heal(0,0) to get a ac_bonus
 *                        bezerk() also modifies wc and ac, so they are
 *                        averaged by total rounds and used to reset wc/ac
 *               fireball: fireball() is based on a total query of all the
 *                           attacking hit points in the room, it is
 *                           calculated here using a damage & hits formula
 *               inferno: since inferno() damage is based on players hit 
 *                          points, a total is kept and used to calculate
 *                          the wc_bonus using the standard formula
 *               healing: special cases of healing are handled with a total
 *                          count of healing and set accordingly (healing
 *                          when hit_point < 100 in heart_beat() and 
 *                          healing during bezerk())
 *  ***********************************************************************
 */

calculate_worth(){
  int healing_mod, fireball_mod, inferno_mod;

  if((Regular_Round + Bezerk_Round) > 0) {
    healing_mod = (((2 * Regular_Round) * 3) / (Regular_Round + Bezerk_Round));
    ac_bonus += healing_mod;

  /* following two lines average the wc & ac for a true account of wc & ac */
  weapon_class = (WC_Count / (Regular_Round + Bezerk_Round));
  armor_class = (AC_Count / (Regular_Round + Bezerk_Round));
  } 
  
  if(FireBall_Hits > 0) { /* following 4 lines averages damage from fireball() */
    fireball_mod = (((FireBall_Damage / FireBall_Hits) * 2) / 3);
    fireball_mod += (((FireBall_Damage / FireBall_Hits) * 2) / 3);
    fireball_mod += (((FireBall_Damage / FireBall_Hits) * 3) / 4);
    fireball_mod /= 2; /* following calculates bonus for fireball() */
    fireball_mod = ((((fireball_mod / 100) * 16) * 125) / 100);
    wc_bonus += fireball_mod;
  }                     /* else wc_bonus to prevent division by zero               */
  else wc_bonus += 20;  /* WC_bonus: lowest it can be is 20                        */                
                        /* .16 (chance) * 99 (avg dmg) = 16 * 1.25 (dmg type) = 20 */

  if(Inferno_Hits > 0) { /* following averages inferno() damage & calculates bonus */
    inferno_mod = (((((Inferno_Damage / Inferno_Hits) / 100) * 8) * 125) / 100); 
    wc_bonus += inferno_mod;
  }                    /* else wc_bonus to prevent division by zero              */
  else wc_bonus += 9;  /* WC_bonus: lowest it can be is 9 based on lvl 10 sta 15 */
                       /* .08 (chance) * 89 (avg dmg) = 7 * 1.25 (dmg type) = 9  */

  hp_bonus += Healing_Total;

  /* Next line caps the exp if over 330,000 - Approved by Verte 2004.06.23 */
  return ::calculate_worth();
}

monster_died() {
  object treasure;
#ifdef BIGKILLLOG
  mon_log(BIGKILLLOG);
  write_file(BIGKILLLOG,
    "                  WC Bonus: "+wc_bonus+"  AC Bonus: "+ac_bonus+"  HP Bonus: "+hp_bonus+" Regular Round: "+Regular_Round+" Bezerk Round: "+Bezerk_Round+"\n"); 
  write_file(BIGKILLLOG,
    "                  Experience Given: "+Worthness+"\n");
#endif
  tell_room(environment(this_object()),
    "\n\nWith the killing blow, a chunk of scales is knocked from Sebassis.\n\n");
  treasure = clone_object(OBJ+"salamite_scales.c");
  move_object(treasure,environment(this_object()));
    return 1;
}
