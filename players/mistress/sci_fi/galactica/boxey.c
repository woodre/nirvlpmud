#include "std.h"
#include "living.h"
object boxey, muffit;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 

extra_init() {
      add_action("fight","kill");
      add_action("fight","fight");
      }

fight(a) {
    if(a=="muffit" || a=="daggit" && present("boxey")) {
      write("\nBoxey won't let you hurt his daggit.\n");
      return 1; }
     }

ONE_EXIT("players/mistress/sci_fi/galactica/serena.c","west",
    "Boxey and Muffit",
    "\nThis appears to be a child's room.  There are small clothes and a \n" +
    "few toys scattered about.\n",1)
 
extra_reset()
{
if (!boxey || !living(boxey) )
{
 
boxey = clone_object("obj/monster");
call_other(boxey, "set_name", "Boxey");
call_other(boxey, "set_ac", 5);
call_other(boxey, "set_wc", 10);
call_other(boxey, "set_level", 6);
call_other(boxey, "set_al", 132);
call_other(boxey, "set_short", "Boxey");
call_other(boxey, "set_alias", "boxey");
call_other(boxey, "set_long", "A young boy about six or seven years old.\n");
call_other(boxey, "set_race", "boy");
call_other(boxey, "set_aggressive", 0);
call_other(boxey, "add_money", 50);
call_other(boxey, "set_chat_chance", 50);
call_other(boxey, "load_chat", "Boxey yells, `Down Muffit! Down!'\n");
call_other(boxey, "load_chat", "`Darn you, daggit!'\n");
call_other(boxey, "set_a_chat_chance", 10);
call_other(boxey, "load_a_chat", "`Muffit! Where is my daggit?'\n");
move_object(boxey, this_object() );
}
if (!muffit || !living(muffit) )
{
 
muffit = clone_object("obj/monster");
call_other(muffit, "set_name", "Muffit");
call_other(muffit, "set_ac", 8);
call_other(muffit, "set_wc", 14);
call_other(muffit, "set_level", 10);
call_other(muffit, "set_al", 0);
call_other(muffit, "set_short", "Muffit");
call_other(muffit, "set_alias", "muffit");
call_other(muffit, "set_long", "Muffit is an android.\n");
call_other(muffit, "set_race", "daggit");
call_other(muffit, "set_alt_name", "dog");
call_other(muffit, "set_aggressive", 0);
move_object(muffit, this_object() );
}
}
