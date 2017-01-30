#include "../../defs.h"
inherit "obj/treasure";
int time;
string location;

reset(arg){
   if (arg) return;

   set_id("portal");
   set_alias("boneportal");
   set_short(BOLD+"A bone portal"+OFF+" [open]");
   set_long("The portal's mist swirls about inside it, beckoning anyone to 'enter'\n"+
            "its dark domain.  Through the portal you can see the realm of death.\n"+
            "The mist forms a dark grin warning you to beware.\n");
   set_weight(6000);
   set_value(0);
}

init()  {
  ::init();
  add_action("enter_portal","enter");
}

enter_portal(str)  {
  if(!str || str != "portal"){
    notify_fail("What would you like to enter?\n");
    return 0;
  }
  write("You step into the bone portal.\n"+
        "You feel the energy of the dark portal flow into your body\n"+
        "as you enter and move to a new location.\n\n");
  say(tpn+" steps into the bone portal.\n");
  move_object(this_player(),PATH+"/room/rod.c");
  command("glance",this_player());
  return 1;
}

set_location(str){
string room; 
  room = PATH+"/room/rod.c";
  location = str; 
  room->add_rift(str);
}

query_location(){ return location; }

set_time(t){ time = t; call_out("dest_portal",time);}

dest_portal(){
string room; 
  room = PATH+"/room/rod.c";
  tell_room(environment(this_object()),"The bone portal sinks back into the ground.\n");
  room->remove_rift(location);
  tell_room(room,"A rift closes.\n");
  destruct(this_object());
}

get()  { return 0; }
