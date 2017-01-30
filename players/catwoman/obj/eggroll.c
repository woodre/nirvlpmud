#include "/players/vertebraker/ansi.h"


/* Vertebraker [5.30.01] fixed like, the entire freakin file :) */

inherit "/obj/treasure";
int roll_eaten;

status id(string arg) { return arg == "eggrolls" || arg == "eggroll" || arg == "bag" || arg == "bag of eggrolls"; }

reset(arg) { if(!arg) set_save_flag(1); }

long()
{
  write("A bag of "+ (11 - roll_eaten) +" eggrolls.\n");

}

short() { return "A bag of eggrolls [" + BOLD + (11-roll_eaten) + NORM + "]"; }

init()

{
  add_action("eat","eat");
}

eat(arg)
{
  if(!arg) { notify_fail("Eat what?\n"); return 0; }
  if(id(arg))
  {
    if (call_other(this_player(), "eat_food", 20))
    {
      say(call_other(this_player(),"query_name") + " eats an eggroll.\n");
      write("You eat an eggroll.\  ");
      if (roll_eaten == 10) { write("You ate the last one.\n"); }
      else { write("There are " + (10 - roll_eaten) + " eggrolls left.\n"); }
/* changed this from 30 to 17.. boltar's ruling f total heal may not exceed 175 - mythos <8-10-96>
      call_other(this_player(),"heal_self",30);
*/
        this_player()->heal_self(17);
      roll_eaten++;

      if (roll_eaten > 10) { 
        this_player()->add_weight(-1);
        destruct(this_object()); 
      }
      return 1;
    }
    return 1;
  } else { notify_fail("You may eat an eggroll if you wish.\n"); return 0; }
}


get() { return 1; }

query_weight() { return 1; }

/* fixed by Vertebraker from straight 1500 [5.30.01] */
query_value() { return (10 - roll_eaten) * 150; }


 
