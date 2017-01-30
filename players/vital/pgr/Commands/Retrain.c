#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

status
QRangerInfo(){ return 1; }

status
RangerInfo(string str)
{
  if(str){ return 1; }
  write("\
  Retrain allows you to remove a skill point from one of your \n\
current skills so you may use it somewhere else. Retrain cost \n\
80000 coins per skill point.\n");
  return 1;
}

status
RangerPower(string str)
{
  if(!str)
  {
    tell_object(this_player(),
      "Zordon tells you: \"What skill do you want to Re-Train?\"\n");
    return 1;
  }
  if(this_player()->query_money() < 80000)
  {
    tell_object(this_player(),
      "Zordon tells you: \"You don't have enough gold coins!\"\n");
    return 1;
  }
  if(previous_object()->ReTrainRanger(str))
  {
    this_player()->add_money(-80000);
    tell_object(this_player(),
      "Zordon tells you: \"Re-Training Succeeded. You may now use your \
Skill Point how you wish.\n");
    return 1;
  }
  else
  {
    tell_object(this_player(),
      "Zordon tells you: \"Re-Training Failed for some reason.\"\n");
    return 1;
  }
  return 0;

}
