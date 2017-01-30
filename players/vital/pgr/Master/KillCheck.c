#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

mapping RangerKills;

void
kill_check(object ob, object ranger, int team)
{
  int i;
  int exp;
  mixed kills;
  if(!RangerKills) RangerKills = ([ ]);
  if(!RangerKills[ob]) RangerKills[ob] = ({ ranger, team });
  else
     RangerKills[ob] += ({ ranger, team });
  kills = RangerKills[ob];
  if(kills) i = sizeof(kills);
    else
  i = 0;
  if( (i/2) > 1 )
  {
    exp = (int) ob->calculate_worth();
    exp = exp/500;
    if(exp > 0)
    {
      for (i=0; i<sizeof(kills); i++)
      {
        if(ranger != kills[i])
        {
          ranger->ABuildPoints((exp*team));
          if(environment(ranger)) tell_object(environment(ranger),
            "You receive "+(exp*team)+
            " build points for your team participation.\n");
          kills[i]->ABuildPoints((exp*kills[i+1]));
          if(environment(kills[i])) tell_object(environment(kills[i]),
            "You receive "+(exp*kills[i+1])+
            " build points for your team participation.\n"); 
        }
        i = i+1;
      }
    }
  }
  return;
}
