/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Shardak Guild
//  Function:     Guild Armor
//  Create Date:  2005.08.01
//  Last Edit:    2005.08.01 -Forbin
//  Notes:        Special AC 5, weight 3, main armor
//                Requires:
//                  5 dragonscales
//                  3 bone shards
//                  1 AC 4 or 5 main armor
//                  10000 coins
//  Notable Changes:            
*/

#include "/players/forbin/ansi.h"
inherit "obj/armor";

#define SHORTD HIR+"Lo"+NORM+RED+"ri"+HIR+"ca"+NORM+RED+" Se"+HIR+"gm"+NORM+RED+"en"+HIR+"ta"+NORM+RED+"ta"+NORM

void reset(int arg)
{
 if(arg) return;
 ::reset(arg);

  set_name("Lorica Segmentata");
  SetMultipleIds(({"lorica","segmentata","lorica segmentata","dragonscale armor","shardak armor"}));
  set_short(SHORTD);
  set_ac(5);
  set_params("other|fire", 0, 20, "fire_special");
  set_type("armor");
  set_weight(3);
  set_value(20000);
}

void long()
{
	if(present("shardark_mark", this_player()))
	  long_desc =
	    "The standard issue uniform of the elite Shardak Assassins, this\n"+
      "main body armor consists of a padded leather half tunic covered\n"+
      "with several horizontal bands of hammered dragonscale.  Additional\n"+ 
      "bands of dragonscale protect each shoulder.  The armor laces in the\n"+
      "front with strong cord, giving it a tight fit, yet still allows\n"+ 
      "for a full range of motion.  The symbol of Shardak has been painted\n"+ 
      "in white across the left shoulder.\n"+
      "  This armor offers protection from ["+HIR+"fire"+NORM+"].\n";
  else
    long_desc =
	    "The standard issue uniform of the elite Shardak Assassins, this\n"+
      "main body armor consists of a padded leather half tunic covered\n"+
      "with several horizontal bands of hammered dragonscale.  Additional\n"+ 
      "bands of dragonscale protect each shoulder.  The armor laces in the\n"+
      "front with strong cord, giving it a tight fit, yet still allows\n"+ 
      "for a full range of motion.  The symbol of Shardak has been painted\n"+ 
      "in white across the left shoulder.\n";    
  ::long();
}

int do_special(object user)
{
	object nmy;
	if(!present("shardak_mark", user)) 
    return 0;
	if(!(nmy = (object)user->query_attack()))
	  return 0;
  if(!random(10))
  {
  	tell_object(user,
  	  (string)nmy->query_name()+" is cut by the scales on your "+SHORTD+".\n");
  	tell_object(nmy,
  	  "You are cut by the scales on "+
  	  (string)user->query_name()+"'s armor.\n");
  	tell_room(environment(user),
  	  (string)nmy->query_name()+" is cut by the scales on "+
  	  (string)user->query_name()+"'s armor.\n", ({ user, nmy }) );
  	nmy->hit_player(5+random(5), "physical");
  	return 0;  	
  }
  return 0;
}

int fire_special(object user)
{
  if(!present("shardak_mark", user)) 
    return 0;
  if(!random(8))
  {
    tell_object(user,
      "Flames lick at your "+SHORTD+".  Your armor protects you.\n"+NORM);
    tell_room(environment(user),
      (string)user->query_name()+"'s armor protects "+
      (string)user->query_objective()+" from the fire.\n", ({ user }) );
    return 2005;
  }
  return 0;
}		