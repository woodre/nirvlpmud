#include "../def.h"

status main(string str, object gob, object player)
{
  tell_object(player,
     PGC+"["+SGC+"*"+PGC+"]"+TGC+" Mage Guild Object Saved.\n"+NORM);
  gob->guild_quit();
  return 0;
}
