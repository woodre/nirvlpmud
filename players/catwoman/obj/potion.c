#include "/obj/ansi.h"

/*
  09-15-01 Rewrote this entirely due to many bugs.
           -Feldegast
  15 hbs/ +7 wc
  10 hbs/ -4 wc
*/

int j;
int i;

short() { 
      if (i == 0) {
        return "A "+RED+"strength"+NORM+" potion";
      } else
      if (i == 1) {
        return 0;
      }
}

long() { 
     if (i == 0)
       write("It is a slightly phosphorescent liquid in a small glass phial.\n"+
             "There is a label on it.\n");
}

id(str) 
{
  if(!i)
     return str == "potion" || str=="strength potion" || str=="strength" || str=="phial";
  else
     return str == "generic_wc_bonus" || str == "active_strength_potion";
}

init() 
{
    add_action("drink","drink");
    add_action("read","read");
    add_action("drink","quaff");
}

read(str) 
{
    if (!str) 
    {
      return 0;
    }
    else if (str == "label" || str == "label on potion" || str=="potion")
    {
      write("The label reads: You must have a weapon to use this potion!\n");
      return 1;
    }
    else if (str)
    {
      return 0;
    }
}

drink(str) {
    object flask;
    object ob;

    if (i == 1)
    {
      return 0;
    }
    else if(str == "potion" || str == "strength potion" || str == "strength") 
    {
      if(present("active_strength_potion", this_player()))
      {
         write("You may not drink this at this time.\n");
         return 1;
      }

      ob = this_player()->query_weapon();
      if (!ob)
      {
         write("You must have a weapon to use this potion.\n");
         return 1;
      }

      write("You drink the strength potion.\n");
      say(call_other(this_player(), "query_name") + " drinks a strength potion.\n");

      write("You feel a surge of power race through you and your weapon.\n");

      flask = clone_object("obj/treasure");
      call_other(flask, "set_id", "flask");
      call_other(flask, "set_short", "An empty flask");
      call_other(flask, "set_weight", 1);
      call_other(flask, "set_value", 10);
      move_object(flask, this_player());

      i = 1;
      set_heart_beat(1);

      return 1;
    }
}

heart_beat() {
    if(!environment()) return;

    if (j++ > 15)
    {
      tell_object(environment(this_object()), "You feel weak.\n");
    }

    if (j > 25)
    {
      tell_object(environment(this_object()), "The strength potion wears off.\n");
      set_heart_beat(0);
      destruct(this_object());
    }
    
}

get() { return !i; }

drop() { return i; }

query_weight() { return !i; }

query_value() { return 700; }

gen_wc_bonus()
{
  if(j > 15)
    return -4;
  else
    return 7;
}
