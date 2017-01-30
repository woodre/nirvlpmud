#include "../defs.h"
#include "valid_attack.h"

status main(string str, object gob, object player)
{
  object target;
  int woot;
  string msg,msg2,msg3;
  int damage,spcost;
  string wep,where,how;

  if((int)player->query_ghost()) 
    return 0;
    
  if((int)gob->query_skill("combat") < 1) 
    return 0;

  if(!str && player->query_attack())
    target = (object)player->query_attack();

  else if(str)
    target = valid_attack(str, player);

  if(!target)
  {
  	tell_object(player,
  	  "What do you want to attack?\n");
  	return 1;
  }
  
  if((int)player->query_spell_dam()) 
    return 1;

  if((int)player->query_sp() < 15)
  {
    tell_object(player,
      "Your symbiotic link is too weak for that.\n");
    return 1;
  }
	
  switch(random(10))
  {
    case 0: wep = "BattleAxe"; break;
    case 1: wep = "Spear"; break;
    case 2: wep = "Sword"; break;
    case 3: wep = "WarDagger"; break;
    case 4: wep = "Whip"; break;
    case 5: wep = "Claw"; break;
    case 6: wep = "Mace"; break;
    case 7: wep = "WarHammer"; break;
    case 8: wep = "Maul"; break;
    case 9: wep = "Scythe"; break;
  }
  
  switch(random(10))
  {
    case 0: where = "head"; break;
    case 1: where = "hand"; break;
    case 2: where = "arm"; break;
    case 3: where = "leg"; break;
    case 4: where = "thigh"; break;
    case 5: where = "neck"; break;
    case 6: where = "shoulder"; break;
    case 7: where = "stomach"; break;
    case 8: where = "chest"; break;
    case 9: where = "chest"; break;
  }

  spcost = 15;
  damage = random(11) + 10;

  switch(damage)
  {
    case 20:  how = HIR+"D e s t r o y e d"+NORM;
    case 17..19:  how = HIR+"Butchered"+NORM;
    case 15..16:  how = RED+"Crushed"+NORM;
    case 12..14:  how = RED+"Struck"+NORM;
    case 10..11:  how = BOLD+"Hit"+NORM;
    case 1..9:  how = "Hit";
  }

  tell_object(player,
    PGC+"<"+HIW+" Weapon "+PGC+">"+NORM+" You shape your arm into a "+wep+"...\n"+
      "You "+how+" "+(string)target->QN+
      " with a "+HIW+"Dark Matter"+NORM+" "+wep+" swing to the "+where+".\n");

  tell_room(environment(player),
    (string)player->QN+" "+how+" "+(string)target->QN+" with a "+HIW+"Dark Matter"+NORM+
    " "+wep+" swing to the "+where+".\n", ({ player }) );


  if((object)target->query_attack() != player)
  {
    tell_object(player,
      (string)target->query_name()+" turns "+(string)target->POS+" attention towards you!\n");
    tell_room(environment(player),
      (string)target->query_name()+" turns "+(string)target->POS+
      " attention towards "+(string)player->QN+"!\n", ({ player }) );
    target->attack_object(player);
  }


  msg = "";
  msg2 = "";
  msg3 = "";
  player->spell_object(target, HIW+"Dark Matter Weapon"+NORM, damage, spcost,	msg, msg2, msg3);
  return 1;
}
