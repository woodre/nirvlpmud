/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     Armor
//  Create Date:  2005.07.26
//  Last Edit:    2005.07.26 -Forbin
//  Notable Changes:            
*/

#include "/players/forbin/realms/flame_forest/ffdefine.h"
inherit "obj/armor";

reset(arg) 
{
	if(arg) return;
  ::reset();  
  set_name("glove of molach");
  set_alias("glove");
  set_short(HIK+"The Glove of "+NORM+CYN+"M"+HIC+"o"+NORM+CYN+"lo"+HIC+"c"+NORM+CYN+"h"+NORM);
  set_long(
    "This glove is made of a strange, dark metal which seems to suck in\n"+ 
    "the surrounding light.  Several interlocking plates protect the back\n"+
    "of the hand, while smaller rings of metal and strips of black leather\n"+
    "cover the fingers.  In the center of the palm rests a single blue gem-\n"+
    "stone.  Across the back, a large, faded blue triangle has been painted\n"+
    "with great care.  A line of script is carefully engraved in small,\n"+
    "flowing calligraphy directly below this.  Perhaps you could read it.\n");
  set_ac(1);
  set_type("gloves");  
  set_weight(1);
  set_value(5555);
}

void init() 
{
	::init();
	add_action("cmd_read", "read");	
	add_action("cmd_trine", "trine");
}

status cmd_read(string arg)
{
  if(!id(arg) && arg != "script")
    return 0;
  tell_object(this_player(),
    "To the bearer of my gift, the ability to '"+NORM+CYN+"Trine"+NORM+"' -"
    +CYN+"M"+HIC+"o"+NORM+CYN+"lo"+HIC+"c"+NORM+CYN+"h"+HIK+" the Corrupter\n"+NORM);
  return 1;  
}

int cmd_trine(string arg)
{
  object nmy;
  int cost, dam;
  string how, umsg, nmsg, rmsg;
  
  if(this_player()->query_ghost())
    return 0;
  if((int)this_player()->query_spell_dam())
  {
  	tell_object(this_player(),
      "Your magical energy has already been used in an attack spell this round.\n");
    return 1;
  }
  if(!worn)
    return 0;
  
  if(!arg && !this_player()->query_attack())
  {
    tell_object(this_player(),
      "You must be in combat to use this spell.\n");
    return 1;
  }
  if(!arg && this_player()->query_attack())
    nmy = (object)this_player()->query_attack();
  else if(arg)
    nmy = present(arg, environment(this_player()));
  if(!nmy)
    return 0;
  if(!nmy->is_npc())
  {
    tell_object(this_player(),
      "You cannot cast "+NORM+CYN+"Trine"+NORM+
      " on "+(string)nmy->query_name()+"\n");
    return 1;
  }
  
  cost = 38;
  
  if((int)this_player()->query_sp() < cost)
  {
    tell_object(this_player(),
      "Nothing happens...\n");
    return 1; 
  }
  
	dam = 10+random(26);
	
	if((int)this_player()->query_attrib("luc") > random(100))
	  dam += 15;
	  
	if(dam > 35)
	  dam = 35;
	
	switch(dam)
	{
    case 35..10000 : how = HIR+"DESTROYED"+NORM; break;
    case 33..34    : how = HIR+"devastated"+NORM; break;
    case 31..32    : how = RED+"pulverized"+NORM; break; 
    case 27..30    : how = HIW+"crushed"+NORM; break;
    case 23..26    : how = "flattened"; break;
    case 18..22    : how = "smashed"; break;
    case 12..17    : how = "hit"; break;
    case 0..11     : how = "annoyed"; break;
    default        : how = "hit"; break;  	
	}
  umsg = 
    "You outstretch your palm towards "+(string)nmy->query_name()+
    " and intone...\n"+
    NORM+CYN+"            ^         ^         ^         ^\n"+"      "+
    HIW+"["+NORM+CYN+"T"+HIW+"]"+NORM+CYN+" / + \\ "+
    HIW+"["+NORM+CYN+"R"+HIW+"]"+NORM+CYN+" / + \\ "+
    HIW+"["+NORM+CYN+"I"+HIW+"]"+NORM+CYN+" / + \\ "+
    HIW+"["+NORM+CYN+"N"+HIW+"]"+NORM+CYN+" / + \\ "+
    HIW+"["+NORM+CYN+"E"+HIW+"]"+NORM+CYN+"\n"+
    "          -----     -----     -----     -----\n"+NORM+
    "Your enemy is encased in a pyramidal prison of sonic fury...\n"+
    (string)nmy->query_name()+" is "+how+" by your "+
    NORM+CYN+"Trine"+NORM+" spell.\n";
    
  nmsg = 
    (string)environment()->query_name()+" outstretches "+
    (string)environment()->query_possessive()+
    " palm towards you and intones...\n"+
    NORM+CYN+"            ^         ^         ^         ^\n"+"      "+
    HIW+"["+NORM+CYN+"T"+HIW+"]"+NORM+CYN+" / + \\ "+
    HIW+"["+NORM+CYN+"R"+HIW+"]"+NORM+CYN+" / + \\ "+
    HIW+"["+NORM+CYN+"I"+HIW+"]"+NORM+CYN+" / + \\ "+
    HIW+"["+NORM+CYN+"N"+HIW+"]"+NORM+CYN+" / + \\ "+
    HIW+"["+NORM+CYN+"E"+HIW+"]"+NORM+CYN+"\n"+
    "          -----     -----     -----     -----\n"+NORM+
    "You are encased in a pyramidal prison of sonic fury...\n"+
    "You are "+how+" by "+(string)environment()->query_name()+
    "'s "+NORM+CYN+"Trine"+NORM+" spell.\n";
      
  rmsg =
    (string)environment()->query_name()+" outstretches "+
    (string)environment()->query_possessive()+
    " palm towards "+(string)nmy->query_name()+
    " and intones...\n"+	
	  (string)nmy->query_name()+" is "+how+" by "+
	  (string)environment()->query_name()+
	  "'s "+NORM+CYN+"Trine"+NORM+" spell.\n";
	  
	this_player()->spell_object(nmy, "Trine", dam, cost, umsg, nmsg, rmsg);
	this_player()->set_spell_dtype("other|mental");  
	
	return 1;
}
