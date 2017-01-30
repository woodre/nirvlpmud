#include "../defs.h"

status main(string str, object PO, object User)
{
  object ob;
  int bonus;
	
  if(GHOST) return 0;
  if(PO->query_control() < 2) return 0;

  if(!str)
  { 
    TOU "Absorb which item?\n"); 
    return 1; 
  }

  ob = present(str, ENV(User));
	
  if(!ob)
  { 
    TOU "You do not see that here.\n"); 
    return 1; 
  }
	
  if(!ob->get() || ob->query_weight() > 15 || 
      ob->query_value() < 1 || living(ob))
  {
    TOU "You cannot absorb that.\n");
    return 1;
  }

  bonus = (int)ob->query_weight();
  if(bonus > (int)PO->query_control())
     bonus = (int)PO->query_control();
  PO->add_mp(bonus);
  TOU PO->query_color()+"< > "+NORM+"You lean over the "+str+" and place your hand over it...\n"+
      "    Tentacles lash out and absorb it, leaving no trace of the "+str+".\n");
  TRU PO->query_color()+"< > "+NORM+User->QN+" leans over the "+str+" and places "+User->POS+" hand over it...\n"+
      "    Tentalces lash out and absorb it, leaving no trace of the "+str+".\n", ({ User }));
  destruct(ob);
  return 1;
}


