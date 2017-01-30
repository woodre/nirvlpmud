/* cost 300 coins 

Sobering Items:

-All sobering items will cost 20 for the first -1 or -2 strength.
 each following -1 will cost 20 more coins.

-Anything that sobers more than -15 will cost 10,000.

Portable healing:

-  Anything in a container must have included the value
   of the empty container when sold. 
-  Portable heals should have a container cost of 10 coins
   per charge or 30% of the healing points that is not recoverable.
-  All healing objects with charges must not save in
   hotels,lockers,houses,etc. Unless that item is coded such

 so the cost for sobering 15 would be
(1=20) + (13*20) + 10 = 290 */

#include "/players/softly/closed/ansi.h"
inherit "/obj/treasure";

reset(arg)
{
  if(arg) return;

  set_id("colewort");
  set_short("Colewort Flowers");
  set_alias("flowers");
  set_long("\A small paper contains a few fragrant white\n\
colewort flowers known to be sobering when eaten.\n");
  set_weight(1);
  set_value(200);

}

init() 
{ 
  ::init(); 
  {
    add_action("cmd_eat", "eat");
    add_action("cmd_eat", "chew");
    add_action("cmd_eat", "bite");
    add_action("cmd_eat", "nibble");
  }
}

status
cmd_eat(string str)
{
  if(!str) return 0;
  if(!(str == "flowers" || str == "colewort" || str == "colewort flowers"))
    {
      notify_fail("\
You don't seem to have that.\n");
      return 0;
    }
  this_player()->drink_alcohol(-15);
  say(this_player()->query_name() + " nibbles a few colewort flowers.\n");
  write("You inhale the fragrance as you slowly chew the flowers.\n\
Your head seems to clear and you feel better.\n\
The paper flutters away.\n\n");
  destruct(this_object()); 
  this_player()->recalc_carry(); 
  return 1;
}

query_save_flag() { 
  return 1; 
}
get() { return 1; }


