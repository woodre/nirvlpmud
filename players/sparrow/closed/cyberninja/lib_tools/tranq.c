/* CyberNinja Tranquilizer Poison
 * 
 * Temporarily renders a monster non-aggressive.
 * Basically all this does is monsterObj->set_aggressive(0);
 * 
 * Ninjas in history have used poison as a major means of 
 * offensive tactics. CyberNinjas are no different, however,
 * their poisons are more technologically advanced.
 * 
 * 
 * Cost:     15 spell points
 * Duration: 20-200 seconds (20 * ninja's guild level)
 * Effect:   monsterObj->set_aggressive(0);
 * Note:     effect is temporary, so the monster's aggressiveness
 *           is turned back on after Duration seconds
 *
*/

#include "../DEFS.h"
#include DEFS_ENHANCEMENTS


status main(string who)
{
  object ob, poisonManager;
  int potency;

  if(!((status)IPTP->item_poisona()) && !IPTP->guild_wiz()) return 0;

  if (!gotsp(TP, ENERGY_POISONA)) return 1;

  if (!who)
  {
    if (!TP->query_attack())
    {
      write("Usage: tranq <target>\n");
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
  if (!function_exists("query_aggressive", ob))
  {
    /* this isn't a real monster... */
    write("You cannot poison that!\n");
    return 1;
  }

  if (!ob->query_aggressive())
  {
    write(OPN + " is not aggressive. The poison would be useless.\n");
    return 1;
  }

  if (!TP->query_interactive()) return 1;

  if (present("_poisonAggressive_", ob))
  {
    write(OPN + " is already suffering from this poison.\n");
    return 1;
  }

  potency = (int)IPTP->guild_lev();
  if (potency < 1) potency = 1;
  
  TP->add_spell_point(-ENERGY_POISONA);

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


  ob->set_aggressive(0);

  poisonManager = clone_object(OBJDIR + "/poisonAggressive.c");
  poisonManager->setPoisonDuration(potency * 20);

  move_object(poisonManager, ob);
  poisonManager->activate();
  
  return 1;
}
