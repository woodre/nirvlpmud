/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Ruins area (/players/forbin/realms/ruins)
//  Function:     Weakens player
//  Create Date:  2002.07.08
//  Last Edit:    2004.07.08 -Forbin
//  Notes:        -RegisterArmor with negative resistance to physical
//                -negative generic_wc_bonus
//  Approval:     Fred 2004.07.24
//  Notable Changes:
*/

#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"

object Who;
string WhoName;
int Time, NegWC, NegAC;

id(str) { return (str == "shadow_weaken_object" || str == "generic_wc_bonus"); }

string extra_look() {
  object a, e;

  if((a = this_player()) && (e = environment()) && (e == a)) 
    return "You are surrounded by "+HIW+"shadows"+NORM+".  You feel very weak";
  else
    return this_player()->query_name()+" is surrounded by "+HIW+"shadows"+NORM+".  "+subjective(this_player())+" looks very weak";
}

start_weaken(object who, int duration, int negwc, int negac) {
  Who = who;
  WhoName = capitalize(Who->query_real_name());
  Time = duration;
  NegWC = negwc;
  NegAC = negac;
  if(environment(this_object())) 
    tell_object(environment(this_object()),
      HIW+"\n        ^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^\n\n"+
      "          "+HIK+"Darkness bursts forth, surro"+HIW+"unding you in shadows...\n\n"+ 
      HIW+"        ^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^\n\n"+NORM);      
  if(environment(environment(this_object())))
    tell_room(environment(environment(this_object())), 
      "Darkness bursts forth, surrounding "+environment(this_object())->query_name()+" in shadows...\n", ({ environment(this_object()) }));  
  Who->RegisterArmor(this_object(), ({ "physical", 0, -NegAC, "negative_special" }));
  set_heart_beat(1);
}

end_weaken() {
  set_heart_beat(0);
  if(environment(this_object())) 
    tell_object(environment(this_object()),
      HIW+"\n        ^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^\n\n"+
      "              The shadows surro"+NORM+"unding you subside...\n\n"+ 
      HIW+"        ^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^\n\n"+NORM);      
  if(environment(environment(this_object())))
    tell_room(environment(environment(this_object())), 
      "The shadows surrounding "+environment(this_object())->query_name()+" subside...\n", ({ environment(this_object()) }));
  Who->RemoveArmor(this_object());  
  destruct(this_object());
  return 1; 
}

heart_beat() {
  if(!environment(this_object())) { set_heart_beat(0); return 1; }
  if(environment(this_object())->query_ghost()) { end_weaken(); return 1; }
  if(Time < 1) { 
    end_weaken();
    return 1; 
  }  
  Time --;
  if(!random(2)) {
    switch(random(3)) {
      case 0:  tell_object(environment(this_object()),
                 HIW+"Shadows push and pull at you.  You struggle in vain to free yourself.\n"+NORM);
               tell_room(environment(this_object()),
                 environment(this_object())->query_name()+" struggles as shadows push and pull at "+objective(environment(this_object()))+".\n");
               break;
      case 1:  tell_object(environment(this_object()),
                 HIW+"Dark shadows swell over you.  You feel very weak.\n"+NORM);
               tell_room(environment(this_object()),
                 "Dark shadows swell over "+environment(this_object())->query_name()+".\n");
               break;
      case 2:  tell_object(environment(this_object()),
                 HIW+"Your head spins as you strain against the shadows.  You feel dizzy.\n"+NORM);
               tell_room(environment(this_object()),
                 environment(this_object())->query_name()+"stumbles around.\n");                                  
               break;
    }
  }       
}

negative_special(owner) {
  if(!random(4)) {
    tell_object(owner, 
    (!random(2) ? HIW+"Shadows swirl about, weakening you.\n"+NORM : HIW+"The shadows drain your will to defend yourself.\n"+NORM));
    return -(1 + random(4));
  }
}

query_weight() { return 0; }

drop() { return 1; }

get() { return 0; }

generic_wc_bonus() { return -NegWC; }