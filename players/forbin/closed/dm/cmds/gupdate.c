#include "../defs.h"

status main(string str, object gob, object player)
{
  tell_object(player,
    CYN+"**"+NORM+" Updating guild object.\n");
  gob->update_gob();
  return 1;
}
