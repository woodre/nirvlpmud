#include "../defs.h"

status main(string str, object gob, object player)
{
  if((int)player->query_ghost()) 
    return 0;
  
  if((int)gob->query_skill("control") < 6) 
    return 0;

  if((int)gob->query_regen())
  {
    tell_object(player,
      "You will yourself to stop the regeneration process.\n");
    gob->set_regen(1);
    return 1; 
  }
  if((int)player->query_sp() < 20)
  {
    tell_object(player,
      "You lack the energy to do that.\n");
    return 1;
  }
  if((int)gob->query_mp() < 15)
  {
    tell_object(player,
      "You lack the dark "+PGC+"Dark Matter"+NORM+" to do that.\n");
    return 1;
  }
  if((int)player->query_hp() < 22)
  {
    tell_object(player,
      "Your body is too weak to begin the regeneration process.\n");
    return 1;
  }

  tell_object(player,
    "You concentrate and force your inner symbiote to heal you.\n"+NORM);

  gob->set_regen(1);
  player->add_spell_point(-20);
  player->add_hit_point(-20);
  gob->sub_mp(15);
  return 1;
}
