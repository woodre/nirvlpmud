#include "../defs.h"

static int kickdam;
static string kickhit, kickhit2;
static string kickpart;

int random_kick_how()
{
	kickdam = 0;
	switch(random(10))
	{
    case 0: kickhit = "punt"; kickhit2 = "punts"; kickdam = 0; break;
    case 1..2: kickhit = "kick"; kickhit2 = "kicks"; kickdam = 1; break;
    case 3..5: kickhit = "boot"; kickhit2 = "boots"; kickdam = 2; break;
    case 6..7: kickhit = "jolt"; kickhit2 = "jolts"; kickdam = 3; break;
    case 8..9: kickhit = "crush"; kickhit2 = "crushes"; kickdam = 4; break;
  }
  return kickdam;
}

int random_kick_where()
{
	kickdam = 0;
	switch(random(20))
	{
    case 0..3: kickpart = "hand"; kickdam = 0; break;
    case 4..8: kickpart = "arm"; kickdam = 1; break;
    case 9..12: kickpart = "chest"; kickdam = 2; break;
    case 13..16: kickpart = "leg"; kickdam = 3; break;
    case 17..18: kickpart = "head"; kickdam = 4; break;    	
    case 19: kickpart = "face"; kickdam = 5; break;
  }
  return kickdam;	
}

int kickattack(object gob, object player, object attacker)
{
	int damage;

  if(!attacker)
    return 0;

  damage += random_kick_how();
  damage += random_kick_where();

  tell_object(player,
    PGC+"< "+HIW+"Kick"+PGC+" > "+NORM+"You "+kickhit+" "+(string)attacker->QN+" in the "+kickpart+".\n");
	
  tell_object(attacker,
    PGC+"< "+HIW+"Kick"+PGC+" > "+NORM+""+(string)player->QN+" "+kickhit2+" you in the "+kickpart+".\n");
    
  tell_room(environment(player),
    PGC+"< "+HIW+"Kick"+PGC+" > "+NORM+""+(string)player->QN+" "+kickhit2+" "+
    (string)attacker->QN+" in the "+kickpart+".\n", ({ player, attacker }) );

  return damage;
}      
  
