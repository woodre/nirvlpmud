#include "std.h"
#include "living.h"
object hammer;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
ONE_EXIT("players/mistress/sci_fi/shark.c","leave",
    "Hammerhead shark",
     "\n" +
    "The water is getting a little deeper here.  You feel something brush agaist\n" +
     "your leg and warily eye the fins still circling you.  Surprisingly,  not\n" +
     "one shark seems inclined to attack you.\n",1)
 
extra_init() {
     add_action("shark","north");
     add_action("shark","south");
     add_action("shark","east");
     add_action("shark","west");
     }
 
shark() {
     if(present("hammer")) {
        write("\nThe hammerhead shark won`t let you move.\n");
        return 1; }
     call_other(this_player(),"move_player"," to find sharks#players/mistress/sci_fi/shark/great_white.c");
     return 1; }
 
extra_reset()
{
if (!hammer || !living(hammer) )
{
 
hammer = clone_object("obj/monster");
call_other(hammer, "set_name", "hammerhead");
call_other(hammer, "set_ac", 12);
call_other(hammer, "set_wc", 20);
call_other(hammer, "set_hp", 380);
call_other(hammer, "set_al", -40);
call_other(hammer, "set_short", "A hammerhead shark");
call_other(hammer, "set_alias", "shark");
call_other(hammer, "set_long", "He looks at little menacing.\n");
call_other(hammer, "set_race", "hammerhead");
call_other(hammer, "set_alt_name", "hammerhead shark");
call_other(hammer, "set_aggressive", 0);
call_other(hammer, "add_money", 875);
call_other(hammer, "set_level", 15);
move_object(hammer, this_object() );
 
}
}
