#include "../defs.h"

status main(string str, object gob, object player)
{
  tell_object(player,
     SGC+"<<"+PGC+"*"+SGC+">> "+TGC+"Neo Symbiote link saved."+NORM+"\n");
  gob->save_gob();
  return 0;
}
