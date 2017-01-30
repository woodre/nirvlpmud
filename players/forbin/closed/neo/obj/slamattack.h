#include "../defs.h"

int slamattack(object gob, object player, object attacker)
{
	int damage;

  if(!attacker)
    return 0;

  if(random(100) < 30)
  {
    tell_object(player,
      PGC+"< "+HIW+"Slam"+PGC+" > "+NORM+"You grab "+(string)attacker->QN+" and toss "+
      (string)attacker->OBJ+" into the air!\n"+
      "         "+(string)attacker->QN+" screams as "+
      (string)attacker->PRO+" crashes into the ground.\n");
	
    tell_object(attacker,
      PGC+"< "+HIW+"Slam"+PGC+" > "+NORM+""+
      (string)player->QN+" grabs you and tosses you into the air.\n"+
      "         You scream as you crash into the ground.\n");
    
    tell_room(environment(player),
      PGC+"< "+HIW+"Slam"+PGC+" > "+NORM+""+
      (string)player->QN+" grabs "+(string)attacker->QN+" and tosses "+
      (string)attacker->OBJ+" into the air!\n"+
      "         "+(string)attacker->QN+" screams as "+
      (string)attacker->PRO+
      " crashes into the ground.\n", ({ player, attacker }) );

    damage = 8;
  }
  
  else if(random(100) < 70)
  {
    tell_object(player,
      PGC+"< "+HIW+"Slam"+PGC+" > "+NORM+"You grab "+(string)attacker->QN+" by the leg.\n"+
      "         "+(string)attacker->QN+" blurs as "+(string)attacker->PRO+
      "is spun around and around.\n"+
      "         "+(string)attacker->QN+" flies wildly through the air, landing with a thud!\n");
	
    tell_object(attacker,
      PGC+"< "+HIW+"Slam"+PGC+" > "+NORM+""+
      (string)player->QN+" grabs you by the leg.\n"+
      "         All you see is a blur as you spin around and around.\n"+
      "         You fly through the air, landing with a solid thud!\n");
    
    tell_room(environment(player),
      PGC+"< "+HIW+"Slam"+PGC+" > "+NORM+""+
      (string)player->QN+" grabs "+(string)attacker->QN+" by the leg.\n"+
      "         "+(string)attacker->QN+" bulrs as "+
      (string)attacker->PRO+" is spund around and around.\n"+
      "         "+(string)attacker->QN+
      " flies through the air, landing with a thud!\n", ({ player, attacker }) );

    damage = 12;  	
  }
  
  else
  {
    tell_object(player,
      PGC+"< "+HIW+"Slam"+PGC+" > "+NORM+"You pick "+(string)attacker->QN+" up high over your head.\n"+
      "         The ground trembles as you hurl "+(string)attacker->OBJ+" before you.\n");
	
    tell_object(attacker,
      PGC+"< "+HIW+"Slam"+PGC+" > "+NORM+""+
      (string)player->QN+" picks you up high over "+
      (string)player->POS+" head.\n"+
      "         The ground trembles as "+
      (string)player->PRO+" hurls you across the room.\n");
    
    tell_room(environment(player),
      PGC+"< "+HIW+"Slam"+PGC+" > "+NORM+""+
      (string)player->QN+" picks "+(string)attacker->QN+" up high over "+
      (string)player->POS+" head.\n"+
      "         The ground trembles as "+
      (string)attacker->QN+" is hurled down before "+
      (string)player->QN+".\n", ({ player, attacker }) );

    damage = 16;  	
  }
  
  return damage;
}      
  
