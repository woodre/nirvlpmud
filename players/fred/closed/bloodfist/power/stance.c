#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cur;
  string *sn;
  sn = (string *)PO->query_stance_names();
  if(!str)
  {
    TOU "You must specify a stance to switch to.\n\n"+
      colour_pad(" 1. "+sn[5], 15)+"Complete dedication to offense\n"+
      colour_pad(" 2. "+sn[4], 15)+"Highly aggressive and reckless\n"+
      colour_pad(" 3. "+sn[3], 15)+"Aggressive and moderately reckless\n"+
      colour_pad(" 4. "+sn[2], 15)+"Moderately on the offensive\n"+
      colour_pad(" 5. "+sn[1], 15)+"Balance between offense and defense\n"+
      "\n"+
      "Current stance: "+capitalize((string)PO->query_stance(2))+"\n\n");
    return 1;
  }
  cur = (int)PO->query_stance();
  if(PO->query_stance_change())
    TOU "You can not change your stance again that quickly.\n");
  else if(str == "1" || str == "insane" || str == "i")
  {
    if(cur == 5)
      TOU "Your combat stance is already insane.\n");
    else
    {
      TOU "You choose "+sn[5]+" as your combat stance.\n");
      TRU User->query_name()+" lowers into a more offensive stance.\n",
        ({ User }));
      PO->set_stance(5);
    }
  }
  else if(str == "2" || str == "murderous" || str == "m")
  {
    if(cur == 4)
      TOU "Your combat stance is already murderous.\n");
    else
    {
      TOU "You choose "+sn[4]+" as your combat stance.\n");
      if(cur == 1 || cur == 2 || cur == 3)
        TRU User->query_name()+" lowers into a more offensive stance.\n",
        ({ User }));
      else if(cur == 5)
        TRU User->query_name()+" adjusts into a more defensive stance.\n",
        ({ User }));
      PO->set_stance(4);
    }
  }
  else if(str == "3" || str == "violent" || str == "v")
  {
    if(cur == 3)
      TOU "Your combat stance is already violent.\n");
    else
    {
      if(cur == 1 || cur == 2)
        TRU User->query_name()+" lowers into a more offensive stance.\n",
        ({ User }));
      else if(cur == 4 || cur == 5)
        TRU User->query_name()+" adjusts into a more defensive stance.\n",
        ({ User }));
      TOU "You choose "+sn[3]+" as your combat stance.\n");
      PO->set_stance(3);
    }
  }
  else if(str == "4" || str == "aggressive" || str == "agro" || str == "a")
  {
    if(cur == 2)
      TOU "Your combat stance is already aggressive.\n");
    else
    {
      if(cur == 1)
        TRU User->query_name()+" lowers into a more offensive stance.\n",
        ({ User }));
      else if(cur == 3 || cur == 4 || cur == 5)
        TRU User->query_name()+" adjusts into a more defensive stance.\n",
        ({ User }));
      TOU "You choose "+sn[2]+" as your combat stance.\n");
      PO->set_stance(2);
    }
  }
  else if(str == "5" || str == "neutral" || str == "n")
  {
    if(cur == 1)
      TOU "Your combat stance is already neutral.\n");
    else
    {
      TOU "You choose "+sn[1]+" as your combat stance.\n");
      TRU User->query_name()+" adjusts into a more defensive stance.\n",
        ({ User }));
      PO->set_stance(1);
    }
  }
  else
    TOU "You can not select \""+str+"\" as a combat stance.\n");
  return 1;
}

