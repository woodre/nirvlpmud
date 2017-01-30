#include "std.h"
#include "living.h"
object great;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
ONE_EXIT("players/mistress/sci_fi/shark.c","leave",
    "Great White shark",
     "\n" +
    "You are treading water now.  The darkness seems to swallow you up as you\n" +
    "peer about in confusion.  Trying to keep an eye on the circling fins is \n" +
    "beginning to be tiresome,  but you feel that it is necessary.  Occassionally\n" +
    "you catch glimpses of VERY large dorsal fins cutting the surface.\n",0)
 
extra_init() {
     add_action("shark","north");
     add_action("shark","south");
     add_action("shark","east");
     add_action("shark","west");
     }
 
shark() {
     if(present("great")) {
        write("\nThe great white shark won`t let you move.\n");
        return 1; }
     call_other(this_player(),"move_player"," to find sharks#players/mistress/sci_fi/shark/jaws.c");
     return 1; }
 
extra_reset()
{
if (!great || !living(great) )
{
 
great = clone_object("obj/monster");
call_other(great, "set_name", "great white");
call_other(great, "set_ac", 10);
call_other(great, "set_wc", 17);
call_other(great, "set_al", -70);
call_other(great, "set_short", "A great white shark");
call_other(great, "set_alias", "shark");
call_other(great, "set_long", "This guy makes you very nervous.\n");
call_other(great, "set_race", "great");
call_other(great, "set_alt_name", "great white shark");
call_other(great, "set_aggressive", 0);
call_other(great, "add_money", 90);
call_other(great, "set_level", 13);
move_object(great, this_object() );
 
}
}
