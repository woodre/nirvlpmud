#include <ansi.h>

int cmd_offer(object mob, string arg)
{
  mapping int_to_str;

    int_to_str =([ 1 : "one", 2 : "two", 3: "three", 4: "four", 5: "five", 
                   6 :  "six", 7 : "seven", 8: "eight", 9: "nine", 10: "ten",
                   11 : "eleven", 12: "twelve", 13 : "thirteen", 14 : "fourteen",
                   15 : "fifteen", 16: "sixteen", 17: "seventeen", 18: "eighteen",
                   19: "nineteen", 20: "twenty", 21: "twenty-one", 22 : "twenty-two",
                   23: "twenty-three", 24: "twenty-four", 25: "twenty-five" ]);

  mob->spell_block();
  if((int)mob->query_spell_block())
    return (write("You are unable to do that.\n"), 1);
  if(!arg)
    return (write("\
You may only offer fresh corpses to the gods of Nirvana.\n"), 1);
   else
   {
     object corpse, me, gold;
     int    corpse_value, time_val;
     string x;

     if(!(corpse = present(arg, (me = mob))) &&
        !(corpse = present(arg, environment(me))))
       return (write("You don't see " + arg + " here.\n"), 1);
     if(!corpse->is_corpse())
       return (write(capitalize(arg) + " is not a real corpse.\n"), 1);

     write("You bend down on one knee and offer " + 
            (string)corpse->short() + " to the gods.\n");
     tell_room(environment(mob), (string)mob->query_name() +
          " bends down on one knee and offers " +
            (string)corpse->short() + " to the gods.\n");

     if((int)corpse->query_decay() < 20)
       return (write("The body is too badly decomposed.\n" +
                     "The gods of Nirvana will not accept it.\n"), 1);



     tell_room(environment(me),
       "With a flash of "+HIW+"lightning"+NORM+", " +
                (string)corpse->short() + " explodes into a " +
                    "cloud of ash.\n");

     corpse_value = ((int)corpse->query_corpse_level());
     if(!corpse_value)
       corpse_value = 1;
     else if(corpse_value > 25)
       corpse_value = 20 + random(5);

     x = capitalize(int_to_str[corpse_value]);
     if(corpse_value == 1)
       tell_room(environment(me),
         "One "+HIY+"golden coin"+NORM+" falls from the heavens!\n");
     else
       tell_room(environment(me),
      x+" "+HIY+"golden coins"+NORM+" fall from the heavens!\n");

     gold=clone_object("/obj/money");
     gold->set_money(corpse_value);
     move_object(gold, environment(me));

     destruct(corpse);

     return 1;
  }
}
