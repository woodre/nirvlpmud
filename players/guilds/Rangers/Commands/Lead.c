#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
RangerPower(string str, string type)
{
  object attack;
  /* write() changed to notify_fail() here */
  /* verte 6.6.01 bleh! */
  /* 11/28/05 Earwax: Made it so rangers could use mud follow cmd */
  attack = (object)this_player()->query_attack();
  if (!attack)
  {
    if (!str)
    {
      tell_object(this_player(),
        "Zordon tells you: \"You are not attacking anyone.\"\n");
      notify_fail("You are not attacking anyone.\n");
      return 0;
    }
    else
    {
      if ((int)call_other(this_player(), "cmd_lead", str) < 1)
        tell_object(this_player(), "Zordon tells you: \"You are not attacking anyone.\"\n");
      return 1;
    }
  }
  if(MASTER->QPowerPoints(type) < 20)
  {
    tell_object(this_player(),
      "Zordon tells you: \"There is not enough power in the guild to \
aid you.\n");
    return 1;
  }
  this_player()->attack_object(attack);
  attack->attack_object(this_player());
  tell_room(environment(this_player()),this_player()->query_name()+
          " finds the courage to fight "+attack->query_name()+" harder.\n");
  MASTER->APowerPoints(-20,type);
  return 1;
}

status
QRangerInfo(){ return 1; }

status
RangerInfo()
{
  write("\
  As a Power Ranger it is your responsibility to protect the \n\
Innocent and what is right, it is also your duty to defend the \n\
Team. Taking the lead in battle is a chance to stand for the \n\
Truth and Conviction of all Power Rangers and help preserve that\n\
which is Good and protect the lives of those who seek the path of\n\
Light and Right.\n\n\
  Lead allows you take the lead in battle and protects other people\n\
from taking enemy hits.\nLead consumes 20 Power Points.\n\n");
  return 1;
}
