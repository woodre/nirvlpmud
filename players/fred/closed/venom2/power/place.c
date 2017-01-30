#include "../defs.h"

status main(string str, object PO, object User)
{
  string one,two;

  if(GHOST) return 0;
  if(User->QL < 15) return 0; 
  if(!PO->query_has_lair()) return 0;

  if(User->query_attack())
  { 
    TOU "You cannot perform this task while you are fighting!\n"); 
    return 1; 
  }
  if((string)ENV(User)->realm() == "NT" || !creator(ENV(User)) ||
     (string)ENV(User)->realm() == "NM")
  {
    TOU "You cannot place your lair here for some reason.\n");
    return 1; 
  }
  if(sscanf(file_name(ENV(User)), "%s#%s", one, two) == 2)
  {
    TOU "You cannot place your lair here for some reason.\n");
    return 1;
  }

  TOU "You place your palm on the ground...\n"+
      HIW+"    D A R K   M A T T E R"+NORM+"  is injected into the ground at your feet.\n");

  PO->set_lair(file_name(ENV(User)));
  PO->set_has_lair(2);
  command("save", User);
  return 1;
}
