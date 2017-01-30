#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
RangerPower(string num ,string channel)
{
/*  Allows a player to convert spell points to guild power */
  int amount;
  int amount3;
/* changed sscanf from %df to %d  3/99 Snow */
  if(!num) return 1;
  if(sscanf(num, "%d", amount) !=1)
  {
    tell_object(this_player(),
      "Zordon tells you: \"Use the syntax: generate <spell points>.\"\n");
    return 1;
  }
  if(amount < 5)
  {
    tell_object(this_player(),
      "Zordon tells you: \"You must convert at least 5 spell points at \
a time.\"\n");
    return 1;
  }
  if(this_player()->query_level() > 19)
  {
    tell_object(this_player(),
      "Zordon tells you: \"Wizards may not donate power!\"\n");
    return 1;
  }
  if(this_player()->SP < amount)
  {
    tell_object(this_player(),
      "Zordon tells you: \"You don't have that many spell points.\"\n");
    return 1;
  }
  if(MASTER->QPowerPoints(channel) > 17250)
  {
    tell_object(this_player(),
      "Zordon tells you: \"The power is full.\"\n");
    return 1;
  }
  amount3 = amount;
  amount = amount - 20;
  amount += random(20);
  if(amount + MASTER->QPowerPoints(channel) > 17249)
  {
    amount = 17250 - (int) MASTER->QPowerPoints(channel);
    amount3 = 17250 - (int) MASTER->QPowerPoints(channel);
  }
  if(amount < -5) amount = 0;
  if(amount < 0)
  {
    amount = 1;
  }
  if(MASTER->APowerPoints(amount, channel))
    this_player()->add_spell_point(-amount3);
  else
    return 1;
  tell_object(this_player(),
      "Zordon tells you: \"You generate " + amount +
      " Power Points for the guild.\"\n");
  return 1;
}

int
QMax() { return 1; }

status
RangerInfo(string str)
{
  write("Generate allows you to convert spell points (SP) for power.\n\
The rate of conversion is not 1:1.\n\n");
  return 1;
}
