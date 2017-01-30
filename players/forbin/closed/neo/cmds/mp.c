#include "../defs.h"

status main(string str, object gob, object player)
{
 
  if((int)player->query_ghost()) 
    return 0;
  
  tell_object(player,
    PGC+"MP "+SGC+"["+HIW+colour_pad((string)gob->show_mp()+"",20)+SGC+"]\n"+NORM);
  return 1;
}
