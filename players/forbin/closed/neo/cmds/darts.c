#include "../defs.h"
#include "valid_attack.h"

status main(string str, object gob, object player)
{
  object target;
  object wound;
  string msg,msg2,msg3;
  int damage, spcost, mpcost, i;

  if((int)player->query_ghost()) 
    return 0;
    
  if((int)gob->query_skill("combat") < 2) 
    return 0;

  if(!str && player->query_attack())
    target = (object)player->query_attack();

  else if(str)
    target = valid_attack(str, player);

  if(!target)
  {
    tell_object(player,
      "What do you want to attack with darts?\n");
    return 1;
  }

  if((int)gob->check_direct_attack())
  {
    tell_object(player,
      "You cannot use darts while being directly attacked.\n");
    return 1;
  }
  
  if((int)player->query_neo_delay()) 
    return 1;

  if((int)player->query_sp() < 45)
  {
    tell_object(player,
      "Your symbiotic link is too weak for that.\n");
    return 1;
  }
	
  damage = ((((int)gob->query_skill("combat") * 3) / 2) + random((((int)gob->query_skill("combat") - 1) * 5)));
  spcost = 45;
  mpcost = 1 + (damage / 6);
	

  tell_object(player,
    PGC+"<"+HIW+" Darts "+PGC+">"+NORM+" You hold out your hand toward "+
    (string)target->QN+"...\n");

  if(damage > 6)
  {
    tell_object(player,
      "     ");
    for(i = 0; i < (damage / 6); i++)
    {
      if(!random(2)) 
        tell_object(player,
          "  "+BOLD+"__ "+NORM+"");
      else 
        tell_object(player,
          "  "+BOLD+"-- --- "+NORM+"");
    }
    tell_object(player,
      "\n\n");
  }
  else
  {
    tell_object(player,
      "             "+BOLD+"- ---          --- -    "+NORM+" \n");
  }
  tell_object(player,
    ""+((damage / 6)+1)+" darts fire from your hand and strike "+
    (string)target->QN+".\n");

  tell_room(environment(player),
    (string)player->QN+" holds out "+(string)player->POS+" hand toward "+(string)target->QN+"...\n"+
    ""+((damage / 6)+1)+" darts fire from "+(string)player->QN+"'s hand and strike "+
    (string)target->QN+".\n", ({ player }) );


  if((object)target->query_attack() != player)
  {
    tell_object(player,
      (string)target->query_name()+" turns "+(string)target->POS+" attention towards you!\n");
    tell_room(environment(player),
      (string)target->query_name()+" turns "+(string)target->POS+
      " attention towards "+(string)player->QN+"!\n", ({ player }) );
    target->attack_object(player);
  }

  if(random(100) < 33)
	{
    if(wound = present("neo_wound_object", target))
    {
      wound->add_ticks(2+random(5));
      wound->add_num(1);
    }
    else
    {
      wound = clone_object(OBJECTS+"wound.c");
      wound->set_ticks(2+random(5));
      wound->set_num(1);
      move_object(wound, target);
    }
  }  
  
  player->add_spell_point(-spcost);
  gob->sub_mp(mpcost);
  gob->set_neo_delay(1);

  return 1;
}
