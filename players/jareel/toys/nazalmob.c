/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Keats/Flame Forest
//  Function:     NPC
//  Create Date:  2005.07.01
//  Last Edit:    2005.07.01 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/realms/keats/keatsdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

#define CALL_ACID_BURN_WC_BONUS 7 /* see function header for calculations */
#define CALL_BLIND_WC_BONUS 4      /* see function header for calculations */
#define CALL_BLIND_AC_BONUS 2      /* see function header for calculations */

id(str) 
{ 
  return (::id(str) || str == "nazal" || str == "wizard"  
                    || str == "wandering wizard"  
                    || str == "nazal the wandering wizard"); 
}

reset(arg) 
{
  ::reset(arg);
  if(arg) return;

  switch(random(4))
  {
    case 0: move_object(clone_object(OBJ+"nazal_csb.c"), this_object()); 
            move_object(clone_object(OBJ+"nazal_cwr.c"), this_object()); 
            break;
    case 1: move_object(clone_object(OBJ+"nazal_esb.c"), this_object());
            move_object(clone_object(OBJ+"nazal_ewr.c"), this_object()); 
            break;
    case 2: move_object(clone_object(OBJ+"nazal_ssb.c"), this_object());
            move_object(clone_object(OBJ+"nazal_swr.c"), this_object()); 
            break;
    case 3: move_object(clone_object(OBJ+"nazal_osb.c"), this_object());
            move_object(clone_object(OBJ+"nazal_owr.c"), this_object()); 
            break;
  }    
  move_object(clone_object(OBJ+"nazal_yew_staff.c"), this_object()); 
  command("wear robes", this_object());   
  command("wield staff", this_object());         
  
  set_name("Nazal");
  set_race("human");
  set_gender("male");
  set_short(HIW+"Nazal"+NORM+", the Wandering Wizard");
  set_long(
    "Nazal is a tall, slender old chap who has been rumored to have\n"+
    "been a member of the Mage guild for over two centuries.  His long\n"+
    "white beard nearly touches the ground and his silver hair, having\n"+
    "been tied into a ponytail, falls almost halfway down his back.  He\n"+
    "is dressed in impeccable silk robes and carries a wooden staff.\n"+
    "Seeing a strength in his deep green eyes, you get the sense that\n"+
    "he is much more powerful than his frail apperance might foretell.\n");  
  set_level(26);
  set_hp(1400);
  set_al(0);
  set_wc(60);
  set_wc_bonus(CALL_ACID_BURN_WC_BONUS + CALL_BLIND_WC_BONUS);  
  set_ac(35);
  set_ac_bonus(CALL_BLIND_AC_BONUS);  
  set_wander(333, 0);
  add_money(5000+random(13000));
  set_dead_ob(this_object());  
  set_chat_chance(15);
    load_chat("Nazal looks off towards the horizon.\n");
    load_chat("The Wandering Wizard says: \"I hear the bridge to keats will soon reopen.\"\n");
    load_chat("Nazal wipes the sweat from his forehead.\n");
    load_chat("The wizard stoops and picks something small up off the ground.\n");
    load_chat("Nazal asks: \"Have you ever been to Keats?\"\n");
    load_chat("The wizard sighs: \"I hope I see the Tower of the Magi again before I die.\"\n");
  set_a_chat_chance(20);
    load_a_chat("Nazal chants in a growling language...\n"+
                "A "+MAG+"purple aura"+NORM+" surrounds him and he is healed.\n");
    load_a_chat("Nazal scoffs: \"You cannot defeat a master Mage like myself!\"\n");
    load_a_chat("Nazal blocks your attack with his "+HIY+"yew"+NORM+" staff.\n");
/* 
////////////////////////////////////////////////////////////////////////////
// AcidArrow
//   10% chance of 30-50 other|poison damage to main attacker
//   clones acid object that damages 5-20 other|poison for 5 rounds
// MagicMissile  
//   10% chance of 5-80 magical damage to main attacker
// FlameStrike 
//   8% chance of 50-100 other|fire damage to main attacker
// ChromaticOrb 
//   8% chance of 20-30 other|light damage to random attacker
// ColorSpray 
//   5% chance of 50-80 other|light damage to main attacker
//   calls additional 15-40 other|light damage to all attackers and
//   clones object that lowers all attackers WC for several rounds
////////////////////////////////////////////////////////////////////////////
*/   
  add_spell("AcidArrow",
    "$HG$ -- -$N$\n"+
    "  Nazal points at you and speaks an ancient word.\n"+
    "  Suddenly an $G$arrow of acid$N$ appears out of nowhere and\n"+
    "  strikes you with a sizzling blast of $HG$acid$N$!\n"+
    "$HG$ -- -$N$\n",  
    "Nazal points at #CTN# and speaks an ancient word.\n"+
    "Suddenly an $G$arrow of acid$N$ appears out of nowhere and\n"+
    "strikes #CTN# with a sizzling blast of $HG$acid$N$!\n",
    10, "30-50", "other|poison", 0, "call_acid_burn");     
  add_spell("MagicMissile",
    "$HY$ -- -$N$\n"+
    "  The Wandering Wizard opens #MP# hand toward you.\n"+
    "  $HY$Magic Missiles$N$ leap forth from #MP# palm.\n"+
    "$HY$ -- -$N$\n",
    "The Wandering Wizard opens #MP# hand toward #CTN#.\n"+
    "$HY$Magic Missiles$N$ leap forth from #MP# palm.\n",
    10, "5-80", "magical", 0, "call_magic_missiles");     
  add_spell("FlameStrike",
    "$R$ -- -$N$\n"+
    "  Nazal produces a pinch of $HY$sulfur$N$ from a fold in #MP# robes.\n"+
    "  He throws the $HY$sulfur$N$ at your feet and shouts: \"$HW$Ignitus!$N$\"\n"+
    "\n     You are engulfed in a $HR$TOWERING PILLAR OF FLAME$N$!\n"+
    "$R$ -- -$N$\n",
    "Nazal produces a pinch of $HY$sulfur$N$ from a fold in #MP# robes.\n"+
    "He throws the $HY$sulfur$N$ at #CTN#'s feet and shouts: \"$HW$Ignitus!$N$\"\n"+
    "\n    #CTN# is engulfed in a $HR$TOWERING PILLAR OF FLAME$N$!\n",
    8, "50-100", "other|fire");     
  add_spell("ChromaticOrb",
    0,0,
    8, "20-30", "other|light", 6, "call_chromatic_orb");     
  add_spell("ColorSpray",
    "$HW$ -- -$N$\n"+
    "  Nazal holds his staff of $HY$yew$N$ high in the air.\n"+ 
    "  A myriad of lights shoot forth from the staff!\n"+
    "$HW$ -- -$N$\n",
    "Nazal holds his staff of $HY$yew$N$ high in the air.\n"+ 
    "A myriad of lights shoot forth from the staff!\n",
    5, "50-80", "other|light", 6, "call_blind");                     
   
}

/* 
////////////////////////////////////////////////////////////////////////////
//  Function:    call_acid_burn (called from AcidArrow spell)
//  Description: clones a timed object that burns player with acid
//               5-20 other|poison damage for 5 rounds
//  Arguments:   object target, object room, int damage
//  WC_Bonus:    7 
//    .10 (chance) * 72.5 (avg dmg * rounds) = 7.25 = 7              
////////////////////////////////////////////////////////////////////////////
*/

void call_acid_burn(object target, object room, int damage) 
{
  object acid, acidob;
  if(!(acid = present("nazal_acid_object", target))) 
  {
    acidob = clone_object(OBJ+"nazal_acid_object.c");
    move_object(acidob, target);
  }
  else
    acid->add_time();
}

/* 
////////////////////////////////////////////////////////////////////////////
//  Function:    call_magic_missiles (called from MagicMissile spell)
//  Description: atmospheric casting of multiple magic missiles
//  Arguments:   object target, object room, int damage
////////////////////////////////////////////////////////////////////////////
*/

void call_magic_missiles(object target, object room, int damage) 
{
  int hits, misses;
  string tmsg, rmsg, bpart;
  int x;
  switch(damage) 
  {
    case  0..10:    hits = 1; misses = 0; break;  
    case 11..15:    hits = 1; misses = 1; break;  
    case 16..20:    hits = 1; misses = 1; break;
    case 21..25:    hits = 2; misses = 0; break;
    case 26..30:    hits = 2; misses = 0; break;
    case 31..35:    hits = 1; misses = 2; break;
    case 36..40:    hits = 2; misses = 1; break;
    case 41..45:    hits = 3; misses = 0; break;
    case 46..50:    hits = 3; misses = 0; break;
    case 51..55:    hits = 1; misses = 3; break;
    case 56..60:    hits = 2; misses = 2; break;
    case 61..65:    hits = 3; misses = 1; break;
    case 66..70:    hits = 4; misses = 0; break;
    case 71..75:    hits = 4; misses = 1; break;
    case 76..10000: hits = 5; misses = 0; break;    
  }
  while(hits || misses)
  {
  	tmsg = ""; rmsg = "";
    switch(random(11))
    {
      case  0: bpart = "head"; break;
      case  1: bpart = "face"; break;
      case  2: bpart = "chest"; break;
      case  3: bpart = "side"; break;
      case  4: bpart = "back"; break;
      case  5: bpart = "hand"; break;
      case  6: bpart = "arm"; break;
      case  7: bpart = "shoulder"; break;
      case  8: bpart = "leg"; break;
      case  9: bpart = "thigh"; break;
      case 10: bpart = "foot"; break;
    }    
    if(!random(3)) 
    {
      if(misses)
      {
        switch(random(4))
        {
          case 0: 
            tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                   " sails past your "+bpart+"!";
            rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                   " sails past "+(string)target->query_name()+"'s "+bpart+"!";
            break;
          case 1: 
            tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                   " shoots by your "+bpart+"!";
            rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                   " shoots by "+(string)target->query_name()+"'s "+bpart+"!";
            break;
          case 2:
            tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                   " streaks into the ground in front of you!";
            rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                   " streaks into the ground in front of "+
                   (string)target->query_name()+"!";
            break;
          case 3:
            tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                   " fizzles out before it gets to you!";
            rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                   " fizzles out before it gets to "+
                   (string)target->query_name()+"!";
            break;            
        }
      if(misses > 0) misses--;
      tell_object(target, "   "+tmsg+"\n");
      tell_room(room, "   "+rmsg+"\n", ({ target }));        
      }
    }
    else if(hits)
    {
      switch(random(3))
      {
        case 0: 
          tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " strikes you in the "+bpart+"!";
          rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " strikes "+(string)target->query_name()+" in the "+bpart+"!";
          break;
        case 1:
          tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " streaks into you!";
          rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " streaks into "+(string)target->query_name()+"!";
          break;
        case 2:
          tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " slams into you!";
          rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " slams into "+(string)target->query_name()+"!";
          break;            
      }
      if(hits > 0) hits--;      
      tell_object(target, "   "+tmsg+"\n");
      tell_room(room, "   "+rmsg+"\n", ({ target }));
    }
    else if(misses) 
    {
      switch(random(4))
      {
        case 0: 
          tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " sails past your "+bpart+"!";
          rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " sails past "+(string)target->query_name()+"'s "+bpart+"!";
          break;
        case 1: 
          tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " shoots by your "+bpart+"!";
          rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " shoots by "+(string)target->query_name()+"'s "+bpart+"!";
          break;
        case 2:
          tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " streaks into the ground in front of you!";
          rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " streaks into the ground in front of "+
                 (string)target->query_name()+"!";
          break;
        case 3:
          tmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " fizzles out before it gets to you!";
          rmsg = "A "+(!random(2) ? HIY : HIW)+"Magic Missile"+NORM+
                 " fizzles out before it gets to "+
                 (string)target->query_name()+"!";
          break;            
      }
      if(misses > 0) misses--;
      tell_object(target, "   "+tmsg+"\n");
      tell_room(room, "   "+rmsg+"\n", ({ target }));      
    }
  }
}

/* 
////////////////////////////////////////////////////////////////////////////
//  Function:    call_chromatic_orb (called from ChromaticOrb spell)
//  Description: atmospheric casting of chromatic orb
//  Arguments:   object target, object room, int damage
////////////////////////////////////////////////////////////////////////////
*/

/* prototype declaration */
string colorize_letters(string str);

void call_chromatic_orb(object target, object room, int damage) 
{
  tell_object(target,
    HIC+" -- -\n"+NORM+
    "  Nazal conjures a "+colorize_letters("chromatic orb")+
    " and tosses it at you!\n"+
    HIC+" -- -\n"+NORM);
  tell_room(room,
    "Nazal conjures a "+colorize_letters("chromatic orb")+
    " and tosses it at you!\n", ({ target })); 
}

string colorize_letters(string str) 
{
  string msg, letter;
  int i;

  msg = "";
  for(i = 0; i < strlen(str); i++) 
  {
    letter = extract(str,i,i);
    switch(random(13)) 
    {
      case 0: letter = RED+letter; break; 
      case 1: letter = YEL+letter; break;
      case 2: letter = GRN+letter; break;
      case 3: letter = BLU+letter; break;
      case 4: letter = CYN+letter; break;
      case 5: letter = MAG+letter; break;
      case 6: letter = HIR+letter; break;
      case 7: letter = HIY+letter; break;
      case 8: letter = HIG+letter; break;
      case 9: letter = HIB+letter; break;
      case 10: letter = HIC+letter; break;                  
      case 11: letter = HIM+letter; break;
      case 12: letter = HIW+letter; break;
    }
    msg += letter;
  }
  msg += NORM;
  return msg;
}

/* 
////////////////////////////////////////////////////////////////////////////
//  Function:    call_blind (called from ColorSpray spell)
//  Description: hits all attackers for 15-40 other|light damage and
//               clones a timed object to lower a players WC (simulating
//               blindness from the light
//  Arguments:   object target, object room, int damage
//  WC_Bonus:    4 (increased by 80%: 50% for limited area attack
//                  and another 30% for spell point drain)
//    .05 (chance) * 34.5 (avg dmg) = 1.725 = 2 ==> (2 * 1.8) = 3.6 = 4
//  AC_Bonus:    2 (given for a players drop in WC, doubled bonus
//                  because it effects all attackers)
//    .05 (chance) * 24.5 (avg wc drop * avg round) = 1.225 = 1 ==> 2
////////////////////////////////////////////////////////////////////////////
*/

status check_attacking_me(object ob) 
{
  return (object)ob->query_attack()==this_object();
}


void call_blind(object target, object room, int damage) 
{
  object *nmys;
  object blindob;
  int time, negwc;
  int beams;
  int s,x;
  string color;
  beams = 3+random(3);
  for(x=0; x<beams; x++) 
  {
    switch(random(5))
    { 
      case 0: color = HIR+"red"+NORM; break;
      case 1: color = HIB+"blue"+NORM; break;
      case 2: color = HIY+"yellow"+NORM; break;
      case 3: color = HIG+"green"+NORM; break;
      case 4: color = HIM+"purple"+NORM; break;
    }
    tell_object(target,
      "A beam of "+color+" light streaks out and strikes you!\n");
    tell_room(room,
      "A beam of "+color+" light streaks out and strikes "+
      (string)target->query_name()+"!\n", ({ target }));
  }
  nmys = filter_array(all_inventory(room), "check_attacking_me", this_object());
  s = sizeof(nmys);
  for(x=0; x < s; x++)
  {
    nmys[x]->hit_player(15+random(26), "other|light");
    if(nmys[x] && !(present("nazal_colorspray_object", nmys[x]))) 
    {
      tell_object(nmys[x],
        "You are blinded by the dazzling display of lights!\n"+
        "You feel drained by the blinding spectrum.\n");
      if((int)nmys[x]->query_sp() > 300)
        nmys[x]->add_spell_point(-270);
      else if((int)nmys[x]->query_sp() > 200)
        nmys[x]->add_spell_point(-160);
      else if((int)nmys[x]->query_sp() > 100)
        nmys[x]->add_spell_point(-90);
      else
        nmys[x]->add_spell_point((-((int)nmys[x]->query_sp())) + 30);        
      time = (5 + random(5));
      negwc = (2 + random(4));
      blindob = clone_object(OBJ+"nazal_colorspray_blindness.c");
      move_object(blindob, nmys[x]);
      blindob->start_blindness(nmys[x], time, negwc);
    }  
  }
}

monster_died() 
{  
	object book, corpse;
#ifdef BIGKILLLOG
  mon_log(BIGKILLLOG);
#endif
  corpse = present("corpse", environment());
  book = present("nazal_fake_spellbook", corpse);
  if(book) 
    destruct(book);
  tell_room(environment(this_object()),
    "With his final breath, Nazal cries: \"You shall never have my spellbook!\"\n"+
    "He throws it to the ground, where it bursts into flames and disappears.\n");
  return 1;
}

