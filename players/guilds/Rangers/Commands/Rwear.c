#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
QRangerInfo(){ return 1; }

status
RangerInfo()
{
  write("\
Rwear allows you to wear certain pieces of standard armor in addition\n\
to your normal Power Ranger suit. Requires significant Power Points per\n\
use. Allowed types:\n\n\
Misc, Amulet, Scarf, Orb, Ring, Cloak, Bracelet\n\n\
Prestige: Belt\n\n");
  return 1;
}


status
RangerPower(string str,string type)
{
  object armor;
  string *allowed;
  allowed = ({"scarf"});
  if(previous_object()->QuerySkillLevel("armor") >= 6)
  {
    allowed += ({"underwear"});
  }
  if(previous_object()->QuerySkillLevel("armor") >= 8)
  {
    allowed += ({"orb"});
  }
  if(previous_object()->QuerySkillLevel("armor") >= 10)
  {
    allowed += ({"misc"});
  }
  if(previous_object()->QuerySkillLevel("armor") >= 15)
  {
    allowed += ({"amulet", "cloak"});
  }
  if(previous_object()->QuerySkillLevel("armor") >= 20)
  {
    allowed += ({"ring", "bracelet"});
    if(this_player()->query_prestige_level())
    {
      allowed += ({"belt"});
    }
  }
  if(!str)
  {
    tell_object(this_player(),
      "Zordon tells you: \"What do you want to wear?\"\n");
    return 1;
  }
  if(!present(str,this_player()))
  {
    tell_object(this_player(), "Zordon tells you: \"You don't have " + str +
      " in your possesion.\"\n");
    return 1;
  }
  if(!previous_object()->QMorphed())
  {
    tell_object(this_player(),
      "Zordon tells you: \"You must be morphed to use Rwear.\"\n");
    return 1;
  }
  if(MASTER->QPowerPoints(type) < 
    ( (int) previous_object()->QuerySkillLevel("armor") * 100) )
  {
    tell_object(this_player(),
      "Zordon tells you: \"There is not enough power to also wear armor.\"\n");
    return 1;
  }
  armor = present(str,this_player());
  if(member_array(armor->query_type(), allowed) < 0)
  {
    tell_object(this_player(),
      "Zordon tells you: \"You cannot wear that type of armor.\n");
    return 1;
  }

  previous_object()->NotArmor(0);
  armor->wear(str);
  if(armor->query_worn())
  {
    MASTER->APowerPoints(-( (int) previous_object()->QuerySkillLevel("armor") * 
      (70 + random(30) ) ), type);
    if(armor->short())
      tell_room(environment(this_player()), "The " + armor->short() +
        " melds in with " + this_player()->query_name() + "'s Power Suit.\n");
  }
  previous_object()->NotArmor(1);
  this_player()->set_ac(0);
  return 1;
}
