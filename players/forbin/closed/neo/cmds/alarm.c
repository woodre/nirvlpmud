#include "../defs.h"

status main(string str, object gob, object player)
{
  object ob;
  
  if((int)player->query_ghost()) 
    return 0;
  
  if((int)gob->query_skill("creation") < 3) 
    return 0;

  if((int)gob->query_alarms() >= (1 + (int)gob->query_skill("control") / 3))
  {
    tell_object(player,
      "You have the maximum amount of alarms for your skill level.\n");
    return 1; 
  }
  if((int)gob->query_mp() < 5)
  {
    tell_object(player,
      "You lack the dark "+PGC+"Dark Matter"+NORM+" to do that.\n");
    return 1;
  }
  
  ob = clone_object(OBJECTS+"alarm.c");
  ob->set_owner(player);
  move_object(ob, environment(player));
  
  tell_object(player,
    "You place your palm a few inches off the ground.\n"+  
    "A blob of "+HIW+"Dark Matter"+NORM+
    " oozes out onto the ground.\n");
  tell_room(environment(player),
    (string)player->QN+" places "+(string)player->POS+
    " hand a few inches off the ground.\n"+
    "A blob of "+HIW+"Dark Matter"+NORM+
    "oozes out onto the ground.\n", ({ player }) );
    
  gob->add_alarm(1);
  gob->sub_mp(5);
  return 1;
}
