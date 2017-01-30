#include "../defs.h"

object Neo;

id(str) { return str == "neo_suffocate_object"; }

int drop() { return 1; }

int query_value(){ return 0; }

int query_weight(){ return 0; }

void init()
{
  if(environment())
  {
    if(living(environment()))
      call_out("suffocate", 1);
  }
}

void set_neo(object x) { Neo = x; }
object query_neo() { return Neo; }

mixed suffocate()
{
	int damage;
	
	if(!environment()) 
	  return;
	  
	if(!living(environment()))
  { 
		destruct(this_object()); 
		return 1; 
  }
  
	if((((int)environment()->query_hp() * 10) / ((int)environment()->query_mhp())) > 3)
	{
	  tell_room(environment(environment()),
      (string)environment()->QN+" shrugs off the tentacle suffocating it!\n");
    destruct(this_object());
		return 1;
  }
  
  if(!present(Neo, environment(environment())))
  {
    destruct(this_object());
    return 1;
  }
  
  if(!environment()->query_attack())
  {
    tell_room(environment(environment()),
      (string)environment()->QN+" yanks the tentacle out of its throat!\n");
    destruct(this_object());
    return 1;
  }

  damage = 4 + random(6);
  if(!random(3))
    tell_room(environment(environment()),
      (string)environment()->QN+
      " gags as the tentacle burrows deeper down their throat!\n", ({ environment() }) );
	environment()->hit_player(damage, "other|forbin");
	remove_call_out("suffocate");
	call_out("sufocate", 2);
}
