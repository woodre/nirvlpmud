#include "../defs.h"

inherit SPELL;

void reset(int x)
{
  if(x) return;
  set_spell(
    "Creeping Doom", /* spell name */
    0,              /* hp cost */
    0,              /* sp cost */
    10000,           /* sac cost */
    15,              /* fae req */
    7,              /* glevel req */
  );
}

varargs status main(string str, object gob, object player)
{
  object targ;
  object obj;
  int dam;
  
  if(!str)
  {
    targ = (object)player->query_attack();
    if(!targ)
    {
      tell_object(player,
  	    "You must supply an target.\n");
  	  return 1;
  	}
  }
  
  else if(!(targ = present(str, environment(player))))
  {
    tell_object(player,
      "You don't see "+str+" here.\n");
  	return 1;
  }  
  
  if(present("forbin_dm_creeping_doom_object", targ))
  {
     tell_object(player,
      (string)targ->QN+" is already under the effect of Creeping Doom.\n");
  	return 1;
  }
  
  if(!(targ = spell_ok(0,"attack:npc",str)))
    return 1;

  obj = clone_object(EFFECTS+"creeping_doom.c");
  obj->setup(targ, gob, player);
  move_object(obj, targ);
      
  tell_object(player,
    "Speaking the phrase, "+HIW+"\"sorte strisciando,\""+NORM+" you gesture at "+(string)targ->QN+".\n");
    
  learned_say(
    "Speaking the phrase, "+HIW+"\"sorte strisciando,\""+NORM+" "+
    (string)player->QN+" gestures at "+(string)targ->QN+".\n");
    
  other_say(
    "Speaking a strange phrase, "+
    (string)player->QN+" gestures at "+(string)targ->QN+".\n");
    
  tell_room(environment(player),GRN+
    "\n\tBugs of every size and description begin to crawl out of the\n"+
    "\tground, fall out of the sky, and fly through the air.\n"+
    "\tEvery insect begins to attack "+(string)targ->QN+GRN+".\n\n"+NORM);
  
  if(!(targ->query_attack())) 
    targ->attack_object(player);
    
  return 1;
}

