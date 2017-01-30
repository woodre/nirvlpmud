#include "../defs.h"
#include "/players/forbin/closed/dm/inherits/color_string.h"

int HPCost;
int SPCost;
int SacCost;
int FaeReq;
int GLevelReq;
string SpellName;

void set_spell(string sn, int hp, int sp, int sac, int fae, int glvl)
{
  SpellName = sn;
  HPCost = hp;
  SPCost = sp;
  SacCost = sac;
  FaeReq = fae;
  GLevelReq = glvl;
}

status learned(object ob) 
{ 
  object dmo;
  if(ob->is_player())
  {
    if((dmo = present("forbin_dm_object", ob)))
    {
      if(dmo->query_learned(SpellName))
        return 1;
      else
        return 0;  
    }
  }
  return 0;
}

status not_learned(object ob) { return !learned(ob); }

void learned_say(string str)
{
  object *objs;
  int    s;
  objs = filter_array(all_inventory(environment(this_player())), "learned", this_object());
  
  s = sizeof(objs);
  while(s--)
  {
    if(objs[s] != this_player())
      tell_object(objs[s], str);
  }
}

void other_say(string str)
{
  object *objs;
  int s;
  objs = filter_array(all_inventory(environment(this_player())), "not_learned", this_object());
  
  s = sizeof(objs);
  while(s--)
  {
    if(objs[s] != this_player())
      tell_object(objs[s], str);
  }
}

varargs object spell_ok(int target_needed, string target_type, string target)
{
  object gob, targ;
  string type, subtype;
  
  gob = present("forbin_dm_object", this_player());
  
  if(target_needed && !target)
  {
  	tell_object(this_player(),
  	  "You must supply an target.\n");
  	return 0;
  }
  
  sscanf(target_type, "%s:%s", type, subtype);
  
  if((int)this_player()->query_ghost())
  {
    tell_object(this_player(),
  	  "You are dead.\n");
    return 0;
  }
   
  if(!((int)gob->query_learned(SpellName)) &&
     !((int)gob->query_learned("all")))
  {
  	tell_object(this_player(),
  	  "What?\n");
    return 0;
  }
  
  if((int)gob->query_glevel() < GLevelReq)
  {
    tell_object(this_player(),
  	  "Your mastery of the "+color_string("fae")+" is not enough for you to use\n"+
      "the ability of \""+SpellName+"\".\n");
    return 0;
  }

  if((int)gob->query_fae() < FaeReq)
  {
    tell_object(this_player(),
  	  "Your control of the "+color_string("fae")+" is not enough for you to use\n"+
      "the ability of \""+SpellName+"\".\n");
    return 0;
  }
  
  if(!((int)gob->check_sacrifice(SacCost)))
  {
    tell_object(this_player(),
  	  "The darkness calls for a sacrifice.\n");
    return 0;
  }
  
  if((int)this_player()->query_sp() < SPCost)
  {
    tell_object(this_player(),
  	  "You need "+SPCost+" spell points to use this ability.\n");
    return 0;
  }
  
  if((int)this_player()->query_hp() < HPCost)
  {
    tell_object(this_player(),
  	  "You need "+HPCost+" hit points to use this ability.\n");
    return 0;
  }

  if(type == "attack")
  {
  	if(target)
  	{
      if(!(targ = present(target, environment(this_player()))))
      {
  	    tell_object(this_player(),
  		    "You don't see "+target+" here.\n");
  		  return 0;
  	  }
  	}
    else if(!(targ = (object)this_player()->query_attack()))
    {
    	tell_object(this_player(),
    	  "You must supply a target.\n");
    	return 0;
  	}
  	if(subtype == "npc")
  	{
      if(!(targ->is_npc()))
      {
      	tell_object(this_player(),
    	    "You cannot use this ability on "+targ->short()+".\n");
    	  return 0;  		
    	}
  	}
    if(subtype == "player")
    {
      if(!(targ->is_npc()) && !(query_ip_number(targ)))
      {
      	tell_object(this_player(),
    	    "You cannot use this ability on "+targ->short()+".\n");
    	  return 0;
      }
    }
  }

  if(type == "other")
  {
  	if(target)
  	{
      if(!(targ = present(target, environment(this_player()))) &&
         !(targ = present(target, this_player())))
      {
  	    tell_object(this_player(),
  		    "You don't see "+target+" here.\n");
  		  return 0;
  	  }
  	}
  	if(subtype == "npc")
  	{
  		if(!targ)
  		  targ = (object)this_player()->query_attack();
      if(!(targ->is_npc()))
      {
      	tell_object(this_player(),
    	    "You cannot use this ability on "+targ->short()+".\n");
    	  return 0;  		
    	}
  	}
  	if(subtype == "player")
  	{
  		if(!targ)
  		  targ = (object)this_player()->query_attack();
      if(!(targ->is_npc()) && !(query_ip_number(targ)))
      {
      	tell_object(this_player(),
    	    "You cannot use this ability on "+targ->short()+".\n");
    	  return 0;  		
    	}
    }  	
  	if(subtype == "self")
  	{
  		if(!targ)
  		  targ = this_player();
    }
  	if(subtype == "armor")
  	{
  		if(!targ)
  		{
  		  tell_object(this_player(),
  	      "You must supply an target.\n");
  	    return 0;
  		}
  		if(!((int)targ->is_armor()))
  		{
      	tell_object(this_player(),
    	    "You cannot use this ability on "+targ->short()+".\n");
    	  return 0;  
  		}
    }    
  	if(subtype == "weapon")
  	{
  		if(!targ)
  		{
  		  tell_object(this_player(),
  	      "You must supply an target.\n");
  	    return 0;
  		}
  		if(!((int)targ->is_weapon()))
  		{
      	tell_object(this_player(),
    	    "You cannot use this ability on "+targ->short()+".\n");
    	  return 0;  
  		}
    }      
  }
  if((string)environment(this_player())->realm() == "NM")
  {
  	tell_object(this_player(),
  	  "The "+color_string("fae")+" refuses to respond here.\n");
  	  return 0;
  }
  
  this_player()->add_sp(-HPCost);
  this_player()->add_hp(-SPCost);
  gob->sub_sacrifice(SacCost);
  
  return targ;
}
