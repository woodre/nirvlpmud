#include "../defs.h"

int do_cmd(string str)
{
  object gob;
  object *syn;
  object targ;

  gob = present(GUILD_ID, TP);

  if(!str)
  {
    notify_fail("Unsynch who? all?\n");
    return 0;
  }

  if(!gob)
  {
    notify_fail("Error!  No guild object!\n");
    return 0;
  }

  syn = (object *)gob->query_synch();

  if(!syn || sizeof(syn) == 0)
  {
    write("Nobody is synched.\n");
    return 1;
  }

  if(str)
  {
    targ = present(str, environment(TP));
    if(!targ)
    {
      notify_fail("That person is not present.\n");
      return 0;
    }

    if(member_array(targ, syn) != -1)
      gob->remove_synch(targ);

    targ = present("crystal_mage_synch_object", targ);
    if(targ)
    {
      tell_object(environment(targ), "Your synch crystal vanishes!\n");
      destruct(targ);
    }

    write(CYN + "You unsynch "+capitalize(str)+".\n" + NORM);
    return 1;
  }
  else if(str == "all")
  {
    int i, j;
    for(i = 0, j = sizeof(syn); i < j; i++)
    {
       gob->remove_synch(syn[i]);
       targ = present("crystal_mage_synch_object", targ);
       if(targ)
       {
         tell_object(environment(targ), "Your synch crystal vanishes!\n");
         destruct(targ);
       }
    }
    write("You dispel the synchronization.\n");
    return 1;
  }
}
