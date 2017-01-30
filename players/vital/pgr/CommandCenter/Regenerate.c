#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

object *targets;
string Align;

void
Regenerate()
{
  int i;
  object comm;
  if(!targets)
    return;
  for (i=0; i<sizeof(targets); i++)
  {
    if(targets[i])
    {
      if(present(targets[i], this_object()))
      {
        comm = present("RangerCommunicator",targets[i]);
        if( (string) comm->QRangerAlign() == Align)
        {
          if(comm->QPersonalPower() < comm->QMPersonalPower())
          {
            if(MASTER->QPowerPoints(Align) > 3)
            {
              MASTER->APowerPoints(-3,Align);
              comm->APersonalPower(3);
            }
            else
            {
              tell_object(targets[i],
                "There is not enough Common Power to regenerate.\n");
              targets -= ({ targets[i] }
              );
              i = i-1;
            }
          }
          else
          {
            tell_object(targets[i],
              "You stop regenerating your personal power.\n");
            targets -= ({targets[i]}
            );
            i = i-1;
          }
        }
        else
        {
          tell_object(targets[i], "You can't regenerate here!\n");
          targets -= ({targets[i]}
          );
          i = i-1;
        }
      }
      else
      {
        targets -= ({targets[i]}
        );
        i = i-1;
      }
    }
    else
    {
      targets -= ({ targets[i] }
      );
      i = i-1;
    }
  }
  if(sizeof(targets) == 0)
    set_heart_beat(0);
}

status
ATarget(object ob)
{
  if(!targets)
    targets = ({}
    );
  ob = this_player();
  if( (string) ob->query_guild_name() != GUILDNAME)
    return 0;
  if(member_array(ob, targets) != -1)
    return 0;
  else
  {
    targets += ({ ob }
    );
    write("You begin to regenerate your personal power.\n");
    set_heart_beat(1);
  }
  return 1;
}

status
RTarget(object ob)
{
  if(!targets)
    return 0;
  ob = this_player();
  if( (string) ob->query_guild_name() != GUILDNAME)
    return 0;
  if(member_array(ob, targets) != -1)
  {
    targets -= ({ ob }
    );
    write("You stop regenerating your personal power.\n");
    return 1;
  }
  else
    return 0;
}
