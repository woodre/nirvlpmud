/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     simulates blindness (lowers WC)
//  Create Date:  2005.12.05
//  Last Edit:    2005.12.05 -Forbin
//  Notes:        -negative generic_wc_bonus
//  Approval:     
//  Notable Changes:
*/

#include "/players/forbin/realms/keats/keatsdefine.h"

object Who;
string WhoName;
int Time, NegWC;

id(str) { return (str == "clath_blind_object" || str == "generic_wc_bonus"); }

void start_blindness(object who, int duration, int negwc) 
{
  Who = who;
  WhoName = capitalize((string)Who->query_real_name());
  Time = duration;
  NegWC = negwc;
  set_heart_beat(1);
}

status end_blindness() 
{
  set_heart_beat(0);
  if(environment(this_object())) 
    tell_object(environment(this_object()),
      HIW+"\n\tYour vision returns.\n\n"+NORM);      
  destruct(this_object());
  return 1; 
}

heart_beat() 
{
  if(!environment(this_object())) { set_heart_beat(0); return 1; }
  if(environment(this_object())->query_ghost()) { end_blindness(); return 1; }
  if(Time < 1) { 
    end_blindness();
    return 1; 
  }  
  Time --;
  if(!random(2)) {
    switch(random(3)) {
      case 0:  tell_object(environment(this_object()),
                 "You swing wildly at your attacker.\n");
               break;
      case 1:  tell_object(environment(this_object()),
                 "You can't see straight...You are blinded!\n");
               break;
      case 2:  tell_object(environment(this_object()),
                 "You stumble around blindly.\n");
               break;
    }
  }       
}

query_weight() { return 0; }

drop() { return 1; }

get() { return 0; }

generic_wc_bonus() { return -NegWC; }