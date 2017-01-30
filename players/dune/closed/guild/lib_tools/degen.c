/* CyberNinja Heal Poison
 * 
 * Temporarily slows/stops monster healing.
 * 
 * Ninjas in history have used poison as a major means of 
 * offensive tactics. CyberNinjas are no different, however,
 * their poisons are more technologically advanced.
 * 
 * 
 * Potency:  1-10           (random number between 1 and guild level)
 * Cost:     4-40 spell pts (4 * Potency)
 * Duration: 20-200 seconds (temporary, lasts Potency * 20 seconds)
 * Effect:   NHR = NHR - Potency (NHR is monster's new heal rate)
 *           NHI = NHI + Potency (NHI is monster's new heal interval)
 * Note:     effect is temporary, so the monster's original
 *           heal rate and interval is restored after Duration seconds
 *
*/

#include "../DEFS.h"


status main(string who)
{
  object ob, poisonManager;
  int potency, glevel, healRate, healIntv, spCost;

  if(!((status)IPTP->item_poisonh()) && !IPTP->guild_wiz()) return 0;

  if (!who)
  {
    if (!TP->query_attack())
    {
      write("Usage: degen <target>\n");
      return 1;
    }
    ob = (object)TP->query_attack(); 
  }

  if (this_player()->query_dead())
  {
    notify_fail("You are a ghost!\n");
    return 1;
  }

  if (who)
  {
    if (!present(who, environment(TP)))
    {
      write("There is no "+capitalize(who)+" here.\n"); 
      return 1; 
    }
    ob = present(who,environment(TP)); 
  }

  if (!call_other(COMBATD, "valid_attack", ob, TP))
  {
    write("You cannot poison that!\n");
    return 1;
  }
  if (ob->is_player())
  {
    /* cannot poison players */
    write("You cannot poison that!\n");
    return 1;
  }
  if (!function_exists("query_heal_rate", ob))
  {
    /* this isn't a real monster... */
    write("You cannot poison that!\n");
    return 1;
  }

  if (!TP->query_interactive()) return 1;

  if (present("_poisonHeal_", ob))
  {
    write(OPN + " is already suffering from this poison.\n");
    return 1;
  }

  glevel = (int)IPTP->guild_lev();

  if (glevel == 1)
  {
    potency = 1;
  }
  else
  {
    potency = random(glevel) + 1;
  }

  spCost = potency * 4;
  if (!gotsp(TP, spCost)) return 1;
  TP->add_spell_point(-spCost);

  tell_room(environment(TP), 
    TPN+" aims "+TP->POS+" arm-mounted dart cannon at "+OPN+".\n");

  if (potency == 1)
  {
    tell_room(environment(TP), 
      "A sparkling " +WHITE+"white"+OFF+
      " poison dart sinks into "+OPN+".\n");
  }
  else if (potency < 5)
  {
    tell_room(environment(TP), 
      potency + " CrAckLiNg " +GREEN+"green"+OFF+
      " poison darts sink into "+OPN+".\n");
  }
  else if (potency < 15)
  {
    tell_room(environment(TP), 
      potency + " ThUnDeRiNg " +BLUE+"blue"+OFF+
      " poison darts slam into "+OPN+".\n");
  }
  else
  {
    tell_room(environment(TP), 
      potency + " *ExPlOdInG* " +MAGENTA+"violet"+OFF+
      " poison darts slam into "+OPN+".\n");
  }

  healRate=(int)ob->query_heal_rate();
  healIntv=(int)ob->query_heal_intv();
  if (healRate == 0)
  {
    /* monster doesn't heal in the first place */
    return 1;
  }
  if (potency > healRate)
  {
    ob->set_heal(0, healIntv + potency);
  }
  else
  {
    ob->set_heal(healRate - potency, healIntv + potency);
  }

  if(!this_player()->query_attack()) this_player()->attack_object(ob);
  if(!ob->query_attack()) ob->attack_object(this_player());

  poisonManager = clone_object(OBJDIR + "/poisonHeal.c");
  poisonManager->setOrigHealRate(healRate);
  poisonManager->setOrigHealIntv(healIntv);
  poisonManager->setPoisonDuration(potency * 20);

  move_object(poisonManager, ob);
  poisonManager->activate();
  
  return 1;
}
