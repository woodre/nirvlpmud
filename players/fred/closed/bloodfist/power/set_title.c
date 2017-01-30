#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  string *test, what, color, path, tog,s,ns,js;
  int a, sa, which, cur, max;
  object tmp;
  
  test = (mixed)TITLE_DAEMON->query_titles((int)PO->query_glevel());
  sa = sizeof(test);
  max = (int)PO->query_chosen_max();
  cur = (int)PO->query_chosen_current();

  if(!str)
  {
    TOU "Bloodfist titles for guild level "+(int)PO->query_glevel()+":\n");
    for(a = 0; a < sa; a++)
      TOU " "+(a+1)+". "+test[a]+"\n");
    TOU"\n");
    return 1;
  }

  if(sscanf(str, "%s %d %s", what, which, tog) == 3){} /* wep title 1    */
  else if(sscanf(str, "%s %d", what, which) == 2){}    /* wep title 2    */
  else if(sscanf(str, "%d %s", which, what) == 2){}    /* lvl title      */
  else if(sscanf(str, "%s", what) == 1){}              /* wep title list */
  else
    return (notify_fail("no\n"), 0);

  if(what == "wep" || what == "weapon")
  {
    if(!cur || !max)
      return (notify_fail("You have not chosen any weapons.\n"), 0);
    if(!which) /* list maxed chosen weps */
    {
      TOU "Maxed Bloodfist Weapons:\n");
      for(a = 0; a < max; a++)
      {
        if((int)PO->query_chosen_lvl(a) == 10) /* max lvl */
        {
          path = "/"+PO->query_chosen(a)+".c";
          if(loadObject(path)) /* just in case */
          {
            tmp = clone_object(path);
            s = (string)tmp->short();
            if(sscanf(s, "%s\n%s", ns, js))
              s = ns;
            what = colour_pad(" "+(a+1)+". "+s,48);
            what += pad((string)PO->query_chosen_lvl(a), 9);
            what += (string)PO->query_chosen_exp(a)+"\n";
            TOU what);
          }
          else
            TOU "error\n");
        }
      }
      return 1;
    }
    else { /* which */
      which--;
      if(which < 0 || which >= max)
        return (notify_fail("What do you want to set your title to?\n"), 0);
      if(which >= cur)
        return (notify_fail("You have not chosen that weapon yet.\n"), 0);
      if(PO->query_chosen_lvl(which) < 10)
        return (notify_fail(
        "You are not experienced enough with that weapon.\n"), 0);
      path = "/"+PO->query_chosen(which)+".c";
      if(!loadObject(path))
        return (notify_fail("error\n"), 0);
      if(User->query_level() > 19)
        return (notify_fail("Wizards can not do this.\n"), 0);
      tmp = clone_object(path);
      if(tog)
      {
        User->set_title("\b, Master of "+tmp->short());
        TOU "You set your title to: , Master of "+tmp->short()+".\n");
      }
      else {
        User->set_title("\b, the Master of "+tmp->short());
        TOU "You set your title to: , the Master of "+tmp->short()+".\n");
      }
      return 1;
    }
  }
  else {
    which--;
    if(which >= sa || which < 0)
      return (notify_fail("What do you want to set your title to?\n"), 0);
    color = NORM;
    if(what == "RED" || what == "red") color = RED;
    else if(what == "HIR" || what == "hir") color = HIR;
    else if(what == "blk" || what == "BLK") color = BOLD+BLK;
    else if(what == "yel" || what == "YEL") color = YEL;
    User->set_title("\b,"+color+" the "+test[which]+NORM);
    TOU "You set your title to: , "+color+"the "+test[which]+NORM+".\n");
    return 1;
  }
  return 0;
}

