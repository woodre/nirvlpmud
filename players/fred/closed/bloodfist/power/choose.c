#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int chosen_current, chosen_max;
  object it;
  string a,b,c,s,ns,js;

  if(!str)
  {
    TOU "What weapon do you want to choose to train with?\n");
    return 1;
  }

  chosen_current = (int)PO->query_chosen_current();
  chosen_max = (int)PO->query_chosen_max();

  if(chosen_current >= chosen_max)
  {
    TOU "You are unable to choose any more weapons to train with.\n");
    return 1;
  }
  it = present(str, User);
  if(!it)
  {
    TOU "What weapon do you want to choose to train with?\n");
    return 1;
  }
  if(!it->is_weapon())
  {
    TOU it->short()+" is not a weapon.\n");
    return 1;
  }
  if(PO->query_if_chosen(it) >= 0)
  {
    TOU "You have already chosen to train with this weapon.\n");
    return 1;
  }

  a = file_name(it);
  if(!a)
  {
    TOU "You cannot train with this weapon.\n");
    return 1;
  }
  if(a->query_nonchoose())
  {
    TOU "You are not able to choose this weapon.\n");
    return 1;
  }
  sscanf(a,"%s#%s",b,c);

  if(b == "obj/weapon")
  {
    TOU it->short()+" is too generic to train with.\n");
	  return 1;
  }
  else if(!loadObject(b))
  {
    TOU "You cannot train with this weapon.\n");
    return 1;
  }

  s = (string)it->short();
  if(User->query_level() >= 40){
    if(sscanf(s, "%s  <%s", ns, js)){}
  }
  else if(sscanf(s, "%s (%s", ns, js)){}
  else
    ns = s;

  TOU "You choose "+ns+" as a weapon to train with.\n");
  PO->add_chosen(b);

  return 1;
}

