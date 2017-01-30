#include "../defs.h"

status main(string str, object PO, object User)
{
  object ob;

  if(GHOST) return 0;
  if(PO->query_creation() < 5) return 0;

  if(PO->query_mp() < 70)
  { 
    TOU "You are too low on "+HIW+"Dark Matter"+NORM+" to perform that.\n"); 
    return 1; 
  }
  if(User->query_sp() < 100)
  { 
    TOU "You lack the energy to perform a heal.\n"); 
    return 1; 
  }

  User->add_spell_point(-100);
  PO->add_mp(-70);

  TOU "You hold out your hand and concentrate for a moment...\n"+
      "A creation ball of "+HIW+"Dark Matter"+NORM+" forms in your upward turned palm.  Look at it to see how to use it.\n");

  TRU User->QN+" closes "+User->POS+" eyes and forms a ball of "+HIW+"Dark Matter"+NORM+" in "+User->POS+" palm.\n", ({ User }));

  ob = clone_object("/players/fred/closed/venom2/OBJ/creationball.c");
  ob->set_who(User->QRN);
  move_object(ob, User);
  return 1;
}
