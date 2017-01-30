#include "all.h"

int
cmd_chuckle(string arg)
{
    if(ghost())
      return 0;

    if(!arg)
    {
      write("You chuckle politely.\n");
      say(tpn + " chuckles politely.\n");
      return 1;
    }

    else
    {
      object ob;

      if(!(ob = arg_check(arg)))
        return 0;

      else if(environment(ob) == environment(tp))
      {
        write("You chuckle at " + on + ".\n");
        say(tpn + " chuckles at " + on + ".\n", ob);
        tell_object(ob, tpn + " chuckles at you.\n");
      }

      else
      {
        write("You chuckle at " + on + " from afar.\n");
        tell_object(ob, tpn + " chuckles at you from afar.\n");
      }
        
    }
  
    return 1;
}
