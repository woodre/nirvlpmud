#include "../defs.h"

int do_cmd(string str)
{
  object gob;
  int action;

  if( (int)TP->query_guild_rank() < 3)
    return 0;

  gob = present(GUILD_ID, TP);
  action = (int) gob->query_action();
  if(action == NOTHING)
  {
    write(HIC+"You start transferring energy from your lifecrystal to your body.\n"+NORM);
    gob->set_action(LIFEGAIN);
    return 1;
  }
  else if(action == LIFEGAIN)
  {
    write("You stop transferring energy from your lifecrystal to your body.\n");
    gob->set_action(NOTHING);
  }
  else
  {
    write("You are already performing another action.\n");
    return 1;
  }
}
