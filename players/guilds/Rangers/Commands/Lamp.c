#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

string *Rangers;

status
RangerPower()
{
  string person;
  person = (string) this_player()->query_real_name() + 
    previous_object()->QRandomNumber();
  if(!Rangers) Rangers = ({});
  if(previous_object()->QNinja())
  {
    if(member_array(person, Rangers) != -1) Rangers -= ({ person });
    tell_object(this_player(),
      "Zordon tells you: \"You cannot use Lamp as a Ninja.\"\n");
    return 1;
  }
  if(!(previous_object()->QMorphed()))
  {
    if(member_array(person, Rangers) != -1) Rangers -= ({ person });
    tell_object(this_player(),
      "Zordon tells you: \"You need to be Morphed to use this.\"\n");
    return 1;
  }
  if(member_array(person, Rangers) < 0)
  {
    previous_object()->set_arm_light(2);
    tell_room(environment(this_player()),this_player()->query_name() +
            "'s Helmet begins to emit a bright beam of light.\n");
    Rangers += ({ person });
    return 1;
  }
  previous_object()->set_arm_light(-2);
  tell_room(environment(this_player()),this_player()->query_name() +
    "'s Helmet stops emitting light.\n");
  Rangers -= ({ person });
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("Your Lamp skill allows you to see better in dark places\n\
by projecting a strong beacon of light from your helmet\n");
  return 1;
}
