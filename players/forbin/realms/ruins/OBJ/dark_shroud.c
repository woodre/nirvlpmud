/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Ruins area (/players/forbin/realms/ruins)
//  Function:     Cloaks the player in darkness
//  Create Date:  2002.07.05
//  Last Edit:    2004.07.05 -Forbin
//  Notes:        -surrounds the player in darkness, light weakens the 
//                   darkness on a 3 second heart_beat - as the 
//                   amount of light increases (up to 5), the duration 
//                   of the darkness shroud decreases  
//                -costs 100 + random(50) sps to use
//                -also includes a RegisterArmor bonus for other|light
//                -will not work while in main village area, those the
//                 duration will decrease anyway
//  Approval:     Fred 2004.07.24
//  Notable Changes:
*/

#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"

int Charge, OnOff;
object Who;

id(str) { return (str == "shroud_of_darkness"); }

short() { 
  if(this_player())
    if(this_player()->query_level() > 20) 
      return "<<INVISIBLE OB>> "+HIW+"Shroud of Darkness ("+NORM+"Charge: "+Charge+" OnOff: "+OnOff+HIW+")"+NORM;
}

string extra_look() {
  object a, e;

  if((a = this_player()) && (e = environment()) && (e == a)) 
    return "You are shrouded in "+HIW+"Darkness"+NORM+"";
  else
    return this_player()->query_name()+" is shrouded in "+HIW+"Darkness"+NORM+"";
}

darken(object who) {
  Who = who;
  Who->RegisterArmor(this_object(), ({ "other|light", 0, 20, "light_special" }));
  set_light(-1);
  Charge = 200 + random(100); 
  OnOff = 1;
  set_heart_beat(1);
}

heart_beat() {
  int is_light;
  if(!environment(this_object())) { set_heart_beat(0); return 1; }
  if(environment(this_object())->query_ghost()) { lighten(); return 1; }
  is_light = set_light(0);
  if(OnOff) is_light += 1;
  if(Charge < 1) { 
    lighten();
    return 1; 
  }  
  if(is_light > 0) {
    if(is_light > 5) is_light = 5;
  Charge -= is_light;
  }  
  if(environment() && environment(environment())) {
    if(!creator(environment(environment()))) {
      if(OnOff) { 
        set_light(1); 
        OnOff = 0; 
      }
    }
    if(creator(environment(environment()))) { 
      if(!OnOff) { 
        set_light(-1); 
        OnOff = 1; 
      }
    }
  }
  if(!random(30)) {
    switch(random(3)) {
      case 0:  tell_object(environment(this_object()),
                 HIW+"\t^~^~^~^~^ Dark shadows flutter about you. ^~^~^~^~^\n"+NORM);
               tell_room(environment(this_object()),
                 "Dark shadows flutter about "+environment(this_object())->query_name()+".\n");
               break;
      case 1:  tell_object(environment(this_object()),
                 HIW+"\t^~^~^~^~^ A dark mist swirls around you. ^~^~^~^~^\n"+NORM);
               tell_room(environment(this_object()),
                 "A dark mist swirls around "+environment(this_object())->query_name()+".\n");
               break;
      case 2:  tell_object(environment(this_object()),
                 HIW+"\t^~^~^~^~^ A blotch of darkness swallows you. ^~^~^~^~^\n"+NORM);
               tell_room(environment(this_object()),
                 "A blotch of darkness swallows "+environment(this_object())->query_name()+".\n");                                  
               break;
    }
  }       
}

lighten() {
  set_heart_beat(0);
  if(environment(this_object())) 
    tell_object(environment(this_object()),
      HIW+"\n        ^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^\n\n"+
      "                The darkness surro"+NORM+"unding you fades...\n\n"+ 
      HIW+"        ^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^\n\n"+NORM);      
  if(environment(environment(this_object())))
    tell_room(environment(environment(this_object())), 
      "The darkness surrounding "+environment(this_object())->query_name()+" fades...\n", ({ environment(this_object()) }));
  set_light(1);
  Who->RemoveArmor(this_object());  
  destruct(this_object());
  return 1; 
}

light_special(object owner) {
  if(!random(8)) {
    tell_object(owner, HIK+"Your overcloak of shadow flickers darkly.\n"+NORM);
    return 1500;
  }
}

query_weight() { return 0; }

drop() { return 1; }

get() { return 0; }