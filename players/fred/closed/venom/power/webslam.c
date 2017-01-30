#include "../defs.h"

status main(string str, object PO, object User)
{
  int x_power;
  int i;
  object target, comp;
  int z, amt;
  int how_many;
  int damage, damage2; 
  string atkmsg, msg, msg2, msg3;
  
  if(GHOST) return 0;
  if(!PO->query_venomed()) return 0;
  if(User->query_spell_dam()) return 1;
  if(User->QL < 7) return 0;
  if(PO->query_webf_delay()) return 1;
  if(PO->query_hardened()) return 1;
  if(!User->query_attack())
  {
    TOU "You are not currently fighting.\n");
    return 1;
  }

/* Can't overload a webslam until 15th level */
  if(i && User->query_level() < 15)
    i = 0;

  if(str)
  {
    sscanf(str, "%d", x_power);      
    if(x_power < 1)
    {
      TOU "You must use a positive amount.\n");
      return 1;
    }
    if(x_power > 40)
    {
      TOU "You cannot put that much energy into your attack!\n");
      return 1;
    }
  }

/***** Sp cost **********/
  if(PO->query_slamstat() > 5000)
  {
    amt = 15;
    damage = random(11) + 10;
  }
  else if(PO->query_slamstat() > 1000)
  {
    amt = 16;
    damage = random(11) + 9;
  }
  else if(PO->query_slamstat() > 600)
  {
    amt = 17;
    damage = random(11) + 8;
  }
  else if(PO->query_slamstat() > 300)
  {
    amt = 18;
    damage = random(11) + 7;
  }
  else if(PO->query_slamstat() > 100)
  {
    amt = 19;
    damage = random(11) + 6;
  }
  else
  {
    amt = 20;
    damage = random(11) + 5;
  }
/*************************/

  if(User->query_sp() < amt + x_power)
  {
    TOU	"Your symbiotic link is too weak for that.\n");
    return 1;
  }

  amt += x_power;
  target = (object)User->query_attack();

  if(x_power) damage += random(x_power / 2) + 1;

  PO->add_slamstat(1);

  TRU "A stream of "+HIW+"webs"+NORM+" shoots out from "+BOLD+CAP((string)PO->query_symbiote())+NORM+"'s hands.\n"+
      "The stream of "+HIW+"web"+NORM+" hits "+target->QN+" in the chest.\n");

  if(damage > 33)
  {
    TRU BOLD+CAP((string)PO->query_symbiote())+NORM+" spins "+target->QN+" overhead "+HIR+"S L A M M I N G"+NORM+" them off of the ground.\n");
  }
  else if(damage > 28)
  {
    TRU BOLD+CAP((string)PO->query_symbiote())+NORM+" spins "+target->QN+" about "+HIR+"Pounding"+NORM+" them against the ground.\n");
  }
  else if(damage > 20)
  {
    TRU BOLD+CAP((string)PO->query_symbiote())+NORM+" flips "+target->QN+" over it's shoulder, "+RED+"Driving"+NORM+" them to the ground.\n");
  }
  else if(damage > 15)
  {
    TRU BOLD+CAP((string)PO->query_symbiote())+NORM+" sends "+target->QN+" flying through the air and landing with a dull thud.\n");
  }
  else if(damage > 10)
  {
    TRU BOLD+CAP((string)PO->query_symbiote())+NORM+" throws "+target->QN+", sending them "+(random(40) + 10)+" feet across the room.\n");
  }
  else
  {
    TRU BOLD+CAP((string)PO->query_symbiote())+NORM+" slings "+target->QN+", sending them bouncing across the floor.\n");
  }

  if(User->QL > 19 || (string)User->QRN == "toy")
  {
    TOU "Damage: "+damage+"\n");
  }
  
  msg = "";
  msg2 = "";
  msg3 = "";
  User->spell_object(target, "web slam", damage, amt, 
	msg, msg2, msg3);
  return 1;
}
