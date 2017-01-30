inherit "/obj/monster";
/******************************************************************************
 * Program: calista.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: Sept 14th, 2015 by Dragnar
 *
 * Purpose: A high level monster in the Seven Spires area. This one is the leader
 *          of the White spire (clerics). 
 * * Specials:
 *    1. Blocks specific dtypes the user is using, must rotate dtypes or she is
 *       impossible to kill.
 *    2. Once a dtype is blocked, if the player keeps hitting her with it she will
 *       reflect a bunch of the damage back at the player.
 *    3. Heal_self spells that damage attackers.
 *
 * History:
 *          09/14/2015 - Dragnar
 *            Created
 ******************************************************************************/
#include <ansi.h>
#include "../../defs.h"

#define MAXSHIELD 500
#define RCOLOR "RCOLOR"
mapping shields;
mapping dtype_matrix;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "archedama calista", "archedama", }) );
  set_name("calista");
  set_race("human");
  set_short(HIW+"Archedama"+NORM+" Calista");
set_long(
"A young woman not yet 30 years old, Calista is full of beauty and\n\
grace. She must be truly exceptional to be the head of her order at\n\
such a young age. Her apparance is almost angelic with her white\n\
cleric robe and blonde hair flowing down to her shoulders. Her eyes\n\
look wiser than her years however, and you detect something darker\n\
lurking there that that doesn't match her calling.\n");

  set_gender("female");
  set_level(26);
  set_hp(1600);
  set_ac(25);
  set_wc(46);
  /** Rough bonus for the shields **/
  set_ac_bonus(30);
  /** Bonus for heal_self damage & shield reflection **/
  set_ac_bonus(50);
  
  set_al(-5);
  set_chat_chance(5);
  load_chat(query_name()+" says: 'Healing and Destruction go hand in hand...'\n");
  load_chat(query_name()+" says: 'Beware the power a Healer yields; it is "+HIW+"life"+NORM+" but also "+HIK+"death"+NORM+".'\n");
  
  shields = ([ ]);
  dtype_matrix = ([ "physical":     ({ "Physical" , NORM })
                 ,"magical" :       ({ "Magic", RCOLOR }) 
                 ,"other|fire":     ({ "Fire", HIR }) 
                 ,"other|ice":      ({ "Ice" , HIB }) 
                 ,"other|evil":     ({ "Evil" , RED }) 
                 ,"other|good":     ({ "Good" , HIW }) 
                 ,"other|light":    ({ "Light" , HIY }) 
                 ,"other|dark":     ({ "Dark" , HIK }) 
                 ,"other|poison":   ({ "Poison" , HIG }) 
                 ,"other|electric": ({ "Electric" , YEL }) 
                 ,"other|mental":   ({ "Mental" , BLU }) 
                 ,"other|sonic":    ({ "Sonic" , HIM }) ]);

  add_spell("anti_cure_spell",
    "\n\n#MN# casts an $B$ANTI-Cure$N$ spell on you and your body is wracked with $HR$P A I N$N$.\n",
    "#MN# casts an $B$ANTI-Cure$N$ spell on #TN# and #TP#'s body is wracked with $HR$P A I N$N$.\n",
    35, "60-90", "other|mental", 6, "anti_cure_spell");
    
  add_spell("cure_spell",
    "#MN# casts a $B$Cure$N$ spell and her body is covered with an $B$aura$N$.\n",
    "#MN# casts a $B$Cure$N$ spell and her body is covered with an $B$aura$N$.\n",
    35, 0, 0, 0, "cure_spell");
}

void cure_spell( object target, object room, int damage ) {
  this_object()->heal_self(100);
  set_hp_bonus( hp_bonus + 100 );
}

void anti_cure_spell( object target, object room, int damage ) {
  target->add_spell_point(damage*-1);
}

attack() {
  int i;
  string *dtypes;
  ::attack();
  
  if( attacker_ob ) {
	dtypes = m_indices( shields );
    if( sizeof(dtypes) > 0) 
      tell_room( environment(), query_shield() + "\n");
  }
}

string dtype_color(string str) {
  string msg;
  int x;
  
  /** Magic is a random color **/
  if( str == RCOLOR ) {
    if( !random(4) )
      msg = BLINK;
    else
      msg = NORM;
    
    x = random(10);
    if(x == 0) msg += HIR; else
    if(x == 1) msg += HIG; else
    if(x == 2) msg += HIY; else
    if(x == 3) msg += HIB; else
    if(x == 4) msg += HIM; else
    if(x == 5) msg += HIC; else
    if(x == 6) msg += BLU; else
    if(x == 7) msg += RED; else
    if(x == 8) msg += HIK; else
    msg += HIW;
  }
  else
    msg = str;
  
  return msg;
}


do_damage(int *damage, string *method){
  int i;
  int *dam;
  string dtype;
  string *dtypes;
  object target;
  
  /** Create a local copy of the damage and damage types **/
  dam = damage;
  dtypes = method;
  
  /** Keep track of the damage done and the type of damage **/
  for( i=0; i < sizeof(damage); i++) {
    if( damage[i] > 0 ) {
      dtype = method[i] ? method[i] : "physical";
      
      if( !shields[ dtype ] )
        shields += ([ dtype : ({damage[i], 0 }) ]);
      else
        shields[ dtype ][0] += damage[i];
	
      /** Turn on the shield **/
      if( shields[ dtype ][0] > MAXSHIELD && shields[ dtype ][1] == 0 ) {
      shields[ dtype ][1] = 1;
      tell_room( environment(), "\n\n"+dtype_color( dtype_matrix[dtype][1] ) + query_name()+"'s shield F L A S H E S as it shifts colors!\n"+NORM);
      }
      if( shields[ dtype ][1] == 1 ) {
        /** Remove these since the shield is on **/
        dam -= ({ damage[i] });
        dtypes -= ({ method[i] });
        
        /** Check to see if the player has continued to hit this dtype, growing the power of the reflect **/
        if( shields[ dtype ][0] > MAXSHIELD + (MAXSHIELD/2) ) {
          reflect_spell( dtype );
        }
      }
    }
  }
  
  return ::do_damage( dam, dtypes );
}

void reflect_spell( string dtype ) {
  int dam;
  
  if(!attacker_ob || !environment() || !shields || !shields[dtype] )
    return;
  
  dam = shields[dtype][0] - MAXSHIELD;
  /** reset the damage **/
  shields[dtype][0] = MAXSHIELD;
  tell_room( environment(), "\n\n\n"+dtype_color( dtype_matrix[dtype][1] )+ dtype_matrix[dtype][0]+" energy from "+
               query_name()+"'s shield breaks free and engulfs "+attacker_ob->query_name()+"!\n\n\n"+NORM);
  attacker_ob->hit_player( random(dam), dtype );
}

string query_shield() {
  int shield, i;
  string msg, dtype;
  mixed *arr;
  
  /** Get all the indices of the dtype_matrix mapping **/
  arr = m_indices(dtype_matrix);
  if( !arr )
    return 0;
  
  msg = "";
  /** Loop through all dtypes and print message based on if those types are protected **/
  for( i=0; i < sizeof(arr); i++ ) {
    dtype = arr[i];
    /** If that type is currently shielded, print it on that part of the shield message **/
    if( shields[dtype] && shields[dtype][1] > 0) {
      msg += dtype_color( dtype_matrix[dtype][1] ) + pad("", 5, '#') + NORM;
    }
    else
      msg += HIK+ pad("", 5, '.')+NORM;
  }

  return msg+"\n"+NORM;
}
