
/* bloodlust combat messages */
void blcm(object me)
{
  int x;
  string a,b,myn,he,his;
  x = random(11);
  b = 0;
  myn = capitalize((string)me->query_real_name());
  he = (string)me->query_pronoun();
  his = (string)me->query_possessive();
  switch(x)
  {
  case 0:
    a = "Blood pulses violently through your veins.";
    b = "Blood pulses violently through "+myn+"'s veins.";
    break;
  case 1:
    a = "Sweat pours from your body as you fight.";
    b = "Sweat pours from "+myn+"'s body as "+he+" fights.";
    break;
  case 2:
    a = "Your muscles bulge beneath your skin.";
    b = myn+"'s muscles bulge beneath "+his+" skin.";
    break;
  case 3:
    a = "Your movements are fueled by your rage.";
    b = myn+"'s movements are fueled by "+his+" rage.";
    break;
  case 4:
    a = "Your fists clench uncontrollably.";
    b = myn+"'s fists clench uncontrollably.";
    break;
  case 5:
    a = "You see the world through a bloody haze.";
    b = myn+" sees the world through a bloody haze.";
    break;
  case 6..10:
    a = b = 0;
    break;
  }
  if(a)
    tell_object(me, a+"\n");
  if(b)
    tell_room(environment(me), b+"\n", ({ me }));
}

/* pain aura combat messages */
void pacm(object me)
{
  int x;
  string a,b,myn,he,his,him;
  x = random(11);
  b = 0;
  myn = capitalize((string)me->query_real_name());
  he = (string)me->query_pronoun();
  his = (string)me->query_possessive();
  him = (string)me->query_objective();
  switch(x)
  {
  case 0:
    a = "Your pain drives you to fight harder.";
    b = myn+"'s pain drives "+him+" to fight harder.";
    break;
  case 1:
    a = "The pain of combat feels good to you.";
    b = myn+" smiles at the pain of combat.";
    break;
  case 2:
    a = "You are driven to fight harder by your physical pain.";
    b = myn+" is driven to fight harder by "+his+" physical pain.";
    break;
  case 3:
    a = "Physical pain becomes emotional pleasure for you.";
    b = "Physical pain becomes emotional pleasure for "+myn+".";
    break;
  case 4:
    a = "Your endurance increases as your body becomes bruised.";
    b = myn+"'s endurance increases as "+his+" body becomes bruised.";
    break;
  case 5:
    a = "Your pain translates into increased endurance.";
    b = myn+"'s pain translates into increased endurance.";
    break;
  case 6..10:
    a = b = 0;
    break;
  }
  if(a)
    tell_object(me, a+"\n");
  if(b)
    tell_room(environment(me), b+"\n", ({ me }));
}
