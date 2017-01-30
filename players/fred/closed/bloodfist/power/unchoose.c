#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  string a, *chosen_weps;
  object *chosen, it;
  int x, good, val, chosen_max, chosen_current;
  chosen = allocate(4);
  val = 0;
  good = -1;
  if(User->query_ghost()) return 0;

  chosen_max = (int)PO->query_chosen_max();
  chosen_current = (int)PO->query_chosen_current();
  chosen_weps = (string *)PO->query_chosen_array();
  
  if(!chosen_max || !chosen_current)
    return (notify_fail("You have not chosen any weapons to master yet.\n"),0);

  if(!str)
    return (notify_fail("You must specify a weapon to unchoose.\n"),0);

  else if(str == "1")
    a = chosen_weps[0];
  else if(str == "2")
    a = chosen_weps[1];
  else if(str == "3")
    a = chosen_weps[2];
  else if(str == "4")
    a = chosen_weps[3];
  /* add more conditions here if allowed to master > 4 weps */
  else
  {
    for(x = 0; x < chosen_current; x++)  /* build array of objects */
    {
      a = "/"+chosen_weps[x]+".c";
      if(a != "/0.c" && loadObject(a))
        chosen[x] = clone_object(a);
    }
    for(x = 0; x < chosen_current; x++)  /* check for valid names */
    {
      if(chosen[x]->id(str))
      {
        val++;
        good = x;
      }
    }
    if(val > 1)
    {
      TOU 
        "You have multiple weapons with the id \""+str+"\"\n"+
        "Either be more specific or choose the number of the weapon.\n");
      return 1;
    }
    else if(val == 1)
      a = (string)PO->query_chosen(good);
    else if(val == 0)
    {
      TOU "None of your chosen weapons have an id of \""+str+"\"\n");
      return 1;
    }
  }
  if(!a)
  {
    TOU "What weapon do you want to remove?\n");
    return 1;
  }
  for(x = 0; x < chosen_max; x++)
  {
    if(a == (string)PO->query_chosen(x))  /* to be removed */
    {
      if(loadObject(a))
      {
        it = clone_object("/"+a+".c");
        TOU "You remove "+it->short()+" as a chosen weapon.\n");
        PO->rm_chosen(x);
      }
      else {
        TOU "You remove weapon "+x+" as a chosen weapon.\n");
        PO->rm_chosen(x);
      }
      return 1;
    }
  }

  return 1;
}

