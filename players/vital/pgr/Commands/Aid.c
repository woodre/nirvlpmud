#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

status
RangerPower(string str, string type)
{
  int cost;
  object attack;
  cost = 20;
  if(!str)
  {
    tell_object(this_player(), "Zordon tells you: \"You must specify a " +
                type + " to aid.\"\n");
    return 1;
  }
  if(str == (string) this_player()->query_real_name())
  {
    tell_object(this_player(),
                "Zordon tells you: \"You cannot aid yourself.\"\n");
    return 1;
  }
  if(str == "command center")
  {
  }
  else if(!find_living(str))
  {
    tell_object(this_player(), "Zordon tells you: \"" +
                capitalize(str)+" cannot not be located\".\n");
    return 1;
  }
    else
  if(type == "Power Ranger"
     && (string) find_living(str)->query_guild_name() != "rangers")
  {
    tell_object(this_player(), "Zordon tells you: \"" + capitalize(str) +
                " is not a Power Ranger.\"\n");
    return 1;
  }
    else
  if(type == "Dark Ranger" 
     && (string) find_living(str)->query_guild_name() != "dark rangers")
  {
    tell_object(this_player(), "Lord Zed tells you: \"" + capitalize(str) +
                " is not a Dark Ranger.\"\n");
    return 1;
  }
  if(!find_living(str)->query_attack())
  {
    tell_object(this_player(), "Zordon tells you: \"" + capitalize(str) + 
                " is not in battle.\"\n");
    return 1;
  }
  if(!present(str, environment(this_player())))
  {
    command("teleport "+str,this_player());
  }
  if(cost > MASTER->QPowerPoints(type))
  {
    tell_object(this_player(),
                "Zordon tells you: \"There is not enough Power.\"\n");
    return 1;
  }
  if(!present(str, environment(this_player()))) return 0;
  attack = (object) present(str, environment(this_player()))->query_attack();
  if(!this_player()->valid_attack(attack))
  {
    tell_object(this_player(),
                "Zordon tells you: \"You cannot attack that person.\"\n");
    return 0;
  }
  this_player()->attack_object(attack);
  MASTER->APowerPoints(-cost,type);
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("\
  Aid is a team skill to allow you to quickly fight with other rangers.\n\
When you use aid you will automatically fight the monster your team member\n\
is fighting, and if necessary you will teleport to them.\n\
         Commands:\n\n\
         aid <team member> - Helps another Power Ranger in battle\n\n");
  return 1;
}
