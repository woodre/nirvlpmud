#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  string a, *studied;
  object *chosen, it;
  int x, good, val, chosen_max, chosen_current;
  chosen = allocate(15);
  val = 0;
  good = -1;
  if(User->query_ghost()) return 0;

  studied = (string *)PO->query_study_array();
  
  if(PO->query_study_num() == 0)
    return (notify_fail("You have not studied any monsters.\n"),0);

  if(!str)
    return (notify_fail("You must specify a monster to unstudy.\n"),0);

  else if(str == "1")
    a = studied[0];
  else if(str == "2")
    a = studied[1];
  else if(str == "3")
    a = studied[2];
  else if(str == "4")
    a = studied[3];
  else if(str == "5")
    a = studied[4];
  else if(str == "6")
    a = studied[5];
  else if(str == "7")
    a = studied[6];
  else if(str == "8")
    a = studied[7];
  else if(str == "9")
    a = studied[8];
  else if(str == "10")
    a = studied[9];
  else if(str == "11")
    a = studied[10];
  else if(str == "12")
    a = studied[11];
  else if(str == "13")
    a = studied[12];
  else if(str == "14")
    a = studied[13];
  else if(str == "15")
    a = studied[14];
  else
  { 
    write("Please choose 1-15.\n");
    return 1;
  }
  /*
  else
  {
    for(x = 0; x < MAX_STUDY; x++)  
    {
      a = "/"+studied[x]+".c";
      if(a != "/0.c" && loadObject(a))
        chosen[x] = clone_object(a);
    }
    for(x = 0; x < MAX_STUDY; x++)  
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
        "You have multiple monsters with the id \""+str+"\"\n"+
        "Either be more specific or choose the number of the monster.\n");
      return 1;
    }
    else if(val == 1)
      a = (string)PO->query_studied(good);
    else if(val == 0)
    {
      TOU "None of your chosen monsters have an id of \""+str+"\"\n");
      return 1;
    }
  }
  */
  if(!a)
  {
    TOU "What monster do you want to remove?\n");
    return 1;
  }
  for(x = 0; x < MAX_STUDY; x++)
  {
    if(a == (string)PO->query_study_name(x))  /* to be removed */
    {
      if(loadObject(a))
      {
        it = clone_object("/"+a+".c");
        TOU "You remove "+it->short()+" from your list of studied mobs.\n");
        PO->rm_studied(x);
      }
      else {
        TOU "You remove weapon "+x+" from your list of studied mobs.\n");
        PO->rm_studied(x-1);
      }
      return 1;
    }
  }
  return 1;
}

