#include "std.h"
#include "living.h"
object baby;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
ONE_EXIT("players/mistress/sci_fi/shark.c","leave",
    "Baby shark",
    "\n" +
    "Luckily the water is shallow enough to wade through.  There does not seem\n" +
    "to be any danger of you being pulled under (at least not here).  The fins\n" +
    "surrounding are relatively small too. <whew!>.\n",1)
 
extra_init() {
     add_action("shark","north");
     add_action("shark","south");
     add_action("shark","east");
     add_action("shark","west");
     }
 
shark() {
     if(present("baby")) {
        write("\nThe baby shark won`t let you move.\n");
        return 1; }
     call_other(this_player(),"move_player"," to find sharks#players/mistress/sci_fi/shark/hammerhead.c");
     return 1; }
 
extra_reset()
{
if (!baby || !living(baby) )
{
 
baby = clone_object("obj/monster");
call_other(baby, "set_name", "baby");
call_other(baby, "set_ac", 6);
call_other(baby, "set_wc", 11);
call_other(baby, "set_al", -20);
call_other(baby, "set_short", "A baby shark");
call_other(baby, "set_alias", "shark");
call_other(baby, "set_long", "He would be cute if he weren`t so irritating with those teeth.\n");
call_other(baby, "set_race", "baby");
call_other(baby, "set_alt_name", "baby shark");
call_other(baby, "set_aggressive", 0);
call_other(baby, "add_money", 52);
call_other(baby, "set_level", 7);
move_object(baby, this_object() );
 
}
}
