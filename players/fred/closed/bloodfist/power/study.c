#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  string *studied, c,d,e;
  object temp;
  int a,b, cost;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(5)) return 0;
  if(!str)
  {
    if(PO->query_study_num() == 0)
      return (notify_fail("You have not studied any monsters.\n"), 0);
    studied = (mixed)PO->query_studied();
    b = sizeof(studied);
    TOU "You have studied these monsters:\n");
    for(a = 0; a < b; a++)
    {
      if(studied[a] && (temp = clone_object(studied[a])))
      {
        if(!temp->short() && !temp->query_name())
          TOU " "+(a+1)+". Unknown.\n");          
        else if(!temp->short())
          TOU " "+(a+1)+". "+temp->query_name()+".\n");
        else  
          TOU " "+(a+1)+". "+temp->short()+".\n");
      }
    }
    TOU "\nYou can study up to 15 monsters.\n");
    return 1;
  }
  if((int)PO->query_study_num() == 15)
  {
    TOU "You can't seem to study any more monsters.\n");
    return 1;
  }
  if(!(temp = present(str, environment(User))))
    return (notify_fail("What do you want to study?\n"), 0);
  if(temp->is_player())
    return (notify_fail("You cannot study players.\n"), 0);
  if(!living(temp))
    return (notify_fail("You cannot study that.\n"), 0);
  if(temp->id("no_bfstudy"))
  {
    if(!temp->short())
      TOU"You are unable to study "+temp->query_short()+"'s movements.\n");
    else 
      TOU"You are unable to study "+temp->short()+"'s movements.\n");
    temp->study_response(User);
    return 1;
  }
  if(PO->query_study(temp) >= 0)
  {
    if(!temp->short()) 
      return (notify_fail("You have already studied "+temp->query_name()+".\n"), 0);    
    else 
      return (notify_fail("You have already studied "+temp->short()+".\n"), 0);
  }
  cost = 18 - (WIS / 20);
  if(User->query_sp() < cost)
    return (notify_fail("You are too weak to do this now.\n"), 0);
  if((WIS + FAI) < ((int)temp->query_level() * (4 - (WIS / 100)))
    && !(User->query_level() > 20 || PO->is_testchar()))
    return (notify_fail(
    "Your wisdom and faith are too low to study a monster.\n"), 0);
  if(random(WIS + FAI) > ((int)temp->query_level() * (4 - (WIS / 100)))
    || (User->query_level() > 20 || PO->is_testchar()))
  {
    if(!temp->short()) 
    {
      TOU "You watch "+temp->query_name()+" and understand its movements.\n");
      TRU Name+" watches "+temp->query_name()+" closely.\n", ({ User }));
    }
    else
    {
      TOU "You watch "+temp->short()+" and understand its movements.\n");
      TRU Name+" watches "+temp->short()+" closely.\n", ({ User }));
    }  
    c = file_name(temp);
    sscanf(c, "%s#%s", d,e);
    if(d == "obj/monster")
    {
      if(!temp->short())
        tell_object(User, temp->query_name()+" is too simple to understand.\n");      
      else 
        tell_object(User, temp->short()+" is too simple to understand.\n");
	    return 1;
    }
    PO->add_study(d);
    User->add_sp(-cost);
    return 1;
  }
  else {
    if(!temp->short())
    {
      TOU "You fail to understand "+temp->query_name()+"'s movements.\n");
      TRU Name+" watches "+temp->name()+" closely.\n", ({ User }));
    }  
    else 
    {
      TOU "You fail to understand "+temp->short()+"'s movements.\n");
      TRU Name+" watches "+temp->short()+" closely.\n", ({ User }));
    }
    User->add_sp(-cost);
    return 1;
  }
  return 0;
}
