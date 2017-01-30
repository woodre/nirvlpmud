#include "../defs.h"

static int clawdam;
static string clawhit, clawhit2;
static string clawpart;

int random_claw_how()
{
	clawdam = 0;
	switch(random(10))
	{
    case 0: clawhit = "graze"; clawhit2 = "grazes"; clawdam = 0; break;
    case 1..2: clawhit = "nick"; clawhit2 = "nicks"; clawdam = 1; break;
    case 3..5: clawhit = "smack"; clawhit2 = "smacks"; clawdam = 2; break;
    case 6..7: clawhit = "slash"; clawhit2 = "slashes"; clawdam = 3; break;
    case 8..9: clawhit = "rip"; clawhit2 = "rips"; clawdam = 4; break;
  }
  return clawdam;
}

int random_claw_where()
{
	clawdam = 0;
	switch(random(20))
	{
    case 0..3: clawpart = "hand"; clawdam = 0; break;
    case 4..8: clawpart = "arm"; clawdam = 1; break;
    case 9..12: clawpart = "chest"; clawdam = 2; break;
    case 13..16: clawpart = "leg"; clawdam = 3; break;
    case 17..18: clawpart = "head"; clawdam = 4; break;    	
    case 19: clawpart = "face"; clawdam = 5; break;
  }
  return clawdam;	
}

int clawattack(object gob, object player, object attacker)
{
	int damage;

  if(!attacker)
    return 0;

  damage += random_claw_how();
  damage += random_claw_where();

  tell_object(player,
    PGC+"< "+HIW+"Claw"+PGC+" > "+NORM+"You "+clawhit+" "+(string)attacker->QN+" in the "+clawpart+".\n");
	
  tell_object(attacker,
    PGC+"< "+HIW+"Claw"+PGC+" > "+NORM+""+(string)player->QN+" "+clawhit2+" you in the "+clawpart+".\n");
    
  tell_room(environment(player),
    PGC+"< "+HIW+"Claw"+PGC+" > "+NORM+""+(string)player->QN+" "+clawhit2+" "+
    (string)attacker->QN+" in the "+clawpart+".\n", ({ player, attacker }) );

  return damage;
}      
  
