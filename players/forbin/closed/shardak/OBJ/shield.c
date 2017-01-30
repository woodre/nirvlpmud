/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Shardak Guild
//  Function:     Guild Armor
//  Create Date:  2005.08.01
//  Last Edit:    2005.08.01 -Forbin
//  Notes:        Special AC 2, weight 2 shield
//                Requires:
//                  2 dragonscales
//                  2 bone shards
//                  7 gator teeth
//                  1 AC 2 shield
//                  4000 coins
//  Notable Changes:            
*/

#include "/players/forbin/ansi.h"
inherit "obj/armor";

#define SHORTD NORM+RED+"The "+HIR+"Demon's "+NORM+RED+"Maw"+NORM

int Flaming; /* 1 = flaming, 0 = not */
string *Flames;

void reset(int arg)
{
 if(arg) return;
 ::reset(arg);

  set_name("The Demon's Maw");
  SetMultipleIds(({"the demon's maw","the demons maw","the demon maw","maw",
                   "demon's maw","demons maw","demon maw","shield","shardak shield"}));
  set_ac(2);
  set_params("other|fire", 0, 15, "fire_special");
  set_type("shield");
  set_weight(2);
  set_value(20000);
  Flames = ({"burning","enflamed","flaming","ablaze","blazing","afire","ignited","firey"});  
}

mixed short()
{
	if(Flaming)
	{
	  short_desc = SHORTD+" ["+HIR+Flames[random(sizeof(Flames))]+NORM+"]";
	  return ::short();
	}
	else
	{
	  short_desc = SHORTD;
	  return ::short();
	}
}

void long()
{
  if(Flaming) 
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

void init()
{
  ::init();
  add_action("cmd_enflame", "enflame");  
}

status cmd_enflame(string arg)
{
  if(!present("shardak_mark", this_player())) 
    return 0;  
  if(!id(arg))
    return 0;
  if(!present("shardak_fire", environment(this_player())))
  {
    tell_object(this_player(),
      "There is no shardak fire present."+
      "  You must first conjure flames.\n"); 
    return 1;
  }
  if(Flaming)
  {
    tell_object(this_player(),
      SHORTD+"is already enflamed.\n");
    return 1; 
  }
  tell_object(this_player(),
    "You slowly drag "+SHORTD+" across the flames as you\n"+
    "whisper a magikal incantation.  "+HIR+
    "Flames"+NORM+" burst forth from the\n"+
    "demon's mouth and eyes.\n");
   tell_room(environment(this_player()),
    (string)this_player()->query_name()+" slowly drags "+
    SHORTD+" across the flames as "+
    (string)this_player()->query_pronoun()+
    " whispers a magikal incantation.  "+HIR+
    "Flames"+NORM+" burst forth from\n"+
    (string)this_player()->query_name()+"'s shield.\n", ({ this_player() }) );
  Flaming = 1;
  call_out("called_extinguish", 2700);
  return 1;
}

status called_extinguish()
{
  if(!living(environment(this_object())))
  {
    tell_room(environment(this_object()),
      "The flames from "+SHORTD+" die down and extinguish.\n");
    Flaming = 0;    
  }
  else
  {
    tell_object(environment(this_object()),
	  	  "The flames from "+SHORTD+" die down and extinguish.\n");
    Flaming = 0;
  }
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
  	tell_object(user,
  	  "You swing "+SHORTD+", slicing "+
  	  (string)nmy->query_name()+".\n");
  	tell_object(user,
  	  (string)user->query_name()+
  	  " swings "+SHORTD+", slicing you.\n");
  	tell_room(environment(user),
  	  (string)user->query_name()+
  	  " swings "+SHORTD+", slicing "+
  	  (string)nmy->query_name()+".\n", ({ user, nmy }) );
  	nmy->hit_player(5+random(11), "physical");
  	return 0;  	
  }
  else if(!random(10))
  {
  	tell_object(user,
  	  "With a swift move, you bash "+
  	  (string)nmy->query_name()+" with your shield.\n");
  	tell_object(nmy,
  	  "With a swift move, "+
  	  (string)user->query_name()+" bashes you with "+
  	  (string)user->query_possessive()+" shield.\n");  
  	tell_room(environment(user),
  	  "With a swift move, "+
  	  (string)user->query_name()+" bashes "+
  	  (string)nmy->query_name()+" with "+
  	  (string)user->query_possessive()+" shield.\n", ({ user, nmy }) );
  	nmy->hit_player(3+random(7), "physical");
  	return 1;  	
  }
  else if(!random(8))
  {
  	tell_object(user,
  	  "You block "+(string)nmy->query_name()+
  	  "'s attack with "+SHORTD+".\n");
  	tell_object(nmy,
  	  (string)user->query_name()+" blocks your attack with "+
  	  (string)user->query_possessive()+" shield.\n");  
  	tell_room(environment(user),
  	  (string)user->query_name()+" blocks "+
  	  (string)nmy->query_name()+"'s attack with "+
  	  (string)user->query_possessive()+" shield.\n", ({ user, nmy }) );
  	return 2;     
  }
  else if(!random(10) && Flaming)
  {
  	tell_object(user,
  	  "A "+HIR+"stream of flame"+NORM+" spews from your shield, burning "+
  	  (string)nmy->query_name()+".\n");
  	tell_object(nmy,
  	  "A stream of flame spews from "+
  	  (string)user->query_name()+"'s shield, burning you.\n");
  	tell_room(environment(user),
  	  "A stream of flame spews from "+
  	  (string)user->query_name()+"'s shield, burning "+
  	  (string)nmy->query_name()+".\n", ({ user, nmy }) );
  	nmy->hit_player(5+random(6), "other|fire");
  	return 0;  	
  }    
  return 0;
}

int fire_special(object user)
{
	object nmy;
	if(!(nmy = (object)user->query_attack()))
	  return 0;	
  if(!present("shardak_mark", user)) 
    return 0;
  if(!random(8))
  {
    tell_object(user,
      "You block some of the fire damage with your shield.\n");
    tell_room(environment(user),
      (string)user->query_name()+
      " blocks some of the fire damage with "+
      (string)user->query_possessive()+" shield.\n", ({ user }) );
    return 1503;
  }
  return 0;
}	