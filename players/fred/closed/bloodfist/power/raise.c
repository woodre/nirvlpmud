#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int x,y,z, amt;
  string attrib;
  string *anames; 
  anames =({ "agility", "agl", "might", "mit", "accuracy", "acc",
             "vigor", "vig", "wisdom", "wis", "faith", "fai" });
  if(!str)
  {
    TOU "What attribute do you want to raise and how much?\n");
    return 1;
  }
  if(!PO->query_free_attribs())
  {
    TOU "You do not have any free attributes.\n");
    return 1;
  }
  y = sizeof(anames);
  if((sscanf(str, "%s %d", attrib, amt) == 2))
  {
    x = 0;
    while(x < y)
    {
      if(attrib == anames[x])
        y = 0;
      else
        x++;
    }
    if(y) amt = 0;
  }
  else {
    x = 0;
    while(x < y && amt == 0)
    {
      if(str == anames[x])
        amt = 1;
      else
        x++;
    }
  }

  if(amt <= 0)
  {
    TOU "That is not valid.\n");
    return 1;
  }

  if(x == 1 || x == 3 || x == 5 || x == 7 || x == 9 || x == 11) x--;
  if(x == 0) z = 0;  if(x == 2) z = 1;  if(x == 4)  z = 2;
  if(x == 6) z = 3;  if(x == 8) z = 4;  if(x == 10) z = 5;

  if((PO->query_attrib(z) + amt) > 100)
  {
    TOU "An attribute can not be raised above 100.\n");
    return 1;
  }

  if(PO->query_free_attribs() < amt)
  {
    TOU "You do not have enough free attributes.\n");
    return 1;
  }

  TOU "You raise your "+anames[x]+" from "+PO->query_attrib(z)+
    " to "+(PO->query_attrib(z) + amt)+".\n");

  PO->add_attrib(z, amt);
  PO->advance_checks();

  return 1;
}
