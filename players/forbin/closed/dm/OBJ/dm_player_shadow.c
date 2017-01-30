#include "../defs.h"

object dm;

set_dm_player_shadow(object obj) 
{
  dm = obj;
  shadow(dm, 1);
}

query_dm_player_shadow() { return 1; }

remove_dm_player_shadow()
{
  dm->unshadow();
  destruct(this_object());
  return 1;
}

/* Prevent wizard added exp from moving into guild exp */
/* temporarily removed 
add_exp(amt)
{
  object gob;
  if(this_player())
  {
    if(this_player()->is_player())
    {
      if(this_player()->query_level() >= 21)
      {
        gob = present("forbin_dm_object", dm);
        if(!gob)
        {
          destruct(this_object());
          return;
        }
        gob->add_old_exp(amt);
        dm->add_exp(amt);
        return;
      }
    }
  }
  dm->add_exp(amt);
}
*/