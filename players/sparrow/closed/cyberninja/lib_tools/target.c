/* 10/19/05 Earwax: Raised chance of target.  It was ridiculous */

#include "../DEFS.h"
#include DEFS_ENHANCEMENTS

/* TARGETTING SYSTEM */


status main(string str)
{
  object meat;
  int mywil, myint, myglev, mylinks;

  if (!((status)IPTP->item_weplink()) && !IPTP->guild_wiz()) return 0;

  if (str)
  {
    meat = present(str, environment(TP));
    if (!meat)
    {
      write("[ "+str+" ] is not here.\n");
      return 1;
    }
    if (!living(meat))
    {
      write("You cannot target [ "+str+" ]\n");
      return 1;
    }
  }

  if (!str)
  {
    if (!TP->query_attack())
    {
      write("Target what?\n");
      return 1;
    }
    else
    {
      meat = (object)TP->query_attack();
      str = (string)meat->query_name();
    }
  }

  mywil = (int)TP->query_attrib("wil");
  myint = (int)TP->query_attrib("int");
  myglev = (int)IPTP->guild_lev();
  mylinks = (int)IPTP->item_weplink();

  if ((object)IPTP->query_target() == meat)
  {
    write("You have already targetted [ "+str+" ]\n");
    return 1;
  }

/* Old chances - Earwax
  if (mywil   < random(25) ||
      myint   < random(25) ||
      myglev  < random(6)  ||
      mylinks < random(4))
If they are less than gmax and 6 links, check stats */

  if (mylinks < random(6) || myglev < random(11)
    && (mywil < random(25) || myint < random(25)))
  {
    tell_object(TP, BOLD+"Targetting Failure.\n"+OFF);
    return 1;
  }

  /* Spell point cost removed because weplink damage
     never required targetting in the first place.
     I did raise the failure rate just for fun though. - Dune
   */

  tell_object(TP, BOLD+"Targetting [ "+str+" ]\n"+OFF);
  IPTP->set_target(meat);
  return 1;
}
