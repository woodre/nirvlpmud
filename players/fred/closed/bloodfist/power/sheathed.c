#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int x, sheathed, max_sheathed, ths;
  string st, nst, xt;
  object *inv;

  sheathed = (int)PO->query_sheathed();
  max_sheathed = (int)PO->query_max_sheathed();
  inv = all_inventory(PO);
  ths = sizeof(inv);

  TOU "Your sheathed weapons...\n\n");

  for(x = 0; x < ths; x++)
  {
    if(x < sheathed)
    {
      st = (string)inv[x]->short();
      if(User->query_level() >= 40)
      {
        if(sscanf(st, "%s  <%s", nst, xt)){}
      }
      else
        nst = st;
      TOU " "+(x+1)+". "+nst+"\n");
    }
    else
      TOU " "+(x+1)+".\n");
  }

  if(PO->query_a_c())
    TOU "\nAdditional commands: sheath, unsheath\n");
  else
    TOU "\n");

  return 1;
}

