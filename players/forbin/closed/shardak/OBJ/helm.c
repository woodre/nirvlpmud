/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Shardak Guild
//  Function:     Guild Armor
//  Create Date:  2005.08.02
//  Last Edit:    2005.08.02 -Forbin
//  Notes:        Special AC 2, weight 2, main armor
//                Requires:
//                  2 dragonscales
//                  2 gator teeth
//                  2 AC 2 helmets
//                  3000 coins
//  Notable Changes:            
*/

#include "/players/forbin/ansi.h"
inherit "obj/armor";

#define SHORTD HBRED+HIR+"Visored "+HIW+"Dragon "+HIR+"Helm"+NORM

int Visor; /* 1 = down, 0 = up */

void lower_helm();
void raise_helm();

id(str) { 
  if(Visor)
    return (::id(str) || str == "player_short_object");
  else
    return (::id(str));
}

void reset(int arg)
{
 if(arg) return;
 ::reset(arg);

  set_name("Visored Dragon Helm");
  SetMultipleIds(({"helm","dragon helm","visored dragon helm","shardak helm"}));
  set_ac(2);
  set_params("other|fire", 0, 15, "fire_special");
  set_type("helmet");
  set_weight(2);
  set_value(20000);
}

void init()
{
  ::init();
  add_action("cmd_wear", "wear");
  add_action("cmd_remove", "remove");  	
  add_action("cmd_lower", "lower");
  add_action("cmd_raise", "raise");
}

status cmd_lower(string arg)
{
  if(!arg || arg != "visor")
    return 0;
  if(!worn)
  {
  	tell_object(this_player(),
  	  "You must be wearing the helm to lower its visor.\n");
  	return 1;
  }
  lower_helm();
  return 1;
}

status cmd_raise(string arg)
{
  if(!arg || arg != "visor")
    return 0;
  raise_helm();
  return 1;
}

void lower_helm()
{
  tell_object(this_player(),
    "You lower the visor on your helm.\n");
  tell_room(environment(this_player()),
    (string)this_player()->query_name()+
    " lowers the visor on "+
    (string)this_player()->query_possessive()+
    " helm.\n", ({ this_player() }) );
  Visor = 1;
  environment(this_object())->add_player_id("servant");
  environment(this_object())->add_player_id("servant of shardak");  
}

void raise_helm()
{
  tell_object(this_player(),
    "You raise the visor on your helm.\n");
  tell_room(environment(this_player()),
    (string)this_player()->query_name()+
    " raises the visor on "+
    (string)this_player()->query_possessive()+
    " helm.\n", ({ this_player() }) );
  Visor = 0;  
  environment(this_object())->remove_player_id("servant");
  environment(this_object())->remove_player_id("servant of shardak");
}

int cmd_wear(string arg) 
{
  status wFlag;
  status x;
  wFlag = worn;
  x = (int)::wear(arg);
  return x;
}

status cmd_remove(string arg) 
{
  status wFlag, x;
  wFlag = worn;
  x = (int)::remove(arg);
  if(wFlag && !worn) 
  {
    raise_helm();
  }
  return x;
}

drop() {
  this_object()->cmd_remove("shardak helm");
  ::drop();
}

give() {
  this_object()->cmd_remove("shardak helm");
  ::give();
}

query_player_short() { return NORM+WHT+"Servant of "+RED+"Shardak"+NORM; }

mixed short()
{
	if(Visor)
	{
	  short_desc = SHORTD+HBRED+HIR+" ["+HIW+"closed"+HIR+"]"+NORM;
	  return ::short();
	}
	else
	{
	  short_desc = SHORTD+HBRED+HIR+" ["+NORM+HBRED+WHT+"open"+HIR+"]"+NORM;
	  return ::short();
	}
}

void long()
{
  if(Visor) 
  {
    if(present("shardak_mark", this_player()))
      long_desc =
        "This large round shield has been fashioned to resemble the face\n"+
        "the demon Trogdor, one of many archdevils of flame.  In the center\n"+
        "of the shield, the demon's gapping mouth and hollow eyes are wide\n"+
        "open.  Fire bellows out of the opening, licking the surface of the\n"+
        "shield.  Two shards of bone make an uncomfortable, but effective,\n"+
        "handle and seven teeth ring the circumference of the shield.\n"+
        "  This shield offers protection from ["+HIR+"fire"+NORM+"].\n"; 
    else
      long_desc =
        "This large round shield has been fashioned to resemble the face\n"+
        "the demon Trogdor, one of many archdevils of flame.  In the center\n"+
        "of the shield, the demon's gapping mouth and hollow eyes are wide\n"+
        "open.  Fire bellows out of the opening, licking the surface of the\n"+
        "shield.  Two shards of bone make an uncomfortable, but effective,\n"+
        "handle and seven teeth ring the circumference of the shield.\n"; 
  }
  else
  {
    if(present("shardak_mark", this_player()))
      long_desc =
        "This large round shield has been fashioned to resemble the face\n"+
        "the demon Trogdor, one of many archdevils of flame.  In the center\n"+
        "of the shield, the demon's gapping mouth and hollow eyes are wide\n"+
        "open.  Two shards of bone make an uncomfortable, but effective,\n"+
        "handle and seven teeth ring the circumference of the shield.\n"+
        "  This shield offers protection from ["+HIR+"fire"+NORM+"].\n"+
        "  You may '"+HIW+"enflame"+NORM+"' this shield with shardak fire.\n"; 
    else
      long_desc =
        "This large round shield has been fashioned to resemble the face\n"+
        "the demon Trogdor, one of many archdevils of flame.  In the center\n"+
        "of the shield, the demon's gapping mouth and hollow eyes are wide\n"+
        "open.  Two shards of bone make an uncomfortable, but effective,\n"+
        "handle and seven teeth ring the circumference of the shield.\n";
  }           
  ::long();
}

int do_special(object user)
{
	object nmy;
	if(!(nmy = (object)user->query_attack()))
	  return 0;
  if(!present("shardak_mark", user)) 
    return 0;	  
  if(!random(10))
  {

    
    
  	return 2;  	
  }
  return 0;
}

int fire_special(object user)
{
  if(!present("shardak_mark", user)) 
    return 0;
  if(!Visor)  
  {
    if(!random(12)) 
    {
      tell_object(user,
        "Your "+SHORTD+" resists the fire.\n");
      tell_room(environment(user),
        (string)user->query_name()+"'s helm protects "+
        (string)user->query_objective()+" from the fire.\n", ({ user }) );
      return 2005;
    }
  }
  else
  {
    if(!random(8))
    {
      tell_object(user,
        "Your "+SHORTD+" resists the fire.\n");
      tell_room(environment(user),
        (string)user->query_name()+"'s helm protects "+
        (string)user->query_objective()+" from the fire.\n", ({ user }) );
      return 2005;
    }
  }  
  return 0;
}	