#include "../defs.h"

int do_cmd(string str)
{
  object gob;
  int action;

  if( (int)TP->query_level() < 13)
    return 0;

  if( (int)TP->query_guild_rank() < 4)
    return 0;

  gob = present(GUILD_ID, TP);
  action = (int) gob->query_action();

  if(action == NOTHING)
  {
    write(HIC+"You start transferring energy from your body to your lifecrystal.\n"+NORM);
    gob->set_action(MANAGAIN);
    return 1;
  }
  else if(action == MANAGAIN)
  {
    write("You stop transferring energy.\n");
    gob->set_action(NOTHING);
    return 1;
  }
  else
  {
    write("You are already performing another action.\n");
    return 1;
  }
}
