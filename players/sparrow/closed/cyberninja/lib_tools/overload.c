#include "../DEFS.h"
#include DEFS_ENHANCEMENTS
/* OVERLOAD DAMAGE ENHANCEMENT
 * Damages player in causing damage to opponent
  * Can kill player ! ! !
  * Does hit_player damage to player
  * Does heal_self damage to opponent
  * Chance of loss of str stat for player
  * Max damage to opponent is random(60)
  * Chance of double damage to player (very dangerous)
*/

#define USE_DELAY 2


status main(string str)
{
  object meat;
  int mhp, hps;
  int damage, snum, meatHp, meatDmg;

  if (!((status)IPTP->item_convert()) && !IPTP->guild_wiz()) return 0;

  if (IPTP->query_use_delay())
  {
    write("Your processor is recovering from use < "+IPTP->query_use_name()+" >\n");
    return 1;
  }

  if (!gotsp(TP, ENERGY_OVERLOAD)) return 1;
  TP->add_spell_point(-ENERGY_OVERLOAD); /* cost is not sp-based */

  hps  = (int)TP->query_hp();
  snum = (int)TP->query_attrib("str");
  damage = (int)IPTP->guild_lev() + random(snum);

  if(environment(TP))
    tell_room(environment(TP),
      "***>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  write("You overload your matter converter!\n"+
        "Intense, burning pain rips through your musculature!\n");
  if(environment(TP))
    tell_room(environment(TP), TPN+" crumples in agony!\n");

  if (!TP->query_attack() ||
      environment((object)TP->query_attack()) != environment(TP))
  {
    TP->hit_player(damage+10);
    if(environment(TP))
      tell_room(environment(TP),
        "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<***\n");
    return 1;
  }

  meat = (object)TP->query_attack();
  meatHp = (int)meat->query_hp();
  meatDmg = random(damage*2);
  if(!meat) return 0;
  if (call_other(COMBATD, "valid_attack", meat, TP))
  {
    write("You channel some excess energy into "+MEAN+"!\n");
    if (environment(TP))
      tell_room(environment(TP),
        "Matter energy crashes into "+MEAN+"!\n");

    if (meatDmg >= meatHp)
    {
      meat->heal_self(-meatHp);
  /* Unnecessary. Verte [6.5.04]  heal_self() will kill.
      meat->hit_player(50);
  */
    }

    if (IPTP->guild_manager()    ||
        TP->query_level() >= 100 ||
        TPN == "Dunetest")
    {
      tell_object(TP, 
        BOLD+"Overload heal_self ["+meatDmg+"/"+(damage*2)+"]"+OFF+"\n");
    }

   /* if meat added by verte */
   if(meat)
    meat->heal_self(-meatDmg);

    /* chance for double damage */
    if (random(snum) < 5)
    {
      if (environment(TP))
        tell_room(environment(TP),
          BOLD+TPN+" gets BlAsTeD by unusually high feedback!"+OFF+"\n");
      /* nanoblood available only to guild leader (highest guild office) */
      if ((status)IPTP->item_nanoblood())   damage += damage / 4;
      else if ((status)IPTP->item_blood())  damage += (damage / 2) + 5;
      else                                  damage += damage + 10;
    }

    TP->hit_player(damage);
  }

  if (snum > 10)
  {
    if (random(snum*5) == 1)
    {
      int strDmg;
      if ((status)IPTP->item_nanoblood())   strDmg = random(2);
      else if ((status)IPTP->item_blood())  strDmg = 1;
      else                                  strDmg = 2;
      if (strDmg > 0)
      {
        write("The conversion overload resulted in permanent damage!\n");
        call_other(TP, "add_attrib", "str", -strDmg);
        TP->save();
      }
    }
  }

  if(environment(TP))
    tell_room(environment(TP),
      "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<***\n");

  IPTP->set_use_delay(USE_DELAY);
  IPTP->set_use_name("OverLoad");
  return 1;
}
