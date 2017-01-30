/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Shardak Guild
//  Function:     Guild Armor
//  Create Date:  2005.08.01
//  Last Edit:    2005.08.01 -Forbin
//  Notes:        Special AC 2, weight 1 amulet
//                Requires:
//                  1 dragonscales
//                  1 bone shards
//                  1 AC 2 amulet
//                  2000 coins
//  Notable Changes:            
*/

#include "/players/forbin/ansi.h"
inherit "obj/armor";

#define SHORTD HIW+"S"+NORM+RED+"ymbol of "+HIW+"S"+NORM+RED+"hardak"+NORM

void reset(int arg)
{
 if(arg) return;
 ::reset(arg);

  set_name("Symbol of Shardak");
  SetMultipleIds(({"symbol","symbol of shardak","shardak symbol",
  	               "symbol shardak","shardak amulet"}));
  set_short(SHORTD);
  set_ac(2);
  set_params("other|fire", 0, 5, "fire_special");
  set_type("amulet");
  set_weight(1);
  set_value(20000);
}

void long()
{
	if(present("shardak_mark", this_player()))
	  long_desc =
	    "This, the Symbol of Shardak, is the mark of his lordship and bears\n"+
	    "witness to his faithful's allegiance.  The outer edge of the emblem\n"+
	    "is a pentagon of red dragonscale which surrounds a carefully made\n"+
	    "pentagram of pearl.  An unpside down cross of broken bone has been\n"+
	    "attached in the center of this.  A rough, jute cord is tied near\n"+
	    "the top so that one might wear it to show their loyalty Shardak.\n"+
      "  This amulet offers protection from ["+HIR+"fire"+NORM+"].\n";
  else
    long_desc =
	    "This, the Symbol of Shardak, is the mark of his lordship and bears\n"+
	    "witness to his faithful's allegiance.  The outer edge of the emblem\n"+
	    "is a pentagon of red dragonscale which surrounds a carefully made\n"+
	    "pentagram of pearl.  An unpside down cross of broken bone has been\n"+
	    "attached in the center of this.  A rough, jute cord is tied near\n"+
	    "the top so that one might wear it to show their loyalty Shardak.\n";    
  ::long();
}

int fire_special(object user)
{
  if(!present("shardak_mark", user)) 
    return 0;
  if(!random(10))
  {
    tell_object(user,
      "Magick "+HIW+"FLARES"+NORM+" from your "+SHORTD+", protecting you from fire.\n"+NORM);
    tell_room(environment(user),
      (string)user->query_name()+"'s amulet flares with magick.\n", ({ user }) );
    return 0501;
  }
  return 0;
}		