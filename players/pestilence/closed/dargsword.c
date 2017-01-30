#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
inherit "/obj/weapon.c";

#define ME this_player()->query_possessive()
#define MEE this_player()->query_objective()

object ob, leg, leg1, leg2, leg3;
int limit = 2;  /* 12/06/05 Fred: Changed from 5. */

  reset(arg) {
    ::reset(arg);
    if(arg) return;

    set_id("blade");
    set_alias("death blade");
    set_short(HIK+"Dark Order "+HIR+"Death"+NORM+" Blade");
    set_long(
       "A sword made for the likes of the Dark Order Trainer.\n"+
       "It has the essence of Daragor forged into the blade\n"+
       "causing ease of attack.\n");
    set_weight(1);
    set_class(18);
    set_value(3500);
    set_type("sword");
    message_hit = ({ 
      HIR+"O B L I T E R A T E S"+NORM," into tiny fragments",
      HIR+"DEVASTATES"+NORM," bone crushing sound",
      HIR+"slashed"+NORM," across the face",           
      HIR+"slashed"+NORM," in the stomach",
      HIR+"stabbed"+NORM," in the throat",
      HIR+"slashed"+NORM," in the knee",
      HIR+"slashed"+NORM," in the leg"
      });
     set_hit_func(this_object());
}

     init() {
       ::init();
}

/* 
 * 10/07/05 Earwax: Recoded this.  Lots of bugging going on.
*/

weapon_hit(attacker) {


  if (random(100) < 30 && limit--) /* 12/06/05 Fred: Changed from < 40. */
  {
	  /* 10/25/05 Earwax: Anti-noob code. */
	  if (TP->query_level() < 19) noob(); 
          /* 12/06/05 Fred: Just cause. */
          if (!random(5) && !environment()->is_kid())
              TP->heal_self(-(random(10)));
    TP->attack();
    return 1;
  }
  limit = 2; /* 12/06/05 Fred: Changed from 5. */
  return 3;
}
        

/* 
 * 10/23/05 Earwax: Added this, no more kids/noobs wielding this.
 *                  Based on Fred's mod to gordie stick.
 */
noob()
{
  int r,x,y,z,amt;
  string it,how;
  x = TP->query_level();
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
       tell_object(TP,
         "You flail "+BOLD+YEL+"wildly"+NORM+" due to your lack of experience and "+BOLD+BLK+how+NORM+" yourself in the "+it+"!\n");
       tell_room(environment(TP),
         TP->query_name()+" flails "+BOLD+YEL+"wildly"+NORM+" due to "+ME+" lack of experience and "+BOLD+BLK+how+"S "+NORM+MEE+"self in the "+it+"!\n", ({ TP }));
       if(x > 10)
       {
         TP->hit_player(1+random(x), "other|fred");
       }
       else
       {
         TP->hit_player((x*(1+random(3))), "other|fred");
       } 
       return -20;
    }
}       
