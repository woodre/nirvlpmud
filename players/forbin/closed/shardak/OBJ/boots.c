/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Shardak Guild
//  Function:     Guild Armor
//  Create Date:  2005.08.01
//  Last Edit:    2005.08.01 -Forbin
//  Notes:        Special AC 2, weight 1 boots
//                Requires:
//                  2 dragonscales
//                  2 bone shards
//                  1 AC 2 boots
//                  2500 coins
//  Notable Changes:            
*/

#include "/players/forbin/ansi.h"
inherit "obj/armor";

#define SHORTD HIK+"Steel-toed "+NORM+RED+"War"+HIK+"Boots"+NORM

void reset(int arg)
{
 if(arg) return;
 ::reset(arg);

  set_name("Steel-toed WarBoots");
  SetMultipleIds(({"warboots","steel-toed boots","steel-toed warboots",
  	               "steel toed boots","steel toed warboots","shardak boots"}));
  set_short(SHORTD);
  set_ac(2);
  set_params("other|fire", 0, 5, "fire_special");
  set_type("boots");
  set_weight(1);
  set_value(20000);
}

void long()
{
	if(present("shardak_mark", this_player()))
	  long_desc =
	    "These pair of boots seem strong enough to take quite a beating.\n"+
	    "They also look fairly comfortable.  The thick rubber soles are\n"+
	    "connected to the upper of rawhide with strong stiching.  There\n"+
	    "are large pieces of black steel fashioned in a way to protect\n"+
	    "the toes, and wide leather laces that run all the way up the\n"+
	    "mid-calf height.  Plates of smithed dragonscales, blackened by\n"+
	    "soil and soot cover the exterior of the boot providing great\n"+
	    "protection.\n"+
      "  These boots offer protection from ["+HIR+"fire"+NORM+"].\n";
  else
    long_desc =
	    "These pair of boots seem strong enough to take quite a beating.\n"+
	    "They also look fairly comfortable.  The thick rubber soles are\n"+
	    "connected to the upper of rawhide with strong stiching.  There\n"+
	    "are large pieces of black steel fashioned in a way to protect\n"+
	    "the toes, and wide leather laces that run all the way up the\n"+
	    "mid-calf height.  Plates of smithed dragonscales, blackened by\n"+
	    "soil and soot cover the exterior of the boot providing great\n"+
	    "protection.\n";    
  ::long();
}

int do_special(object user)
{
	object nmy;
	if(!present("shardak_mark", user)) 
    return 0;
	if(!(nmy = (object)user->query_attack()))
	  return 0;
  if(!random(12))
  {
  	tell_object(user,
  	  "You kick "+(string)nmy->query_name()+", disrupting "+
  	  (string)nmy->query_possessive()+" attack.\n");
    tell_object(nmy,
      (string)user->query_name()+" kicks you, disrupting your attack.\n");  	  
  	tell_room(environment(user),
  	  (string)user->query_name()+" kicks"+
  	  (string)nmy->query_name()+", disrupting "+
  	  (string)nmy->query_possessive()+".\n", ({ user, nmy }) );
  	return 2;  	
  }
  return 0;
}

int fire_special(object user)
{
  if(!present("shardak_mark", user)) 
    return 0;
  if(!random(10))
  {
    tell_object(user,
      "Your "+SHORTD+" protect you from the fire.\n"+NORM);
    tell_room(environment(user),
      (string)user->query_name()+"'s boots protect "+
      (string)user->query_objective()+" from the fire.\n", ({ user }) );
    return 0501;
  }
  return 0;
}		