#include "../defs.h"

status main(string str, object gob, object player)
{
  if(!str)
  {
    player->print_monitor();

    tell_object(player,
      PGC+"MP "+SGC+"["+HIW+colour_pad((string)gob->show_mp()+"",20)+SGC+"]   "+NORM);
    if((int)gob->query_hypermode())
      tell_object(player,
        PGC+"Hypermode "+SGC+"["+HIW+"ON"+SGC+"]   "+NORM);
    if((int)gob->query_burnoff())
      tell_object(player,
        PGC+"Burnoff "+SGC+"["+HIW+"ON"+SGC+"]   "+NORM);
    if((int)gob->query_regen())
      tell_object(player,
        PGC+"Regen "+SGC+"["+HIW+"ON"+SGC+"]   "+NORM);
    tell_object(player,
      "\n");
    return 1;
  }
  return 1;
}
