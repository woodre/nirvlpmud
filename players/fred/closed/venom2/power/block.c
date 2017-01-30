#include "../defs.h"

status main(string str, object PO, object User)
{
  if(GHOST) return 0;
  if(PO->query_combat() < 5 || PO->query_creation() < 5) return 0;
  if(User->query_spell_dam()) return 1;
  
  if(PO->query_sdelay())
  {
    TOU "You are already using "+PO->query_sdelay()+".\n");
    return 1;
  }
  if(User->query_sp() < 15)
  {
    TOU "You lack the energy for that.\n");
    return 1;
  }
  if(PO->query_block())
  {
    TOU "You are already blocking!\n");
    return 1;
  }
  if(!User->query_attack())
  {
    TOU PO->query_color()+"You are not fighting!"+NORM+"\n");
    return 1;
  }

  User->add_spell_point(-15);
  PO->set_block((WIL / 5) + random((int)PO->query_combat()));
  
  TOU "You hold your palm outward towards your attacker...\n"+
       HIW+"Dark Matter"+NORM+" swells forward and creates a hard shield to defend you!\n");

  TRU User->QN+" forms a shield from "+BOLD+"Dark Matter"+NORM+"!\n", ({ User }));
  return 1;
}

