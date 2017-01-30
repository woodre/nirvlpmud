#include "../defs.h"

status main(string str, object gob, object player)
{
  object target, ob;

  if((int)player->query_ghost()) 
    return 0;
    
  if((int)gob->query_skill("combat") < 5 || (int)gob->query_skill("control") < 5) 
    return 0;

  if(!(target = (object)player->query_attack()))
  {
  	tell_object(player,
  	  "You must be fighting to suffocate an opponent.\n");
  	return 1;
  }

  if(!((int)target->is_npc()))
  {
  	tell_object(player,
  	  "You may not suffocate players.\n");
  	return 1;
  }
  
  if((int)player->query_sp() < 30)
  {
    tell_object(player,
      "Your symbiotic link is too weak for that.\n");
    return 1;
  }
	
  if((int)gob->query_mp() < 5)
  {
    tell_object(player,
      "You lack the "+HIW+"Dark Matter"+NORM+" for that.\n");
    return 1;
  }

  if((((int)target->query_hp() * 10) / ((int)target->query_mhp())) > 3)
  {
    tell_object(player,
      (string)target->QN+" is too strong to suffocate.\n");
    return 1;
  }
  
  if(present("neo_suffocate_object", target))
  {
    tell_object(player,
      (string)target->QN+" is already being suffocated.\n");
    return 1;
  }

  if(random(100) > target->query_level())
  {
  	tell_object(player,
  	  "You point at "+(string)target->QN+
  	  " and send a tentacle out to suffocate them...\n"+
  	  "The "+HIW+"Dark Matter Tentacle"+NORM+" forces its way into "+
  	  (string)target->POS+" throat!\n");
  	
    tell_room(environment(player),
      "A tentacle of "+HIW+"Dark Matter"+NORM+
      " flies out and forces its way into "+(string)target->QN+"'s throat.\n"+
      (string)target->QN+" begins to gag and suffocate.\n");

    ob = clone_object(OBJECTS+"suffocate.c");
    ob->set_neo(player->QRN);
    move_object(ob, target);
  }
  
  else
    tell_object(player,
      "Your tentacle lashes out to suffocate "+
      (string)target->QN+" and misses!\n");

  gob->sub_mp(5);
  player->add_spell_point(-30);
  return 1;
}
