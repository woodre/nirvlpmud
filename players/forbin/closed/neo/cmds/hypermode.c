#include "../defs.h"

status main(string str, object gob, object player)
{
  if((int)player->query_ghost()) 
    return 0;
  
  if((int)gob->query_skill("combat") < 8) 
    return 0;

  if((int)player->query_sp() < 100)
  {
    tell_object(player,
      "You lack the energy for Hypermode.\n");
    return 1;
  }
  if((int)gob->query_mp() < 10)
  {
    tell_object(player,
      "You lack the dark "+PGC+"Dark Matter"+NORM+" to do that.\n");
    return 1;
  }
  if((int)gob->query_hypermode())
  {
    tell_object(player,
      "Hypermode is already active.\n");
    return 1;
  }

  tell_object(player,
    "Your body tightens as "+HIW+"Dark Matter"+NORM+" courses through your veins and into your muscles...\n"+
    PGC+"Your motions become a blur.\n"+NORM);
  tell_room(environment(player),
    (string)player->QN+"'s body darkens as something black courses through "+
    (string)player->POS+" veins.\n"+
    PGC+(string)player->QN+"'s motions blur!\n"+NORM, ({ player }) );

  if((int)player->query_pl_k())
    gob->set_hypermode(30 + ((int)gob->query_skill("combat") * 6) + (int)player->query_attrib("wil"));
  else     
    gob->set_hypermode(30 + ((int)gob->query_skill("combat") * 2) + (int)player->query_attrib("wil"));
  player->add_spell_point(-100);
  gob->sub_mp(10);
  return 1;
}
