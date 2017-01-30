#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cur, max, x;
  object tmp;
  string a,t,s,ns,js;
  if(User->query_ghost()) return 0;
  max = (int)PO->query_chosen_max();
  cur = (int)PO->query_chosen_current();
  if(!max)
  {
    TOU "You are unable to choose any weapons to master.\n");
    return 1;
  }
  else if(max && !cur)
  {
    TOU "You have not chosen any weapons to master yet.\n");
    for(x = 0; x < max; x++)
      TOU " "+(x+1)+".\n");
  }
  else if(max < cur)
  {
    TOU "You have chosen more than your maximum allowed.\n"+
        "Please contact your System Administrator.\n");
  }
  else if(max && cur)
  {
    TOU "These are your chosen weapons:\n"+
        "    Name                                        Level    Exp\n");
    for(x = 0; x < max; x++)
    {
      a = "/"+PO->query_chosen(x)+".c";
      if(a == "/0.c")
        TOU " "+(x+1)+".\n");
      else
      {
        if(loadObject(a))
        {
          tmp = clone_object(a);
          s = (string)tmp->short();
          /*
          if(User->query_level() >= 40){
            if(sscanf(s, "%s  <%s", ns, js)){}
          }
          else if(sscanf(s, "%s (%s", ns, js)){}
          else
          */
            ns = s;
          t = colour_pad(" "+(x+1)+". "+ns,48);
          t += pad((string)PO->query_chosen_lvl(x), 9);
          t += (string)PO->query_chosen_exp(x)+"\n";
          TOU t+NORM);
        }
        else
          TOU " "+(x+1)+". error\n");
      }
    }
  }
  if(PO->query_a_c())
    TOU "\nAdditional commands: choose, unchoose\n");
  else
    TOU "\n");
  return 1;
}

