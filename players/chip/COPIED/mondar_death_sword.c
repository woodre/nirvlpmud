/* 10/07/05 - Earwax - corrected numerous typos and grammatical errors. 
 *                   - Also recoded the weapon_hit().  Was buggy.
 * 10/20/05 - Earwax - Made minor changes to try to solve bugging.
 * 10/23/05 - Earwax - Added Fred's anti-noob code from gstick to this
 *
 * 12/06/05 - Fred   - Semi nerfed.  I'm sick of this thing pumping out
 *                     insane damage with no drawbacks.
 *
 * 03/06/06 - Earwax - Made it base specials off xlevels
 *                     Recoded special to not use attack, as well
 *
 *Fred:
 *I ran a test for damage dual wielding (dervish/dark order).
 *100 rounds against an ac of 17.
 *
 *These swords before changes:
 *Total Dmg: 6509             
 *Avg. Dmg:  65.9             
 *Max Dmg:    256             
 *
 *Other weps:
 *Finely Honed as a 19+21:                    Element of Air
 *Total Dmg: 2505                                 3132   
 *Avg. Dmg:  25.5                                31.32 
 *Max Dmg:     58                                   94
 *
 *Elemental weps
 *Total Dmg: 2933
 *Avg. Dmg: 29.33
 *Max Dmg:     72
 *
 *After Changes to these swords:
 *Total Dmg: 3189  
 *Avg. Dmg: 31.89
 *Max Dmg:    138
 *
 * Still has potential to do good damage but it's not totally bs compared to other weps.
*/

#include "/obj/ansi.h"
inherit "/obj/weapon.c";
#define CHANCE (10 + (this_player()->query_extra_level()/5))

#define ME this_player()->query_possessive()
#define MEE this_player()->query_objective()

/* Global Variables */
int chance;
object ob;
int limit = 2;  /* 12/06/05 Fred: Changed from 5. */

  reset(arg) {
    ::reset(arg);
    if(arg) return;

    set_id("blade");
    set_alias("death blade");
    set_short("Iron "+HIK+"Death"+NORM+" Blade");
    set_long(
       "The weapon is edged perfection.  A simple bladed\n"+
       "bastard sword with an inscribed death rune at the\n"+
       "base of the blade.\n");
    set_weight(2);
    set_class(20);
    set_value(3500);
    set_type("sword");
    /* 10/07/05 Earwax: These need further work. */
    /* 10/07/05 Earwax: These need further work. */
    message_hit = ({ 
      HIK+"slashed"+NORM," in the eye",
      HIK+"stabbed"+NORM," in the chest",
      HIK+"chopped"+NORM," in the arm",           
      HIK+"impaled"+NORM," in the stomach",
      HIK+"stabbed"+NORM," in the body",
      HIK+"slashed"+NORM," in the knee",
      HIK+"sweeped"+NORM," in the leg"
      });
     set_hit_func(this_object());
}

     init() {
       ::init();
}

/* 03/06/06 Earwax:  Recoded this to remove attack() call and balance
 * this thing for the final time, hopefully.
 * 
 * 06/30/06 Earwax: Made it return random(4) if it doesn't special
 * made some changes to reduce bugging, changed the damage dealt to
 * go off the weapon class rather than a set amount, so if the weapon
 * breaks, damage is lessened.
 */
weapon_hit(attacker) {
  int i, dam, ret;
  string m1, m2;
  string name;
  string *msg;

  if (!attacker || !environment() || !environment(attacker))
    return 0;
 if(!this_player()) return 0;
  if (this_player()->query_real_name() == "mondar" || (this_player() != environment(this_object())))
    return 0;
  
  if (chance < random(100)) {
    chance = CHANCE;
    attacker->hit_player(random(10), "magical");
    return random(5);
  }

  /* Do mean things if it's a kid or a noob */
  if (this_player()->query_level() < 19) noob();
  if (!random(5) && !environment()->is_kid())
    this_player()->heal_self(-(random(10)));

  name = attacker->query_name();
  dam = class_of_weapon+random(5);

  /* Get the hit message. */
  msg = query_message_hit(random(dam));
  m1 = msg[1];
  m2 = msg[0];
  tell_object(this_player(), "You "+m1+ " " + name+""+m2+".\n");
  if (attacker)
    tell_object(attacker, this_player()->query_name()+" "+m1+" you"+m2+".\n");
  tell_room(environment(this_player()), this_player()->query_name()+" "+m1+" "+name+m2+".\n", ({ attacker, this_player() }) );

  /* Do damage, recurse. */
  attacker->do_damage( ({ dam }), ({ "physical" }) );
  chance = (chance * 2) / 3;
  ret = weapon_hit(attacker);

  return (ret > 5 ? 5 : ret);
}

/* 
 * 10/23/05 Earwax: Added this, no more kids/noobs wielding this.
 *                  Based on Fred's mod to gordie stick.
 */
noob()
{
  int r,x,y,z,amt;
  string it,how;
  x = this_player()->query_level();
  y = random(10);
  r = random(6);
  z = 1+random(x);  
    switch(y)
    {
      case 0: it = "shoulder"; break;
      case 1: it = "arm"; break;
      case 2: it = "mid section"; break;
      case 3: it = "leg"; break;
      case 4: it = "head"; break;
      case 5: it = "shin"; break;
      case 6: it = "foot"; break;
      case 7: it = "thigh"; break;
      case 8: it = "face"; break;
      case 9: it = "ankle"; break;
    }
    switch(r)
    {
      case 0: how = "CRACK"; break;
      case 1: how = "SMACK"; break;
      case 2: how = "GOUGE"; break;
      case 3: how = "SLASH"; break;
      case 4: how = "CUT"; break;
      case 5: how = "WHACK"; break;
    }
    if(x < 6)            amt = 9;
    if(x > 5 && x < 8)   amt = 7;
    if(x > 7 && x < 11)  amt = 6;
    if(x > 10 && x < 14) amt = 5;
    if(x > 13 && x < 17) amt = 4;
    if(x > 16)           amt = 3;
    if((z*amt) > random(100))
    {
       tell_object(this_player(),
         "You flail "+BOLD+YEL+"wildly"+NORM+" due to your lack of experience and "+BOLD+BLK+how+NORM+" yourself in the "+it+"!\n");
       tell_room(environment(this_player()),
         this_player()->query_name()+" flails "+BOLD+YEL+"wildly"+NORM+" due to "+ME+" lack of experience and "+BOLD+BLK+how+"S "+NORM+MEE+"self in the "+it+"!\n", ({ this_player() }));
       if(x > 10)
       {
         this_player()->hit_player(1+random(x), "other|fred");
       }
       else
       {
         this_player()->hit_player((x*(1+random(3))), "other|fred");
       } 
       return -20;
    }
}       
/*
 * 03/06/06 Earwax: Commented this out.
 * 10/07/05 Earwax: Recoded this.  Lots of bugging going on.

weapon_hit(attacker) {
  int i;
  string m1, m2;

  if (TPRN == "mondar" || (this_player() != environment(this_object())))
    return;
  if (random(100) < 30 && limit--) /* 12/06/05 Fred: Changed from < 40. /
  {
	  /* 10/25/05 Earwax: Anti-noob code. /
	  if (TP->query_level() < 19) noob(); 
          /* 12/06/05 Fred: Just cause. /
          if (!random(5) && !environment()->is_kid())
              TP->heal_self(-(random(10)));
    TP->attack();
    return 1;
  }
  limit = 2; /* 12/06/05 Fred: Changed from 5. /
  return 3;
}
*/
