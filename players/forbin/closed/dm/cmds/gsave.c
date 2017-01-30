#include "../defs.h"

status main(string str, object gob, object player)
{
  tell_object(player,
    CYN+"**"+NORM+" Saving guild object.\n");
  gob->save_gob();
  return 1;
}
