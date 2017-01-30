#include <ansi.h>
#include "../macros.h"
#include "../def.h"

object shadowee;

shadow_player(ob)
{
    shadow((shadowee = ob), 1);
}

unshadow_player()
{
   if(shadowee)
     shadow(shadowee, 0);
   destruct(this_object());
}

second_life()
{
    if(!shadowee) return;
    if(!servant(shadowee))
    {
      shadowee->second_life();
      return unshadow_player();
    }

    else
    {
      string msg;
      object att;

      if(objectp(att = shadowee->query_attack()))
        msg = shadowee->query_name() + " has been slain by " + att->query_name() + ".\n";
      else
        msg = shadowee->query_name() + " has died.\n";
      shadowee->second_life();
      CHANNELD->broadcast(msg, 1, "[Servants]");
    }
}
     
query_shardak_death_shadow() { return 1; }

/*
short()
{

    if((shadowee->query_real_name() == "vertebraker") && !shadowee->query_invis())
      return 
        "Verte "+HIC+"the Omnimpotent"+NORM+" (neutered)";
    else shadowee->short();
}

*/

query_real_name()
{
 object x;
/*
 if((x=caller()) && sscanf(file_name(x),"%splasma%syep%s">1))
  return "plasma";
 else
   causing problems -Bp */
  return shadowee->query_real_name();
}
