#include "../defs.h"

status main(string str, object PO, object User)
{

  object target,wound;
  int woot,i;
  string msg,msg2,msg3;
  int damage,spamount;
  string wep,where,how;
	
  if(GHOST) return 0;
  if(PO->query_combat() < 5 || PO->query_control() < 5) return 0;

  if(!User->query_attack())
  {
    TOU PO->query_color()+"You are not fighting!"+NORM+"\n");
    return 1;
  }

  target = (object)User->query_attack();
  if(!target->is_npc())
  {
    TOU "You may only perform this on monsters!\n");
    return 1;
  }
  if(User->query_sp() < 30)
  {
    TOU "You lack the energy for that.\n");
    return 1;
  }
  if(PO->query_mp() < 5)
  {
    TOU "You lack the "+HIW+"Dark Matter"+NORM+" to perform that.\n");
    return 1;
  }
  if(((int)target->query_hp()*10)/((int)target->query_mhp()) > 3)
  {
    TOU ATN+" is still too strong!\n");
    return 1;
  }
  if(present("suffocate_object_venom", target))
  {
    TOU "They are already being suffocated!\n");
    return 1;
  }
  if(random(100) > target->query_level())
  {
    TOU "You point at "+ATN+" and send a tentacle out to suffocate them...\n"+
        "The "+HIW+"Dark Matter Tentacle"+NORM+" flies outward and implants itself down their throat!\n");

    TRU "A tentacle of "+HIW+"Dark Matter"+NORM+" flies out towards "+ATN+" and flies down their throat! "+ATN+" begins to suffocate!\n", ({ User }));

    wound = clone_object("/players/fred/closed/venom2/OBJ/suffocate.c");
    wound->set_who(User->QRN);
    move_object(wound, target);
  }
  else
    TOU "Your tentacle lashes out to suffocate and misses!\n");

  PO->add_mp(-5);
  User->add_spell_point(-30);
  return 1;
}
