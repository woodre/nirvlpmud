#include "../defs.h"

status main(string str, object PO, object User)
{
  object ob;
  string type;

  if(GHOST) return 0;
  if(PO->query_creation() < 6) return 0;

  if(!str)
  { 
    TOU "createball <heal, attack, bind, or transfer>\n");
    return 1;
  } 
  if(PO->query_mp() < 50)
  {
    TOU "You do not have enough "+HIW+"Dark Matter"+NORM+" for that.\n");
    return 1;
  }
  if(User->query_sp() < 50)
  {
    TOU "You lack the energy to do that.\n");
    return 1;
  }
  if(str == "heal" || str == "Heal")
    type = "Heal";
  if(str == "attack" || str == "Attack")
    type = "Attack";
  if(str == "bind" || str == "Bind")
    type = "Bind";
  if(str == "transfer" || str == "Transfer")
    type = "Transfer";
  
  if(type == 0)
  {
    TOU "createball <heal, attack, bind, or transfer>\n");
    return 1;
  }

  ob = clone_object("/players/fred/closed/venom2/OBJ/sphere.c");
  ob->set_who(User->QRN);
  ob->set_type_of(type);
  move_object(ob, ENV(User));
  PO->add_mp(-50);
  User->add_spell_point(-50);

  TOU "You place your palm on the ground...\n"+
      "A "+HIW+"Dark Matter Sphere"+NORM+" forms at your feet.\n");

  TRU User->QN+" kneels to the ground...\n"+
      CAP((string)User->PRO)+" forms a "+HIW+"Dark Matter Sphere"+NORM+" at "+User->POS+" feet.\n", ({ User }));
  return 1;
}
