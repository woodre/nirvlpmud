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
//                  1 AC 2 ring
//                  1800 coins
//  Notable Changes:            
*/

#include "/players/forbin/ansi.h"
inherit "obj/armor";

#define SHORTD HIW+"S"+HIK+"piked "+HIW+"Gaunt"+HIK+"lets"+NORM

void reset(int arg)
{
 if(arg) return;
 ::reset(arg);

  set_name("Spiked Gauntlets");
  SetMultipleIds(({"gauntlets","gauntlet","spiked gauntlets",
                   "spiked gauntlet","shardak gauntlets"}));
  set_short(SHORTD);
  set_ac(2);
  set_params("other|fire", 0, 5, "fire_special");
  set_type("ring");
  set_weight(1);
  set_value(20000);
}

void long()
{
	if(present("shardak_mark", this_player()))
	  long_desc =
	    "Four wide plates of hammered dragonscale overlap to give superb\n"+
	    "protection to the forearm, wrist, and hand.  The plates stop\n"+
	    "short of the knuckles, with dark leather and many tiny rings of\n"+ 
	    "scalemail protecting each of the fingers.  Mounted in the center\n"+
	    "of the hand is a large tooth which looks to make the gauntlets\n"+
	    "a weapon in a quick jamb.\n"+
      "  These boots offer protection from ["+HIR+"fire"+NORM+"].\n";
  else
    long_desc =
	    "Four wide plates of hammered dragonscale overlap to give superb\n"+
	    "protection to the forearm, wrist, and hand.  The plates stop\n"+
	    "short of the knuckles, with dark leather and many tiny rings of\n"+ 
	    "scalemail protecting each of the fingers.  Mounted in the center\n"+
	    "of the hand is a large tooth which looks to make the gauntlets\n"+
	    "a weapon in a quick jamb.\n";    
  ::long();
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
      (string)user->query_name()+"'s gauntlets protect "+
      (string)user->query_objective()+" from the fire.\n", ({ user }) );
    return 0501;
  }
  return 0;
}		