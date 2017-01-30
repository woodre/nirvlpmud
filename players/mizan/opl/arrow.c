/* This is the actual entrance to the Proving Grounds of the OverPowerLord
 *
 *
 */
#include "/obj/ansi.h"

reset(arg)
{
     if(arg) return;
     move_object(this_object(), "/room/wild1.c");
}

id(str) { return str == "arrow"; }

is_castle() { return 1; }

short() 
{
    return "A " + HIW + HBRED + "HUGE neon arrow" + NORM + " pointing south";
}

long() 
{
    write("You see a HUGE neon arrow pointing south.\n"+
    "It reads: Proceed south to the Proving Grounds of the OverPowerLord!\n"+
    "This is an area for EXPERIENCED players only!\n");
}

init()
{
    add_action("long_entry","south");
}

long_entry() 
{
    if(this_player()->query_level() < 19) 
    {
        write("So sorry... but you need to be level 19 to enter this realm.\n");
        return 1;
    }

    this_player()->move_player("south#players/mizan/opl/ROOMS/entrance.c");
    return 1;
}


