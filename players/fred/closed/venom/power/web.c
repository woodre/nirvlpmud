#include "../defs.h"

status main(string str, object PO, object User)
{
  object target, web, comp;
  if(User->query_ghost()) return 0;
  if(User->QL < 14) return 0;
  if(!PO->query_venomed()) return 0;
  if(!str && !User->query_attack()) return 0;
  if(str)
    target = present(str, ENV(User));
  if(User->query_attack())
    target = (object)User->query_attack();
  if(!target)
  {
    TOU "You do not see "+str+" here.\n");
    return 1;
  }
  if(target->is_living() && !target->query_npc())
  {
    TOU "You cannot cast this on players!\n");
    return 1;
  }
  if(User->query_sp() < 30 || PO->query_mp() < 10)
  {
    TOU "Your symbiotic link is too weak.\n");
    return 1;
  }
  if(target->webbed())
  {
    TOU "You cannot web "+target->QN+" again!\n");
    return 1;
  }
  if(random(100) > (INT + WIL + random(100)))
  {
    TOU "You attempt to web "+target->QN+", but miss!\n");
    PO->add_mp(-5);
    User->add_spell_point(-20);
    return 1;
  }

  TRU "A stream of "+HIW+"webs"+NORM+" fly from "+BOLD+CAP((string)PO->query_symbiote())+NORM+"'s hands covering "+target->QN+"!\n", ({ User }));
  
  TOU "A stream of "+HIW+"webs"+NORM+" fly from your hands covering "+target->QN+"!\n");		
  User->add_spell_point(-30);
  PO->add_mp(-10);
  web = clone_object("/players/fred/closed/venom/OBJ/webbing.c");
  web->set_time(20 + User->QL + User->QEL);
  web->web_person(target);
  return 1;
}
