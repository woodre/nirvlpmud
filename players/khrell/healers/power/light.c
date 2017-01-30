#include "../def.h"

status main(string str, object PO, object User)
{
  if(PO->query_lt()) 
  { 
    PO->set_light(-2); 
    write("You dim the light of your staff.\n");
    say(User->QN+" dims the light of the Staff of Healing.\n"); 
    PO->set_lt(0); 
  }
  
  else 
  { 
    PO->set_light(2); 
    write("You brighten the room with the light of your staff.\n");
    say("The room brightens as "+User->QN+"'s staff glows.\n"); 
    PO->set_lt(1); 
  }
  return 1; 
}
