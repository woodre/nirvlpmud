#include "../defs.h"

status main(string str, object PO, object User)
{
  object target;
  int woot;
  string msg,msg2,msg3;
  int damage,spamount;
  string wep,where,how;

  if(GHOST) return 0;
  if(PO->query_combat() < 1) return 0;
  if(User->query_spell_dam()) return 1;

  if(PO->query_sdelay())
  {
    TOU "You are already using "+PO->query_sdelay()+".\n");
    return 1;
  }
  if(User->query_sp() < 15)
  {
    TOU "Your symbiotic link is too weak for that.\n");
    return 1;
  }
  if(!User->query_attack())
  {
    TOU "You are not fighting!\n");
    return 1;
  }
	
  switch(random(10) + 1)
  {
    case 10:  wep = "BattleAxe";  break;
    case  9:  wep = "Spear";      break;
    case  8:  wep = "Sword";      break;
    case  7:  wep = "WarDagger";  break;
    case  6:  wep = "Whip";       break;
    case  5:  wep = "Claw";       break;
    case  4:  wep = "Mace";       break;
    case  3:  wep = "WarHammer";  break;
    case  2:  wep = "Maul";       break;
    case  1:  wep = "Scythe";     break;
  }
  switch(random(10) + 1)
  {
    case 10:  where = "head";     break;
    case  9:  where = "hand";     break;
    case  8:  where = "arm";      break;
    case  7:  where = "leg";      break;
    case  6:  where = "thigh";    break;
    case  5:  where = "neck";     break;
    case  4:  where = "shoulder"; break;
    case  3:  where = "stomach";  break;
    case  2:  where = "chest";    break;
    case  1:  where = "chest";    break;
  }

  spamount = 15;
  damage = random(11) + 10;

  switch(damage)
  {
    case     20:  how = HIR+"D e s t r o y e d"+NORM;
    case 17..19:  how = HIR+"Butchered"+NORM;
    case 15..16:  how = RED+"Crushed"+NORM;
    case 12..14:  how = RED+"Struck"+NORM;
    case 10..11:  how = BOLD+"Hit"+NORM;
    case   1..9:  how = "Hit";
  }

  TOU PO->query_color()+"<Weapon>"+NORM+" You shape your arm into a "+wep+"...\n"+
      "You "+how+" "+ATN+" with a "+HIW+"Dark Matter"+NORM+" "+wep+" swing to the "+where+".\n");

  TRU User->QN+" "+how+" "+ATN+" with a "+HIW+"Dark Matter"+NORM+" "+wep+" swing to the "+where+".\n", ({ User }));

  msg = "";
  msg2 = "";
  msg3 = "";
  User->spell_object(User->query_attack(), PO->query_color()+"Dark Matter Weapon"+NORM, damage, spamount,
	msg, msg2, msg3);
  return 1;
}
