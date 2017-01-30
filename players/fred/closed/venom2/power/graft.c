#include "../defs.h"

status main(string str, object PO, object User)
{
  object ob;

  if(GHOST) return 0;
  if(PO->query_control() < 3) return 0;

  if(!str)
  { 
    TOU "graft <armor>\n"); 
    return 1; 
  }

  ob = present(str, User);
  if(!ob)
  { 
    TOU "You do not see that.\n"); 
    return 1; 
  }
  if(!ob->armor_class())
  {
    TOU "You do not believe it would do any good to graft that.\n");
    return 1;
  }
  if(!ob->is_armor())
  { 
    TOU "That is not something you can graft!\n"); 
    return 1; 
  }
  if(PO->query_mp() < 30)
  {
    TOU "You lack the matter to graft.\n");
    return 1;
  }
  if(PO->check_armors(ob->query_type()))
  {
    TOU "You already have "+ob->query_type()+" type armor worn!\n");
    return 1;
  }
  
  TOU "You concentrate and extend "+HIW+"Dark Matter"+NORM+" tentacles out toward the\n"+
      ob->short()+". They burrow into the piece of armor and extend\n"+
      "throughout its internal structure. The armor is pulled to your\n"+
      "body and grafted to your skin.\n");

  TRU User->QN+" grafts "+ob->short()+" to "+User->POS+" skin.\n", ({ USER }));

  PO->add_mp(-30);
  PO->add_gr_armors(ob->query_type(), ob->short(), ob->armor_class());
  destruct(ob);
  return 1;
}
