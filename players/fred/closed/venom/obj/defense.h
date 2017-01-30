venom_defense()
{
  int def;
  def = random(USER->query_attrib("ste") * 5);
  defense_bonus = 0;
  if(!ATT) return;
  if(def > 85)
  {
    TOM "<"+HIB+"defend"+NORM+"> Tentacles lash out from you.\n"+
        "         "+ATT->QN+" fights for control of "+ATT->POS+" weapon.\n"+
        "         "+ATT->QN+" is slowly over powered.\n");
    TRM "Tentacles lash out from "+CAP((string)GOB->query_symbiote())+".\n"+
        ""+ATT->QN+" fights for control of "+ATT->POS+" weapon.\n"+
        ""+ATT->QN+" is slowly over powered.\n", ({USER}));
    defense_bonus = 14;
  }
  else if(def > 64)
  {
    TOM "<"+HIB+"defend"+NORM+"> You headbutt the oncoming attack.\n"+
        "         You then screech in ecstasy.\n"+
        "         "+ATT->QN+" cringes.\n");
    TRM CAP((string)GOB->query_symbiote())+" headbutts the on coming attack.\n"+
        CAP((string)GOB->query_symbiote())+" screeches in ecstasy.\n"+
        ""+ATT->QN+" cringes.\n", ({USER}));
    defense_bonus = 8;
  }
  else if(def > 55)
  {
    TOM "<"+HIB+"defend"+NORM+"> You smack the attack aside.\n");
    TRM CAP((string)GOB->query_symbiote())+" smacks the attack aside.\n", ({USER}));
    defense_bonus = 5;
  }
  else if(def > 35)
  {
    TOM "<"+HIB+"defend"+NORM+"> You tense up absorbing most of the impact.\n");
    TRM CAP((string)GOB->query_symbiote())+" tenses up absorbing most of the impact.\n", ({USER}));
    defense_bonus = 3;
  }
  else if(def > 5)
  {
    TOM "<"+HIB+"defend"+NORM+"> You leap aside.\n");
    TRM CAP((string)GOB->query_symbiote())+" leaps aside.\n", ({USER}));
    defense_bonus = 1;
  }
  return defense_bonus;
}
