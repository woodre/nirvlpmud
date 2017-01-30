#include "/players/pavlik/guild/mages/defs.h"

/*
 * "fake" party object for guild NPCs to hold.
 * this will pass the "share_exp()" to the owners party
 * object in the event that a target is killed while
 * the guild NPC is the attacker_object.
 */

reset(arg)
{
  if(arg) return;
  return;
}

short() { return; }
long() { return; }
query_value(){ return 0; }
get(){ return 0; }
drop(){ return 1; }

id(str) {
  return str == "party object";
}

share_exp(amount)
{
  object owner;

  if(!environment(this_object()))
	return 0;

  if(!(owner = environment(this_object())->query_owner()))
	return 0;

  if( present("double_xp_object", owner ) )
    amount *= 2;

  if(!present("party object", owner)){
	  owner->add_exp(amount);
	  tell_object(owner,HIG+"Experience Gain: "+amount+"\n"+NORM);
          if( previous_object() && previous_object()->is_npc() )
            owner->set_top_kill( amount, previous_object() );
    if(owner->query_level() < 20 && owner->query_extra_level() < 100)
    {
      int xpn;
      xpn = (int)call_other("/bin/play/_xpnext", "query_next_xp", 0, owner);
      if(xpn <= 0) write("You are ready to advance to your Next Level.\n");
      else write("Experience needed for your Next Level: "+xpn+".\n");
    }
  }
  else{
	  present("party object", owner)->share_exp(amount);
  }
  return 1;
}

