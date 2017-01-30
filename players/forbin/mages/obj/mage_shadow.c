#include "../def.h"

object mage, wepshadow;

set_mage_player_shadow(object obj) 
{
  mage = obj;
  shadow(mage, 1);
}

query_mage_player_shadow() { return 1; }

remove_mage_player_shadow()
{
  mage->unshadow();
  destruct(this_object());
  return 1;
}

/* Prevent wizard added exp from moving into guild exp */
/*
add_exp(amt)
{
  object gob;
  if(this_player())
  {
    if(this_player()->is_player())
    {
      if(this_player()->query_level() >= 21)
      {
        gob = present("forbin_mage_object", mage);
        if(!gob)
        {
          destruct(this_object());
          return;
        }
        gob->add_old_exp(amt);
        mage->add_exp(amt);
        return;
      }
    }
  }
  mage->add_exp(amt);
}
*/